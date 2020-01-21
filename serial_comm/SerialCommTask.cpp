#include "SerialCommTask.h"

#include "Arduino.h"
#include "HandshakeMessage.h"
#include "ProtocolBase.h"
#include "Messages.h"
#include "LogMessage.h"
#include "BigBuf.h"

SerialCommTask::SerialCommTask(const uint16_t runPeriodicity, Stream& _channel, const ProtocolBase* _protocol) : 
TaskBase(runPeriodicity), 
channel(_channel),
protocol(_protocol)

{
  
}

void SerialCommTask::sendMsg(MessageBase* message)
{
  messagesToSend.push_back(message);
}

void SerialCommTask::execute(const unsigned long newTime)
{
  UNUSED(newTime);
  receiveMessages();
  sendMessages();
}

void SerialCommTask::sendMessages()
{
  for (unsigned int i = 0u; i < messagesToSend.size(); ++i)
  {
    Vector<unsigned char> data = protocol->encodeMessage(*messagesToSend.element_at(i));
    uint16_t dataSize = data.size();
    channel.write((unsigned char*)&dataSize, 2u);
    if (0 != data.size())
    {
      channel.write(data.data(), data.size());
    }
    delete messagesToSend.element_at(i);
  }
  messagesToSend.clear();
}

void SerialCommTask::receiveMessages()
{
  while (0 != channel.available())
  {
    //Header = 2byte messageSize
    uint16_t messageSize = 0u;
    channel.readBytes(BigBuf::getBigBuf(), 2u);
    messageSize = BigBuf::getBigBuf()[1u] << 8u | BigBuf::getBigBuf()[0u];

    channel.readBytes(BigBuf::getBigBuf(), messageSize);

    for (unsigned int i = 0u; i < messageReceivers.size(); ++i)
    {    
      MessageBase* message = protocol->decodeMessage(BigBuf::getBigBuf(), messageSize);
      if (NULL != message)
      {
        messageReceivers.element_at(i)->storeMessage(message);
      }
      else
      {
        String msg = "No protocol defined to handle message";
        sendMsg(new LogMessage(msg));
      }
    }
  }
}

void SerialCommTask::registerMsgReceiver(MessageReceiver* receiver)
{
  messageReceivers.push_back(receiver);
}
