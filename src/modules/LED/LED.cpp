#include "LED.h"

static uint8_t ledPin;
static bool ledState = false;
static unsigned long lastToggle = 0;

void LED_init(uint8_t pin) {
  ledPin = pin;
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void LED_on() {
  digitalWrite(ledPin, HIGH);
  ledState = true;
}

void LED_off() {
  digitalWrite(ledPin, LOW);
  ledState = false;
}

void LED_update() {
  unsigned long now = millis();
  if (now - lastToggle >= 1000) { // blink tiap 1 detik
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    lastToggle = now;
  }
}
