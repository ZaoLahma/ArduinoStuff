#include "ActorBase.h"

ActorBase::ActorBase(const unsigned int _runPeriodicity) : 
runPeriodicity(_runPeriodicity), currTimeStamp(UINT_MAX)
{
}

void ActorBase::run(const unsigned int newTimeStamp)
{
  if ((UINT_MAX == currTimeStamp) ||
      ((newTimeStamp - currTimeStamp) >= runPeriodicity))
  {
    currTimeStamp = newTimeStamp;

    execute(currTimeStamp);
  }
}
