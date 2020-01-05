#ifndef HEADER_TASK_BASE
#define HEADER_TASK_BASE

#define UNUSED(x) (void)(x)

#include <stdint.h>

class TaskBase
{
  public:
  static const uint16_t UINT16T_MAX = 0xFFFFu;
  void run(const unsigned long newTimeStamp);

  TaskBase(const uint16_t _runPeriodicity);

  protected:
  const uint16_t runPeriodicity;
  uint16_t currTimeStamp = 0u;
    
  virtual void execute(const unsigned long newTime) = 0;

  private:
};

#endif
