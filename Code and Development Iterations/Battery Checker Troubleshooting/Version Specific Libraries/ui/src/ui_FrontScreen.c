// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 9.1.0
// Project name: BatteryChecker

#include "ui.h"

void ui_FrontScreen_screen_init(void)
{
    ui_FrontScreen = lv_obj_create(NULL);
    lv_obj_remove_flag(ui_FrontScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_FrontScreen, lv_color_hex(0x494F49), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FrontScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PercentValue = lv_label_create(ui_FrontScreen);
    lv_obj_set_width(ui_PercentValue, 50);
    lv_obj_set_height(ui_PercentValue, 25);
    lv_obj_set_x(ui_PercentValue, -15);
    lv_obj_set_y(ui_PercentValue, 60);
    lv_obj_set_align(ui_PercentValue, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PercentValue, "100");
    lv_obj_set_style_text_color(ui_PercentValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_PercentValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_PercentValue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_PercentValue, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PercentSign = lv_label_create(ui_FrontScreen);
    lv_obj_set_width(ui_PercentSign, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PercentSign, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_PercentSign, 25);
    lv_obj_set_y(ui_PercentSign, 60);
    lv_obj_set_align(ui_PercentSign, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PercentSign, "%");
    lv_obj_set_style_text_color(ui_PercentSign, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_PercentSign, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_PercentSign, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BatteryIndicator = lv_obj_create(ui_FrontScreen);
    lv_obj_set_width(ui_BatteryIndicator, 128);
    lv_obj_set_height(ui_BatteryIndicator, 128);
    lv_obj_set_x(ui_BatteryIndicator, -5);
    lv_obj_set_y(ui_BatteryIndicator, 105);
    lv_obj_set_align(ui_BatteryIndicator, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_BatteryIndicator, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_BatteryIndicator, lv_color_hex(0x4A4C4A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BatteryIndicator, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_BatteryIndicator, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_transform_rotation(ui_BatteryIndicator, 2700, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui_BatteryIndicator, &ui_img_fullbattery_png, LV_PART_MAIN | LV_STATE_USER_1);
    lv_obj_set_style_bg_image_src(ui_BatteryIndicator, &ui_img_halfbattery_png, LV_PART_MAIN | LV_STATE_USER_2);
    lv_obj_set_style_bg_image_src(ui_BatteryIndicator, &ui_img_emptybattery_png, LV_PART_MAIN | LV_STATE_USER_3);

    lv_obj_add_event_cb(ui_FrontScreen, ui_event_FrontScreen, LV_EVENT_ALL, NULL);

}
