/**
 * Description:
 * LED blinking
 * 
 * Copyright 2019 Denis Meyer
 */

#define PIN_LED 6
#define DELAY_MS 500

void setup() {
  
}

void loop() {
  digitalWrite(PIN_LED, HIGH);
  delay(DELAY_MS);
  digitalWrite(PIN_LED, LOW);
  delay(DELAY_MS);
}
