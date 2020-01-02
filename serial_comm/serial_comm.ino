#include "SerialCommTask.h"
#include "Vector.h"

SerialCommTask* serialCommTask = NULL;

void setup() {
  const unsigned int runPeriodicity = 1000; //ms
  const long baudRate = 115200l;
  serialCommTask = new SerialCommTask(runPeriodicity, baudRate);
}

void loop() {
  serialCommTask->run(millis());

  if (millis() % 1000 == 0)
  {
    const unsigned int vectorCapacity = 8u;
    Vector<int> testVector(vectorCapacity);
    testVector.push_back(new int(5));
    testVector.push_back(new int(20));
  
    for (unsigned int i = 0; i < testVector.get_size(); ++i)
    {
      Serial.println(*(testVector.get(i)));
    }
  }
}
