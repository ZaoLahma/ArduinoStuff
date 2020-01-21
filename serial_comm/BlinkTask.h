#ifndef HEADER_INTERNAL_BLINK_TASK
#define HEADER_INTERNAL_BLINK_TASK

#include "TaskBase.h"
#include <stdint.h>

/**
 * A pin toggling task
 */
class BlinkTask : public TaskBase
{
  public:
  BlinkTask(const uint16_t runPeriodicity, const uint8_t _pinNumber);

  protected:
  void execute(const unsigned long newTime);

  enum class BlinkMode
  {
    ON,
    OFF
  };

  BlinkMode blinkMode;

  uint8_t pinNumber;

  private:
  
  
};

#endif
