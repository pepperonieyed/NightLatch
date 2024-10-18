#ifndef NIGHTLATCH_INC_TOUCH
#define NIGHTLATCH_INC_TOUCH

#include <lvgl.h>
#include <TAMC_GT911.h>

constexpr uint8_t TOUCH_SDA = 19;
constexpr uint8_t TOUCH_SCL = 20;
constexpr int8_t TOUCH_INT = -1;
constexpr int8_t TOUCH_RST = -1;

extern TAMC_GT911 *touch_screen;
extern lv_indev_t *indev;

void read_touchscreen(lv_indev_t*, lv_indev_data_t*);

#endif
