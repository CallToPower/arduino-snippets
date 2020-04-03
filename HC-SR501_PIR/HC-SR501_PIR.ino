/**
 * Description:
 * HC-SR501 infrared body induction module
 * 
 * Copyright 2019 Denis Meyer
 */

#define SENSOR_INPUT_PIN 8
#define LED_PIN 12
#define BUILTIN_LED_PIN 13
#define INITIAL_DELAY_MS 20000
#define DELAY_MS 500

#include <stdio.h>
#include <stdlib.h>

int pirState = LOW;
int val = LOW;

void setup() {
  pinMode(SENSOR_INPUT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
 
  Serial.begin(9600);

  Serial.println("Warming up (this may take a while)...");
  delay(INITIAL_DELAY_MS);
  Serial.println("Starting now");
  Serial.println(LOW);
  Serial.println(HIGH);
}

void loop() {
  val = digitalRead(SENSOR_INPUT_PIN);

  if (val == HIGH) {
    if (pirState == LOW) {
      Serial.println("Motion detected");
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(BUILTIN_LED_PIN, HIGH);
      pirState = HIGH;
    }
  } else {
    if (pirState == HIGH) {
      Serial.println("Motion ended");
      digitalWrite(LED_PIN, LOW);
      digitalWrite(BUILTIN_LED_PIN, LOW);
      pirState = LOW;
    }
  }

  delay(DELAY_MS);

}
