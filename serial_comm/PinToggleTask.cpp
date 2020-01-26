#include "PinToggleTask.h"
#include "Arduino.h"

PinToggleTask::PinToggleTask(const uint16_t runPeriodicity, const uint8_t _pinNumber):
TaskBase(runPeriodicity),
pinNumber(_pinNumber)
{
  pinMode(pinNumber, OUTPUT);
  pinState = PinState::OFF;
}

void PinToggleTask::execute(const unsigned long newTime)
{
  UNUSED(newTime);
  
  if (PinState::OFF == pinState)
  {
    pinState = PinState::ON;
    digitalWrite(pinNumber, HIGH);
  }
  else
  {
    pinState = PinState::OFF;
    digitalWrite(pinNumber, LOW);
  }
}
