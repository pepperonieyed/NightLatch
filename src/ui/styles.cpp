#include "ui/styles.hpp"

lv_style_t style_title_text;
lv_style_t style_footer_text;

void styles_init() {
    init_title_text();
    init_footer_text();
}

void init_title_text() {
    lv_style_init(&style_title_text);
    lv_style_set_text_align(&style_title_text, LV_TEXT_ALIGN_CENTER);
    lv_style_set_text_font(&style_title_text, &lv_font_montserrat_40);
}

void init_footer_text() {
    lv_style_init(&style_footer_text);
    lv_style_set_text_align(&style_footer_text, LV_TEXT_ALIGN_CENTER);
    lv_style_set_text_font(&style_footer_text, &lv_font_montserrat_14);
    lv_style_set_text_color(&style_footer_text, lv_color_hex(0xCCCCCC));
}
