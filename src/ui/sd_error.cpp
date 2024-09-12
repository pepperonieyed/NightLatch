#include <lvgl.h>

#include "settings.hpp"
#include "ui/sd_error.hpp"
#include "ui/styles.hpp"

void show_sd_error() {
    lv_obj_t *base = lv_obj_create(lv_screen_active());
    lv_obj_set_align(base, LV_ALIGN_CENTER);
    lv_obj_set_size(base, 400, 350);

    lv_obj_t *no_sd_label = lv_label_create(base);
    lv_obj_set_width(no_sd_label, 300);
    lv_label_set_text(no_sd_label, "Unable to Read SD Card");
    lv_label_set_long_mode(no_sd_label, LV_LABEL_LONG_WRAP);
    lv_obj_add_style(no_sd_label, &style_title_text, LV_STATE_DEFAULT);
    lv_obj_align(no_sd_label, LV_ALIGN_TOP_MID, 0, 44);

    lv_obj_t *no_sd_explanation_label = lv_label_create(base);
    lv_obj_set_width(no_sd_explanation_label, 300);
    lv_label_set_text(
        no_sd_explanation_label,
        "It was not possible to detect the SD card. Either no SD card is inserted or the inserted card is corrupt.\n\nInsert a working SD card to continue."
    );
    lv_label_set_long_mode(no_sd_explanation_label, LV_LABEL_LONG_WRAP);
    lv_obj_add_style(no_sd_explanation_label, &style_body_text, LV_STATE_DEFAULT);
    lv_obj_align(no_sd_explanation_label, LV_ALIGN_TOP_MID, 0, 175);

    lv_obj_t *footer_label = lv_label_create(lv_screen_active());
    lv_label_set_text(footer_label, "NightLatch v" NIGHTLATCH_VERSION);
    lv_obj_align(footer_label, LV_ALIGN_BOTTOM_MID, 0, -14);
    lv_obj_add_style(footer_label, &style_footer_text, LV_STATE_DEFAULT);
}
