#include "TaskBase.h"

TaskBase::TaskBase(const uint16_t _runPeriodicity) : 
runPeriodicity(_runPeriodicity), currTimeStamp(UINT_MAX)
{
}

void TaskBase::run(const unsigned long newTimeStamp)
{
  if ((UINT_MAX == currTimeStamp) ||
      ((newTimeStamp - currTimeStamp) >= runPeriodicity))
  {
    currTimeStamp = newTimeStamp;

    execute(currTimeStamp);
  }
}
