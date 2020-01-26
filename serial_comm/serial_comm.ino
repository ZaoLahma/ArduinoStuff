#include "SerialCommTask.h"
#include "SerialCommIf.h"
#include "PinToggleTask.h"
#include "TaskContext.h"
#include "SerialProtocol.h"
#include "LogMessage.h"
#include "ProgState.h"

TaskContext taskContext;

void setup() {
  const uint16_t serialRunPeriodicity = 0u; //ms
  const unsigned long baudRate = 115200l;
  Serial.begin(baudRate);

  SerialCommIf* serialCommIf = new SerialCommTask(serialRunPeriodicity, Serial, new SerialProtocol());
  
  taskContext.addTask(static_cast<SerialCommTask*>(serialCommIf));

  const uint16_t blinkRunPeriodicity = 100u; //ms
  taskContext.addTask(new PinToggleTask(blinkRunPeriodicity, LED_BUILTIN));

  const uint16_t stateRunPeriodicity = 250u; //ms
  taskContext.addTask(new ProgStateTask(stateRunPeriodicity, serialCommIf));
}

void loop() {
  taskContext.run();
}
