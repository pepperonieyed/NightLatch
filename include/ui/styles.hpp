#ifndef NIGHTLATCH_INC_STYLES
#define NIGHTLATCH_INC_STYLES

#include <lvgl.h>

void styles_init(void);
void init_title_text();
void init_footer_text();

extern lv_style_t style_title_text;
extern lv_style_t style_footer_text;

#endif
