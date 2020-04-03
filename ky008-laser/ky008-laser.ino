/**
 * Description:
 * KY008 laser module
 * 
 * Copyright 2019 Denis Meyer
 */

#define PIN_OUT_LASER 10

void setup() {
  pinMode (PIN_OUT_LASER, OUTPUT);
}

void loop() {
  digitalWrite (PIN_OUT_LASER, HIGH);
  delay (100000000);
}
