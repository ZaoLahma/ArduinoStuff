#include "TaskBase.h"

TaskBase::TaskBase(const uint16_t _runPeriodicity) : 
runPeriodicity(_runPeriodicity), currTimeStamp(UINT16T_MAX)
{
}

void TaskBase::run(const unsigned long newTimeStamp)
{
  if ((UINT16T_MAX == currTimeStamp) ||
      ((newTimeStamp - currTimeStamp) >= runPeriodicity))
  {
    currTimeStamp = newTimeStamp;

    execute(currTimeStamp);
  }
}
