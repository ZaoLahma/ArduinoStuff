#ifndef HEADER_INTERNAL_BLINK_TASK
#define HEADER_INTERNAL_BLINK_TASK

#include "TaskBase.h"

class InternalBlinkTask : public TaskBase
{
  public:
  InternalBlinkTask(const unsigned int runPeriodicity);

  protected:
  void execute(const unsigned int newTime);

  enum class BlinkMode
  {
    ON,
    OFF
  };

  BlinkMode blinkMode;

  private:
  
  
};

#endif
