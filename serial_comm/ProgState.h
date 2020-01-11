#ifndef HEADER_PROG_STATE_TASK
#define HEADER_PROG_STATE_TASK

#include "TaskBase.h"
#include "SerialCommIf.h"
#include "MessageReceiver.h"

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
