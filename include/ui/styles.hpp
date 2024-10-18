#ifndef NIGHTLATCH_INC_STYLES
#define NIGHTLATCH_INC_STYLES

#include <lvgl.h>

void styles_init(void);
void style_init_title_text(void);
void style_init_footer_text(void);
void style_init_menubar(void);

extern lv_style_t style_title_text;
extern lv_style_t style_body_text;
extern lv_style_t style_footer_text;
extern lv_style_t style_menubar;

#endif
