#ifndef HEADER_TASK_BASE
#define HEADER_TASK_BASE

#include "Utils.h"
#include <stdint.h>

/**
 * The base class for Tasks
 * 
 * It is responsible for executing
 * the task with its configured periodicity
 */
class TaskBase
{
  public:
  void run(const unsigned long newTimeStamp);

  TaskBase(const uint16_t _runPeriodicity);

  protected:
  const uint16_t runPeriodicity;
  long currTimeStamp = 0u;
    
  virtual void execute(const unsigned long newTime) = 0;

  private:
};

#endif
