#include <SoftwareSerial.h>

#define BUZZ_PIN 10
#define SAFE_PIN 7
#define DANGER_PIN 12

SoftwareSerial Bluetooth(4, 3);

void setup() {
  Serial.begin(9600);
  Bluetooth.begin(9600);

  pinMode(BUZZ_PIN, OUTPUT);
  pinMode(SAFE_PIN, OUTPUT);
  pinMode(DANGER_PIN, OUTPUT);
  digitalWrite(BUZZ_PIN, LOW);
  digitalWrite(SAFE_PIN, LOW);
  digitalWrite(DANGER_PIN, HIGH);
}

int c;
void loop() {
  while (Bluetooth.available()) {
    c = Bluetooth.parseInt();
    if (c == 1) {
      digitalWrite(BUZZ_PIN, LOW);
      digitalWrite(SAFE_PIN, LOW);
      digitalWrite(DANGER_PIN, HIGH);
      Serial.println("DANGER");
    } else if (c == 0) {
      digitalWrite(BUZZ_PIN, HIGH);
      digitalWrite(SAFE_PIN, HIGH);
      digitalWrite(DANGER_PIN, LOW);
      Serial.println("SAFE");
    }
  }

  delay(100);
}
