#ifndef HEADER_SERIAL_COMM_TASK
#define HEADER_SERIAL_COMM_TASK

#include "TaskBase.h"
#include "Vector.h"
#include "MessageBase.h"
#include "SerialCommIf.h"

class SerialCommTask : public TaskBase, public SerialCommIf
{
  public:
  SerialCommTask(const uint16_t runPeriodicity, const unsigned long baudRate);
  void sendMsg(MessageBase* message);

  protected:
  void execute(const unsigned long newTime);
  Vector<MessageBase*> messages = Vector<MessageBase*>(1);

  private:
};

#endif
