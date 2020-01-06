#include "SerialCommTask.h"

#include "Arduino.h"

SerialCommTask::SerialCommTask(const uint16_t runPeriodicity, const unsigned long baudRate) : 
TaskBase(runPeriodicity)
{
  Serial.begin(baudRate);
}

void SerialCommTask::sendMsg(MessageBase* message)
{
  messages.push_back(message);
}

void SerialCommTask::execute(const unsigned long newTime)
{
  UNUSED(newTime);
  for (unsigned int i = 0u; i < messages.size(); ++i)
  {
    Serial.write((uint8_t)messages.element_at(i)->getType());
    char* data = messages.element_at(i)->encode();
    if (NULL != data)
    {
      //Do stuff
    }
  }
}
