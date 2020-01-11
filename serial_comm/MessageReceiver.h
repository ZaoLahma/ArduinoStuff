#ifndef HEADER_MESSAGE_RECEIVER
#define HEADER_MESSAGE_RECEIVER

#include "MessageBase.h"
#include "Vector.h"

class MessageReceiver
{
  public:
  MessageReceiver();
  MessageBase* getNextMessage();
  void storeMessage(MessageBase* msg);

  protected:
  Vector<MessageBase*> messages = Vector<MessageBase*>(1);
  uint16_t currMessage;

  MessageBase* decode(const char* data);
  

  private:
};

#endif
