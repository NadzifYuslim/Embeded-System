#pragma once
#include <Arduino.h>
#include <DHT.h>

extern DHT dht;

void DHT11_init(uint8_t pin, uint8_t type);
void DHT11_read();
float DHT11_getTemperature();
float DHT11_getHumidity();
