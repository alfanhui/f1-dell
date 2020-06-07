/* F1 DELL Arduino USB Keyboard HID 

  Sends F1 keypress via USB to bypass Dell's inability to care less about their fans. (ALERT FAN FAILURE) 

*/

#include <avr/interrupt.h>
#include <avr/power.h>
#include <avr/sleep.h>

#define F1 58

uint8_t buf[8] = { 0 };

void setup();
void loop();

void setup()
{
  Serial.begin(9600);
  delay(200);
}

void loop()
{
  //wait for Dell to get to ALERTING ERR
  delay(15000);

  buf[2] = F1;
  Serial.write(buf, 8); // Send keypress
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key
  
  Serial.end();
  
  // Brush teeth
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  // Tell a bedtime story
  sleep_enable();
  // Turn the lights out
  sleep_mode();
}



