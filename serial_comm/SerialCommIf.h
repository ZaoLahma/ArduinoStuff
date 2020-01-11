#ifndef HEADER_SERIAL_COMM_IF
#define HEADER_SERIAL_COMM_IF

#include "MessageBase.h"
#include "MessageReceiver.h"

class SerialCommIf
{
  public:
  virtual void sendMsg(MessageBase* message) = 0;
  virtual void registerMsgReceiver(MessageReceiver* receiver) = 0;
};

#endif
