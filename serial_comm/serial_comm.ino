#include "SerialCommActor.h"

SerialCommActor* actor = NULL;

void setup() {
  const unsigned int runPeriodicity = 1000; //ms
  const long baudRate = 115200l;
  actor = new SerialCommActor(runPeriodicity, baudRate);
}

void loop() {
  actor->run(millis());
}
