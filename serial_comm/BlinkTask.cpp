#include "BlinkTask.h"
#include "Arduino.h"

BlinkTask::BlinkTask(const uint16_t runPeriodicity, const uint8_t _pinNumber):
TaskBase(runPeriodicity),
pinNumber(_pinNumber)
{
  pinMode(pinNumber, OUTPUT);
  blinkMode = BlinkMode::OFF;
}

void BlinkTask::execute(const unsigned long newTime)
{
  UNUSED(newTime);
  
  if (BlinkMode::OFF == blinkMode)
  {
    blinkMode = BlinkMode::ON;
    digitalWrite(pinNumber, HIGH);
  }
  else
  {
    blinkMode = BlinkMode::OFF;
    digitalWrite(pinNumber, LOW);
  }
}
