#include "TaskBase.h"

TaskBase::TaskBase(const uint16_t _runPeriodicity) : 
runPeriodicity(_runPeriodicity), currTimeStamp(0)
{
}

void TaskBase::run(const unsigned long newTimeStamp)
{
  if ((newTimeStamp - currTimeStamp) >= runPeriodicity)
  {
    currTimeStamp = newTimeStamp;

    execute(currTimeStamp);
  }
}
