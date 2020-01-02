#include "SerialCommActor.h"

#include "Arduino.h"

SerialCommActor::SerialCommActor(const unsigned int runPeriodicity) : ActorBase(runPeriodicity)
{
  
  Serial.begin(9600);
}

void SerialCommActor::execute(const unsigned int newTime)
{
  Serial.print("Ping at: ");
  Serial.println(currTimeStamp);
}
