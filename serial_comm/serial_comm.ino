#include "SerialCommTask.h"
#include "BlinkTask.h"
#include "TaskContext.h"

TaskContext* taskContext = NULL;

void setup() {
  taskContext = new TaskContext();
  
  const uint16_t serialRunPeriodicity = 1000; //ms
  const unsigned long baudRate = 115200l;
  taskContext->add_task(new SerialCommTask(serialRunPeriodicity, baudRate));

  const uint16_t blinkRunPeriodicity = 2000; //ms
  taskContext->add_task(new BlinkTask(blinkRunPeriodicity, LED_BUILTIN));
}

void loop() {
  taskContext->run();
}
