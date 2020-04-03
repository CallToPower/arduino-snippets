/**
 * Description:
 * DHT11 temperature and humidity module
 * 
 * Copyright 2019 Denis Meyer
 */

#include <dht.h>

/**
 * https://www.arduinolibraries.info/libraries/dht-sensor-library
 */

#define PIN_DHT11 2
#define DELAY_MS 5000

dht DHT;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int chk = DHT.read11(PIN_DHT11);
  Serial.print("Temperature: ");
  Serial.print(DHT.temperature);
  Serial.print("°C");
  Serial.print(", Humidity: ");
  Serial.print(DHT.humidity);
  Serial.print("%");
  Serial.print("\n");
  delay(DELAY_MS);
}
