#include "SerialCommTask.h"

SerialCommTask* actor = NULL;

void setup() {
  const unsigned int runPeriodicity = 1000; //ms
  const long baudRate = 115200l;
  actor = new SerialCommTask(runPeriodicity, baudRate);
}

void loop() {
  actor->run(millis());
}
