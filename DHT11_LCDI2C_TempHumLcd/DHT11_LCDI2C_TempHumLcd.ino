/**
 * Description:
 * DHT11 temperature and humidity module
 * LCD1602 with I2C module
 * 
 * Copyright 2019 Denis Meyer
 */

#include <dht.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define PIN_DHT11 2
#define DELAY_MS 2000

dht DHT;

LiquidCrystal_I2C  lcd(0x27, 2, 1, 0, 4, 5, 6, 7); // 0x27 is the I2C bus address for an unmodified backpack

void setup() {
  Serial.begin(9600);

  lcd.begin (16, 2); // for 16x2 LCD module
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH);
}

void loop() {
  int chk = DHT.read11(PIN_DHT11);

  lcd.clear();

  Serial.print("Temperature: ");
  Serial.print(DHT.temperature);
  Serial.print("°C");
  lcd.setCursor (0, 0);
  lcd.print("Temp: "); 
  lcd.print(DHT.temperature); 
  lcd.print(" C"); 

  Serial.print(", Humidity: ");
  Serial.print(DHT.humidity);
  Serial.print("%");
  Serial.print("\n");
  lcd.setCursor (0, 1);
  lcd.print("Humid: "); 
  lcd.print(DHT.humidity); 
  lcd.print("%"); 

  delay(DELAY_MS);
}
