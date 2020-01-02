#include "SerialCommTask.h"

SerialCommTask* serialCommTask = NULL;

void setup() {
  const unsigned int runPeriodicity = 1000; //ms
  const long baudRate = 115200l;
  serialCommTask = new SerialCommTask(runPeriodicity, baudRate);
}

void loop() {
  serialCommTask->run(millis());
}
