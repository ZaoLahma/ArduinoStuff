#include "SerialCommTask.h"

#include "Arduino.h"

SerialCommTask::SerialCommTask(const unsigned int runPeriodicity, const long baudRate) : 
TaskBase(runPeriodicity)
{
  Serial.begin(baudRate);
}

void SerialCommTask::execute(const unsigned int newTime)
{
  Serial.print("Execute at: ");
  Serial.println(newTime);
}
