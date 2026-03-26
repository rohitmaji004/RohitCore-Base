#include "RohitCoreBase.h"

bool RohitCoreBase::_debugEnabled = true;

void RohitCoreBase::begin(bool enableDebug, long baud) {
  _debugEnabled = enableDebug;

  if (_debugEnabled) {
    Serial.begin(baud);
    delay(100);
    Serial.println("[RCBase] Initialized");
  }
}

void RohitCoreBase::log(RCLogLevel level, String message) {
  if (!_debugEnabled) return;

  String prefix;

  switch (level) {
    case RC_INFO:  prefix = "[INFO] "; break;
    case RC_WARN:  prefix = "[WARN] "; break;
    case RC_ERROR: prefix = "[ERROR] "; break;
  }

  Serial.println(prefix + message);
}

void RohitCoreBase::debug(String message) {
  log(RC_INFO, message);
}

String RohitCoreBase::getBoard() {
  #if defined(ESP32)
    return "ESP32";
  #elif defined(ARDUINO_AVR_UNO)
    return "Arduino UNO";
  #elif defined(ARDUINO_AVR_NANO)
    return "Arduino Nano";
  #else
    return "Unknown Board";
  #endif
}

uint32_t RohitCoreBase::getFreeMemory() {
  #if defined(ESP32)
    return ESP.getFreeHeap();
  #elif defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_NANO)
    extern int __heap_start, *__brkval;
    int v;
    return (int)&v - (__brkval == 0 ? (int)&__heap_start : (int)__brkval);
  #else
    return 0;
  #endif
}
