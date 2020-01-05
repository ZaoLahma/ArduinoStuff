#include "SerialCommTask.h"

#include "Arduino.h"

SerialCommTask::SerialCommTask(const uint16_t runPeriodicity, const unsigned long baudRate) : 
TaskBase(runPeriodicity)
{
  Serial.begin(baudRate);
}

void SerialCommTask::execute(const unsigned long newTime)
{
  if (0 < Serial.availableForWrite())
  {
    Serial.print("Execute at: ");
    Serial.println(newTime);
  }
}
