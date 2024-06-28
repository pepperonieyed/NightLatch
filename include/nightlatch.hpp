#ifndef include_nightlatch
#define include_nightlatch

#include <lvgl.h>

#define NIGHTLATCH_VERSION "0.0.2"

#define DISP_BL_PIN 2
#define DISP_WIDTH 800
#define DISP_HEIGHT 480

static lv_display_t *display;

// LVGL draw buffer (1/10 of screen size due to partial rendering)
#define DRAW_BUFFER_SIZE (DISP_WIDTH * DISP_HEIGHT / 10)
uint32_t draw_buffer[DRAW_BUFFER_SIZE];


void flush_display(lv_display_t, const lv_area_t*, uint8_t*);
static uint32_t tick(void);

void setup(void);
void loop(void);

#endif
