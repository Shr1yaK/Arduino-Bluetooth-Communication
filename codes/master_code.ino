#include <SoftwareSerial.h>

#define TRIG_PIN 9
#define ECHO_PIN 8

SoftwareSerial Bluetooth(7, 6);

void setup() {
  Bluetooth.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration / 2) / 29.1;  // Calculate distance in cm

  Bluetooth.println(distance < 15);
  delay(500);
}
