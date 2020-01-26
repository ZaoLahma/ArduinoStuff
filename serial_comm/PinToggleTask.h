#ifndef HEADER_INTERNAL_BLINK_TASK
#define HEADER_INTERNAL_BLINK_TASK

#include "TaskBase.h"
#include <stdint.h>

/**
 * A pin toggling task
 */
class PinToggleTask : public TaskBase
{
  public:
  PinToggleTask(const uint16_t runPeriodicity, const uint8_t _pinNumber);

  protected:
  void execute(const unsigned long newTime);

  enum class PinState
  {
    OFF,
    ON
  };

  PinState pinState;

  uint8_t pinNumber;

  private:
  
  
};

#endif
