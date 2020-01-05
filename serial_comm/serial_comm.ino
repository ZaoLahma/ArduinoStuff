#include "SerialCommTask.h"
#include "BlinkTask.h"
#include "TaskContext.h"

TaskContext* taskContext = NULL;

void setup() {
  taskContext = new TaskContext();
  
  const uint16_t serialRunPeriodicity = 1000u; //ms
  const unsigned long baudRate = 115200l;
  taskContext->add_task(new SerialCommTask(serialRunPeriodicity, baudRate));

  const uint16_t blinkRunPeriodicity = 2000u; //ms
  taskContext->add_task(new BlinkTask(blinkRunPeriodicity, LED_BUILTIN));

  taskContext->add_task(new BlinkTask(blinkRunPeriodicity / 10u, 2u));

  taskContext->add_task(new BlinkTask(blinkRunPeriodicity / 20u, 3u));

  taskContext->add_task(new BlinkTask(blinkRunPeriodicity / 2u, 4u));
}

void loop() {
  taskContext->run();
}
