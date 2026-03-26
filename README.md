# RohitCore-Base

Core utility library for Arduino providing debugging, board detection, and memory tools. Designed as the foundation for the RohitCore ecosystem.

---

## 🚀 Features

- 🔍 Debug logging system (INFO, WARN, ERROR)
- 🧠 Board detection (UNO, Nano, ESP32)
- 📊 Memory monitoring utilities
- ⚡ Lightweight and fast

---

## 🧰 Supported Boards

- Arduino UNO  
- Arduino Nano  
- ESP32  

---

## 📦 Installation

### Method 1: Arduino Library Manager (Recommended)
1. Open Arduino IDE  
2. Go to **Sketch → Include Library → Manage Libraries**  
3. Search for **RohitCore-Base**  
4. Click **Install**

### Method 2: Manual Installation
1. Download this repository as ZIP  
2. Open Arduino IDE  
3. Go to **Sketch → Include Library → Add .ZIP Library**  
4. Select the downloaded ZIP file  

---

## 🧪 Example Usage

```cpp
#include <RohitCoreBase.h>

void setup() {
  RohitCoreBase::begin(true);

  RohitCoreBase::debug("System started");

  RohitCoreBase::log(RC_INFO, "Info message");
  RohitCoreBase::log(RC_WARN, "Warning message");
  RohitCoreBase::log(RC_ERROR, "Error message");

  Serial.println("Board: " + RohitCoreBase::getBoard());
  Serial.println("Free Memory: " + String(RohitCoreBase::getFreeMemory()));
}

void loop() {}
