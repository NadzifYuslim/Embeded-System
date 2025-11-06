#include "LDR.h"

static uint8_t ldrPin;

void LDR_init(uint8_t pin) {
  ldrPin = pin;
}

int LDR_read() {
  int val = analogRead(ldrPin);
  return val;
}
