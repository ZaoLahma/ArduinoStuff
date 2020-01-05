#include "InternalBlinkTask.h"
#include "Arduino.h"

InternalBlinkTask::InternalBlinkTask(const unsigned int runPeriodicity):
TaskBase(runPeriodicity)
{
  pinMode(LED_BUILTIN, OUTPUT);
  blinkMode = BlinkMode::ON;
}

void InternalBlinkTask::execute(const unsigned int newTime)
{
  if (BlinkMode::OFF == blinkMode)
  {
    blinkMode = BlinkMode::ON;
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    blinkMode = BlinkMode::OFF;
    digitalWrite(LED_BUILTIN, LOW);
  }
}
