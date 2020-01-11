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
    channel.write((uint8_t)messagesToSend.element_at(i)->getType());
    Vector<char> data = messagesToSend.element_at(i)->encode();
    if (0 != data.size())
    {
      uint16_t dataSize = data.size();
      channel.write((char*)&dataSize, 2u);
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
    //Header = 1byte messageId, 2byte messageSize
    uint8_t messageId = 0xFFu;
    channel.readBytes(BigBuf::getBigBuf(), 1u);
    messageId = (uint8_t)BigBuf::getBigBuf()[0u];

    uint16_t messageSize = 0x0000u;
    channel.readBytes(BigBuf::getBigBuf(), 2u);
    messageSize = BigBuf::getBigBuf()[1u] << 8u | BigBuf::getBigBuf()[0u];

    channel.readBytes(BigBuf::getBigBuf(), messageSize);

    for (unsigned int i = 0u; i < messageReceivers.size(); ++i)
    {    
      MessageBase* message = protocol->getMessage(messageId);
      if (NULL != message)
      {
        message->decode(BigBuf::getBigBuf(), messageSize);
        messageReceivers.element_at(i)->storeMessage(message);
      }
      else
      {
        String msg = "No protocol defined to handle message: " + String(messageId);
        sendMsg(new LogMessage(msg));
      }
    }
  }
}

void SerialCommTask::registerMsgReceiver(MessageReceiver* receiver)
{
  messageReceivers.push_back(receiver);
}
