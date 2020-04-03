/**
 * Description:
 * Blink LED when the ultrasound sensor registers an object <= DISTANCE_BLINK_CM away
 * 
 * Copyright 2019 Denis Meyer
 */

#define PIN_TRIGGER 8
#define PIN_ECHO 9
#define PIN_LED_BUILTIN 13
#define DELAY_MS 1000
#define DISTANCE_BLINK_CM 10

void setup() {
  pinMode(PIN_TRIGGER, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(PIN_LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(PIN_TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGGER, LOW);

  long duration = pulseIn(PIN_ECHO, HIGH);
  long distance_cm = get_distance_cm(duration);

  if (distance_cm <= DISTANCE_BLINK_CM) {
    digitalWrite(PIN_LED_BUILTIN, HIGH);
  } else {
    digitalWrite(PIN_LED_BUILTIN, LOW);
  }

  Serial.print("Distance = ");
  Serial.print(distance_cm);
  Serial.print(" cm\n");

  delay(DELAY_MS);
}

long get_distance_cm(long duration) {
  return duration * 0.0340 / 2; /* Distance = (Time x Sound speed in Air (340 m/s))/2 */
}
