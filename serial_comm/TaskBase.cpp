#include "TaskBase.h"

TaskBase::TaskBase(const unsigned int _runPeriodicity) : 
runPeriodicity(_runPeriodicity), currTimeStamp(UINT_MAX)
{
}

void TaskBase::run(const unsigned int newTimeStamp)
{
  if ((UINT_MAX == currTimeStamp) ||
      ((newTimeStamp - currTimeStamp) >= runPeriodicity))
  {
    currTimeStamp = newTimeStamp;

    execute(currTimeStamp);
  }
}
