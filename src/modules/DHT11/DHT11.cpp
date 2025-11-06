#include "DHT11.h"

DHT dht(2, DHT11); // default, nanti dioverride di init()

static float temperature = 0;
static float humidity = 0;

void DHT11_init(uint8_t pin, uint8_t type) {
  dht = DHT(pin, type);
  dht.begin();
}

void DHT11_read() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (!isnan(h) && !isnan(t)) {
    humidity = h;
    temperature = t;
  }
}

float DHT11_getTemperature() {
  return temperature;
}

float DHT11_getHumidity() {
  return humidity;
}
