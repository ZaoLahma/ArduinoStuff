#include "SerialCommTask.h"
#include "SerialCommIf.h"
#include "BlinkTask.h"
#include "TaskContext.h"
#include "SerialProtocol.h"
#include "LogMessage.h"
#include "ProgState.h"

TaskContext* taskContext = NULL;
SerialCommIf* serialCommIf = NULL;

void setup() {
  taskContext = new TaskContext();
  
  const uint16_t serialRunPeriodicity = 0u; //ms
  const unsigned long baudRate = 115200l;

  serialCommIf = new SerialCommTask(serialRunPeriodicity, baudRate, new SerialProtocol());
  
  taskContext->add_task(static_cast<SerialCommTask*>(serialCommIf));

  const uint16_t blinkRunPeriodicity = 500u; //ms
  taskContext->add_task(new BlinkTask(blinkRunPeriodicity, LED_BUILTIN));

  const uint16_t stateRunPeriodicity = 250u; //ms
  taskContext->add_task(new ProgStateTask(stateRunPeriodicity, serialCommIf));
}

void loop() {
  taskContext->run();
}
