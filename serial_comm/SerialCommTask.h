#ifndef HEADER_SERIAL_COMM_TASK
#define HEADER_SERIAL_COMM_TASK

#include "TaskBase.h"
#include "Vector.h"
#include "MessageBase.h"
#include "SerialCommIf.h"
#include "MessageReceiver.h"

class ProtocolBase;

class SerialCommTask : public TaskBase, public SerialCommIf
{
  public:
  SerialCommTask(const uint16_t runPeriodicity, Stream& _channel, const ProtocolBase* _protocol);
  void sendMsg(MessageBase* message);
  void registerMsgReceiver(MessageReceiver* receiver);

  protected:
  void execute(const unsigned long newTime);

  void sendMessages();
  void receiveMessages();
  
  Vector<MessageBase*> messagesToSend = Vector<MessageBase*>(1);

  Vector<MessageReceiver*> messageReceivers = Vector<MessageReceiver*>(1);

  Stream& channel;

  const ProtocolBase* protocol;

  private:
};

#endif
