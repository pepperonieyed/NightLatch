#include <Arduino.h>
#include <Arduino_GFX_Library.h>
#include <Arduino_GFX.h>
#include <lvgl.h>

#include "nightlatch.hpp"
#include "touch.hpp"
#include "sd_card.hpp"
#include "ui/styles.hpp"
#include "ui/homepage.hpp"
#include "ui/sd_error.hpp"

/*
 * flush_display
 * -------------------
 * Updates the relevant area of the display (partial rendering) for this
 * flush
 * 
 * color_map: Bitmap of colors to write to the area of the display
 */
void flush_display(lv_display_t *display, const lv_area_t *area, uint8_t *color_map) {
  uint16_t width = lv_area_get_width(area);
  uint16_t height = lv_area_get_height(area);

  gfx->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)color_map, width, height);

  lv_disp_flush_ready(display);
}

/*
 * tick
 * -------------------
 * Provides a reference to time for LVGL
*/
uint32_t tick(void) {
  return millis();
}

void setup(void) {
  // Setup display driver (Arduino_GFX)
  bus = new Arduino_ESP32RGBPanel(
    41, 40, 39, 42, 14, 21, 47, 48, 45, 9, 46, 3, 8, 16, 1, 15, 7, 6, 5, 4,
    0, 210, 30, 16, 0, 22, 13, 10, 1, 16000000
  );
  gfx = new Arduino_RGB_Display(DISP_WIDTH, DISP_HEIGHT, bus, 1);

  // Initialise display driver
  gfx->begin();
  gfx->fillScreen(BLACK);

  pinMode(DISP_BL_PIN, OUTPUT);
  analogWrite(DISP_BL_PIN, 255);

  // Setup lvgl
  lv_init();
  lv_tick_set_cb(tick);

  display = lv_display_create(gfx->width(), gfx->height());
  lv_display_set_flush_cb(display, flush_display);
  lv_display_set_buffers(display, draw_buffer, NULL, sizeof(draw_buffer), LV_DISPLAY_RENDER_MODE_PARTIAL);

  // Setup touchscreen
  // Width and height are inverted due to portrait mode
  touch_screen = new TAMC_GT911(
    TOUCH_SDA, TOUCH_SCL, TOUCH_INT, TOUCH_RST,
    DISP_HEIGHT, DISP_WIDTH
  );

  touch_screen->begin();
  touch_screen->setRotation(ROTATION_RIGHT);

  lv_indev_t *indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, read_touchscreen);

  // Init styles
  styles_init();

  // Check if SD card inserted
  sdcard_init() ? show_homepage() : show_sd_error();
}

void loop(void) {
  int delta = lv_timer_handler();
  delay(delta);
}
