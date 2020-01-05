#include "SerialCommTask.h"
#include "InternalBlinkTask.h"
#include "Vector.h"

SerialCommTask* serialCommTask = NULL;
InternalBlinkTask* internalBlinkTask = NULL;

void setup() {
  const unsigned int serialRunPeriodicity = 1000; //ms
  const long baudRate = 115200l;
  serialCommTask = new SerialCommTask(serialRunPeriodicity, baudRate);

  const unsigned int blinkRunPeriodicity = 100; //ms
  internalBlinkTask = new InternalBlinkTask(blinkRunPeriodicity);
}

void loop() {
  serialCommTask->run(millis());
  internalBlinkTask->run(millis());
}
