#include "SerialCommActor.h"

SerialCommActor* actor = NULL;

void setup() {
  const unsigned int runPeriodicity = 1000; //ms
  actor = new SerialCommActor(runPeriodicity);
}

void loop() {
  actor->run(millis());
}
