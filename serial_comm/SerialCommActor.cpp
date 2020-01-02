#include "SerialCommActor.h"

#include "Arduino.h"

SerialCommActor::SerialCommActor(const unsigned int runPeriodicity, const long baudRate) : 
ActorBase(runPeriodicity)
{
  Serial.begin(baudRate);
}

void SerialCommActor::execute(const unsigned int newTime)
{
  Serial.print("Execute at: ");
  Serial.println(newTime);
}
