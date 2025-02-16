
void DisplaySleep(lv_event_t * e)
{
digitalWrite(2, LOW);
}

void DisplayWakeup(lv_event_t * e)
{
	digitalWrite(2, HIGH);
}