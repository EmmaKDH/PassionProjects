
void UpdateClockDisplays(){
  UpdateClockHands();
  UpdateDigitalDisplay();
}

void UpdateClockHands(){
  //Second
  lv_img_set_angle(ui_ClockSecondHandImage, second() * 60 % 3600);
  //Minute
  lv_img_set_angle(ui_ClockMinuteHandImage, minute() * 60);
  //Hour
  lv_img_set_angle(ui_ClockHourHandImage, hour() * 300 + minute() / 12 * 60);
}

void UpdateDigitalDisplay(){
//Hours
  if(hour() >= 10 && hour() < 20){
  lv_label_set_text(ui_DigitalDisplayHoursLeftDigit, String(1).c_str());  //Convert count val to string on label
  lv_label_set_text(ui_DigitalDisplayHoursRightDigit, String(hour()-10).c_str());  //Convert count val to string on label

  } else if(hour() >= 20){
  lv_label_set_text(ui_DigitalDisplayHoursLeftDigit, String(2).c_str());  //Convert count val to string on label
  lv_label_set_text(ui_DigitalDisplayHoursRightDigit, String(hour()-20).c_str());  //Convert count val to string on label

  } else {
  lv_label_set_text(ui_DigitalDisplayHoursLeftDigit, String(0).c_str());  //Convert count val to string on label
  lv_label_set_text(ui_DigitalDisplayHoursRightDigit, String(hour()).c_str());  //Convert count val to string on label
  }

//Minutes
  if(minute() >= 10 && minute() < 20){
  lv_label_set_text(ui_DigitalDisplayMinuteLeftDigit, String(1).c_str());  //Convert count val to string on label
  lv_label_set_text(ui_DigitalDisplayMinuteRightDigit, String(minute()-10).c_str());  //Convert count val to string on label

  } else if(minute() >= 20 && minute() < 30){
  lv_label_set_text(ui_DigitalDisplayMinuteLeftDigit, String(2).c_str());  //Convert count val to string on label
  lv_label_set_text(ui_DigitalDisplayMinuteRightDigit, String(minute()-20).c_str());  //Convert count val to string on label

  } else if(minute() >= 30 && minute() < 40){
  lv_label_set_text(ui_DigitalDisplayMinuteLeftDigit, String(3).c_str());  //Convert count val to string on label
  lv_label_set_text(ui_DigitalDisplayMinuteRightDigit, String(minute()-30).c_str());  //Convert count val to string on label

  } else if(minute() >= 40 && minute() < 50){
  lv_label_set_text(ui_DigitalDisplayMinuteLeftDigit, String(4).c_str());  //Convert count val to string on label
  lv_label_set_text(ui_DigitalDisplayMinuteRightDigit, String(minute()-40).c_str());  //Convert count val to string on label
  } else if(minute() >= 50){
  lv_label_set_text(ui_DigitalDisplayMinuteLeftDigit, String(5).c_str());  //Convert count val to string on label
  lv_label_set_text(ui_DigitalDisplayMinuteRightDigit, String(minute()-50).c_str());  //Convert count val to string on label  
  } else {
  lv_label_set_text(ui_DigitalDisplayMinuteLeftDigit, String(0).c_str());  //Convert count val to string on label
  lv_label_set_text(ui_DigitalDisplayMinuteRightDigit, String(minute()).c_str());  //Convert count val to string on label
  }
}

void ResetSecond(lv_event_t * e)
{
  S = 0;
  setTime(H,M,S,0,0,25);
}

void TimeSetHourUp(lv_event_t *e) {
  if (H == 23) {
    H = 0;
   } else {
    H++;
  }
  if(H >= 10 && H < 20){
  HDial = H - 10;
  lv_label_set_text(ui_DigitalDisplayHoursLeftDigit, String(1).c_str());  //Convert count val to string on label
  } else if ( H >= 20){
  HDial = H - 20;
  lv_label_set_text(ui_DigitalDisplayHoursLeftDigit, String(2).c_str());  //Convert count val to string on label
  } else {
  HDial = H;
  lv_label_set_text(ui_DigitalDisplayHoursLeftDigit, String(0).c_str());  //Convert count val to string on label
  }
  lv_label_set_text(ui_SetTimeScreenHourLabel, String(H).c_str());  //Convert count val to string on label

  lv_label_set_text(ui_DigitalDisplayHoursRightDigit, String(HDial).c_str());  //Convert count val to string on label
  

  setTime(H,M,S,0,0,25);
     HDial = H;
}

