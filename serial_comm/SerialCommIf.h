#ifndef HEADER_SERIAL_COMM_IF
#define HEADER_SERIAL_COMM_IF

#include "MessageBase.h"

class SerialCommIf
{
  public:
  virtual void sendMsg(MessageBase* message) = 0;
};

#endif
