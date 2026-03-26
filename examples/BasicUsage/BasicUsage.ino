#include <RohitCoreBase.h>

void setup() {
  // Initialize RohitCore Base
  RohitCoreBase::begin(true);

  // Basic debug message
  RohitCoreBase::debug("System started successfully");

  // Log with different levels
  RohitCoreBase::log(RC_INFO, "Info message");
  RohitCoreBase::log(RC_WARN, "Warning message");
  RohitCoreBase::log(RC_ERROR, "Error message");

  // Print board type
  String board = RohitCoreBase::getBoard();
  Serial.println("Board: " + board);

  // Print free memory
  uint32_t memory = RohitCoreBase::getFreeMemory();
  Serial.println("Free Memory: " + String(memory));
}

void loop() {
  // Nothing required here for this example
}
