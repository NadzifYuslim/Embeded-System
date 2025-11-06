#pragma once
#include <Arduino.h>

// =====================================================
// Pilih project yang digunakan
// =====================================================
// Ditentukan otomatis lewat build_flags di platformio.ini
// (tidak perlu ubah manual)
//#define PROJECT_2     // Project 1 (ESP32: LDR + LED)
#define PROJECT_2    // Project 2 (UNO: DHT11 + LED)

// =====================================================
// Konfigurasi Project 1:(LDR + LED)
// =====================================================

#if defined(PROJECT_1)
  #define TARGET_1
  #define USE_SENSOR_LDR  1
  #define USE_SENSOR_DHT  0
  #define USE_LED_OUTPUT  1

  #define SENSOR_LDR_PIN  34
  #define LED_PIN         2
  #define SERIAL_BAUD     115200

// =====================================================
// Konfigurasi Project 2:(DHT11 + LED)
// =====================================================
#elif defined(PROJECT_2)
  #define TARGET_2
  #define USE_SENSOR_LDR  0
  #define USE_SENSOR_DHT  1
  #define USE_LED_OUTPUT  1

  #define SENSOR_DHT_PIN  2
  #define LED_PIN         7
  #define DHT_TYPE        DHT11
  #define SERIAL_BAUD     9600

#else
  #error "Pilih salah satu PROJECT_ESP32 atau PROJECT_UNO di platformio.ini"
#endif