void TimeSetHourDown(lv_event_t *e) {
  if (H == 0) {
    H = 23;
  } else {
    H--;
  }

  if(H >= 10 && H < 20){
  HDial = H - 10;
  lv_label_set_text(ui_DigitalDisplayHoursLeftDigit, String(1).c_str());  //Convert count val to string on label
  } else if ( H >= 20){
  HDial = H - 20;
  lv_label_set_text(ui_DigitalDisplayHoursLeftDigit, String(2).c_str());  //Convert count val to string on label
  } else {
  HDial = H;
  lv_label_set_text(ui_DigitalDisplayHoursLeftDigit, String(0).c_str());  //Convert count val to string on label
  }
  lv_label_set_text(ui_SetTimeScreenHourLabel, String(H).c_str());  //Convert count val to string on label

  lv_label_set_text(ui_DigitalDisplayHoursRightDigit, String(HDial).c_str());  //Convert count val to string on label
  

  setTime(H,M,S,0,0,25);
  HDial = H;
}

void TimeSetMinuteUp(lv_event_t *e) {
  if (M == 59) {
    M = 0;
  } else {
    M++;
  }
  if(M >= 10 && M < 20){
  MDial = M - 10;
  lv_label_set_text(ui_DigitalDisplayMinuteLeftDigit, String(1).c_str());  //Convert count val to string on label
  } else if(M >= 20 && M < 30){
  MDial = M - 20;
  lv_label_set_text(ui_DigitalDisplayMinuteLeftDigit, String(2).c_str());  //Convert count val to string on label
  } else if(M >= 30 && M < 40){
  MDial = M - 30;
  lv_label_set_text(ui_DigitalDisplayMinuteLeftDigit, String(3).c_str());  //Convert count val to string on label
  } else if(M >= 40 && M < 50){
  MDial = M - 40;
  lv_label_set_text(ui_DigitalDisplayMinuteLeftDigit, String(4).c_str());  //Convert count val to string on label
  } else if(M >= 50){
  MDial = M - 50;
  lv_label_set_text(ui_DigitalDisplayMinuteLeftDigit, String(5).c_str());  //Convert count val to string on label
  } else {
  MDial = M;
  lv_label_set_text(ui_DigitalDisplayMinuteLeftDigit, String(0).c_str());  //Convert count val to string on label
  }

  lv_label_set_text(ui_SetTimeScreenMinuteLabel, String(M).c_str());  //Convert count val to string on label
  
  lv_label_set_text(ui_DigitalDisplayMinuteRightDigit, String(MDial).c_str());  //Convert count val to string on label
  
  setTime(H,M,S,0,0,25);
  MDial = M;
}

void TimeSetMinuteDown(lv_event_t *e) {
  if (M == 0) {
    M = 59;
  } else {
    M--;
  }

  if(M >= 10 && M < 20){
  MDial = M - 10;
  lv_label_set_text(ui_DigitalDisplayMinuteLeftDigit, String(1).c_str());  //Convert count val to string on label
  } else if(M >= 20 && M < 30){
  MDial = M - 20;
  lv_label_set_text(ui_DigitalDisplayMinuteLeftDigit, String(2).c_str());  //Convert count val to string on label
  } else if(M >= 30 && M < 40){
  MDial = M - 30;
  lv_label_set_text(ui_DigitalDisplayMinuteLeftDigit, String(3).c_str());  //Convert count val to string on label
  } else if(M >= 40 && M < 50){
  MDial = M - 40;
  lv_label_set_text(ui_DigitalDisplayMinuteLeftDigit, String(4).c_str());  //Convert count val to string on label
  } else if(M >= 50){
  MDial = M - 50;
  lv_label_set_text(ui_DigitalDisplayMinuteLeftDigit, String(5).c_str());  //Convert count val to string on label
  } else {
  MDial = M;
  lv_label_set_text(ui_DigitalDisplayHoursLeftDigit, String(0).c_str());  //Convert count val to string on label
  }

  lv_label_set_text(ui_SetTimeScreenMinuteLabel, String(M).c_str());  //Convert count val to string on label

  lv_label_set_text(ui_DigitalDisplayMinuteRightDigit, String(MDial).c_str());  //Convert count val to string on label
  
  setTime(H,M,S,0,0,25);
  MDial = M;
}
