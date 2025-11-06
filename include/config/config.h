#pragma once
#include "config_requirement.h"

#if USE_SENSOR_DHT
  #include "modules/DHT11/DHT11.h"
#endif

#if USE_SENSOR_LDR
  #include "modules/LDR/LDR.h"
#endif

#if USE_LED_OUTPUT
  #include "modules/LED/LED.h"
#endif

inline void setupAllDevices() {
  Serial.begin(SERIAL_BAUD);
  delay(1000);
  Serial.println(F("=== System Booting ==="));

  #if USE_LED_OUTPUT
    LED_init(LED_PIN);
    Serial.println(F("LED initialized"));
  #endif
  #if USE_SENSOR_DHT
    DHT11_init(SENSOR_DHT_PIN, DHT_TYPE);
    Serial.println(F("DHT11 initialized"));
  #endif
  #if USE_SENSOR_LDR
    LDR_init(SENSOR_LDR_PIN);
    Serial.println(F("LDR initialized"));
  #endif
}

inline void loopAllDevices() {
  #if USE_LED_OUTPUT
    LED_update();
  #endif

  #if USE_SENSOR_DHT
    DHT11_read();
    Serial.print(F("Temp: "));
    Serial.print(DHT11_getTemperature());
    Serial.print(F(" °C | Hum: "));
    Serial.println(DHT11_getHumidity());
  #endif

  #if USE_SENSOR_LDR
    int ldr = LDR_read();
    Serial.print(F("LDR Value: "));
    Serial.println(ldr);
  #endif

  delay(1000);
}
