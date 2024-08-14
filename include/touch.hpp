#ifndef NIGHTLATCH_INC_TOUCH
#define NIGHTLATCH_INC_TOUCH

#include <lvgl.h>
#include <TAMC_GT911.h>

#define TOUCH_SDA 19
#define TOUCH_SCL 20
#define TOUCH_INT -1
#define TOUCH_RST -1

extern TAMC_GT911 *touch_screen;
extern lv_indev_t *indev;

void read_touchscreen(lv_indev_t*, lv_indev_data_t*);

#endif
