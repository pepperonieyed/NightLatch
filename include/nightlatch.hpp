#ifndef NIGHTLATCH_INC_NIGHTLATCH
#define NIGHTLATCH_INC_NIGHTLATCH

#include <lvgl.h>
#include <TAMC_GT911.h>
#include <Arduino_GFX_Library.h>
#include <Arduino_GFX.h>

#define DISP_BL_PIN 2
#define DISP_WIDTH 800
#define DISP_HEIGHT 480

Arduino_ESP32RGBPanel *bus;
Arduino_RGB_Display *gfx;

lv_display_t *display;

// LVGL draw buffer (1/10 of screen size due to partial rendering)
#define DRAW_BUFFER_SIZE (DISP_WIDTH * DISP_HEIGHT / 10)
uint32_t draw_buffer[DRAW_BUFFER_SIZE];

void flush_display(lv_display_t, const lv_area_t*, uint8_t*);
uint32_t tick(void);

TAMC_GT911 *touch_screen;

void setup(void);
void loop(void);

#endif
