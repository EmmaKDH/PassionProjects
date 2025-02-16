//Arduino-TFT_eSPI board-template main routine. There's a TFT_eSPI create+flush driver already in LVGL-9.1 but we create our own here for more control (like e.g. 16-bit color swap).

#include <lvgl.h>
#include <TFT_eSPI.h>
#include <ui.h>

#include <TimeLib.h>  //For clock management
int H = 12;
int M = 0;
int S = 0;
#include <CST816S.h>  //NECCESARRY ADDITION

int HDial = 12;
int MDial = 0;
int SDial = 0;


/*Don't forget to set Sketchbook location in File/Preferences to the path of your UI project (the parent foder of this INO file)*/

/*Change to your screen resolution*/
static const uint16_t screenWidth = 240;
static const uint16_t screenHeight = 240;

enum { SCREENBUFFER_SIZE_PIXELS = screenWidth * screenHeight / 10 };
static lv_color_t buf[SCREENBUFFER_SIZE_PIXELS];

TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */
CST816S myTouch(6, 7, 13, 5);                       //NECCESSARY ADDITION

#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(const char *buf) {
  Serial.printf(buf);
  Serial.flush();
}
#endif

/* Display flushing */
void my_disp_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *pixelmap) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  if (LV_COLOR_16_SWAP) {
    size_t len = lv_area_get_size(area);
    lv_draw_sw_rgb565_swap(pixelmap, len);
  }

  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);
  tft.pushColors((uint16_t *)pixelmap, w * h, true);
  tft.endWrite();

  lv_disp_flush_ready(disp);
}

/*Read the touchpad*/  //NECCESARRY ADDITION - WHOLE FUNCTION
void my_touchpad_read(lv_indev_t *indev_driver, lv_indev_data_t *data) {
  uint16_t touchX = 0, touchY = 0;

  if (myTouch.available()) {
    touchX = myTouch.data.x;
    touchY = myTouch.data.y;

    std::swap(touchX, touchY);      //Necessary for touch calibration
    touchX = tft.width() - touchX;  //Necessary for touch calibration

    data->state = LV_INDEV_STATE_PR;
  } else {
    data->state = LV_INDEV_STATE_REL;
  }

  /*Set the coordinates*/
  data->point.x = touchX;  
  data->point.y = touchY;

  //I added these conditions just to keep my serial monitor from going crazy
  if (touchX != 0) {
    Serial.print("Data x ");
    Serial.println(touchX);
  }

  if (touchY != 0) {
    Serial.print("Data y ");
    Serial.println(touchY);
  }
}

/*Set tick routine needed for LVGL internal timings*/
static uint32_t my_tick_get_cb(void) {
  return millis();
}


void setup() {
  Serial.begin(115200); /* prepare for possible serial debug */
  setTime(H,M,S,0,0,25); //For TimeKeeping

  String LVGL_Arduino = "Hello Arduino! ";
  LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

  Serial.println(LVGL_Arduino);
  Serial.println("I am LVGL_Arduino");

  lv_init();

#if LV_USE_LOG != 0
  lv_log_register_print_cb(my_print); /* register print function for debugging */
#endif

  tft.begin();        /* TFT init */
  tft.setRotation(3); /* Landscape orientation, flipped */

  myTouch.begin();  //NECCESARRY ADDITION

  static lv_disp_t *disp;
  disp = lv_display_create(screenWidth, screenHeight);
  lv_display_set_buffers(disp, buf, NULL, SCREENBUFFER_SIZE_PIXELS * sizeof(lv_color_t), LV_DISPLAY_RENDER_MODE_PARTIAL);
  lv_display_set_flush_cb(disp, my_disp_flush);

  static lv_indev_t *indev;
  indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, my_touchpad_read);

  lv_tick_set_cb(my_tick_get_cb);

  ui_init();
  
//  Added for DisplaySleepCheck function

  pinMode(2, OUTPUT);

  Serial.println("Setup done");
}

void loop() {
  lv_timer_handler(); /* let the GUI do its work */

  UpdateClockDisplays();
  delay(5);
}
