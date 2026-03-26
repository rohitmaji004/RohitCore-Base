#ifndef RohitCoreBase_h
#define RohitCoreBase_h

#include <Arduino.h>

enum RCLogLevel {
  RC_INFO,
  RC_WARN,
  RC_ERROR
};

class RohitCoreBase {
  public:
    static void begin(bool enableDebug = true, long baud = 115200);
    static void log(RCLogLevel level, String message);
    static void debug(String message);
    static String getBoard();
    static uint32_t getFreeMemory();

  private:
    static bool _debugEnabled;
};

#endif
