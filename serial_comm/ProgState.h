#ifndef HEADER_PROG_STATE_TASK
#define HEADER_PROG_STATE_TASK

#include "TaskBase.h"
#include "SerialCommIf.h"
#include "MessageReceiver.h"

/**
 * Class that keeps track of the overall program state
 * 
 * It will drop back to previous states if conditions
 * to remain in the current state are no longer fulfilled,
 * and will try to get back up to the highest possible
 * state after
 */
class ProgStateTask : public TaskBase
{
  public:
  ProgStateTask(const uint16_t runPeriodicity, SerialCommIf* _commIf);
  
  enum class State
  {
    INIT = 0,
    CONNECTING = 1,
    CONNECTED = 2
  };

  State getCurrState();

  protected:
  void execute(const unsigned long newTime);

  State currState;

  SerialCommIf* commIf;

  MessageReceiver messages;
  
  private:
};

#endif
