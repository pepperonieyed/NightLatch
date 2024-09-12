#include "ui/styles.hpp"
#include "fonts/poppins_40_700.c"
#include "fonts/suse_16_400.c"
#include "fonts/suse_18_400.c"

lv_style_t style_title_text;
lv_style_t style_body_text;
lv_style_t style_footer_text;

void init_title_text() {
    lv_style_init(&style_title_text);
    lv_style_set_text_align(&style_title_text, LV_TEXT_ALIGN_CENTER);
    lv_style_set_text_font(&style_title_text, &poppins_40_700);
}

void init_body_text() {
    lv_style_init(&style_body_text);
    lv_style_set_text_align(&style_body_text, LV_TEXT_ALIGN_CENTER);
    lv_style_set_text_font(&style_body_text, &suse_18_400);
}

void init_footer_text() {
    lv_style_init(&style_footer_text);
    lv_style_set_text_align(&style_footer_text, LV_TEXT_ALIGN_CENTER);
    lv_style_set_text_font(&style_footer_text, &suse_16_400);
    lv_style_set_text_color(&style_footer_text, lv_color_hex(0x8F8F8F));
}

void styles_init() {
    init_title_text();
    init_body_text();
    init_footer_text();
}
