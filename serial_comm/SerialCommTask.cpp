#include "SerialCommTask.h"

#include "Arduino.h"
#include "HandshakeMessage.h"
#include "ProtocolBase.h"

SerialCommTask::SerialCommTask(const uint16_t runPeriodicity, const unsigned long baudRate, const ProtocolBase* _protocol) : 
TaskBase(runPeriodicity), protocol(_protocol)
{
  Serial.begin(baudRate);
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
    Serial.write((uint8_t)messagesToSend.element_at(i)->getType());
    Vector<char> data = messagesToSend.element_at(i)->encode();
    if (0 != data.size())
    {
      uint16_t dataSize = data.size();
      Serial.write((char*)&dataSize, 2u);
      Serial.write(data.data(), data.size());
    }
    delete messagesToSend.element_at(i);
  }
  messagesToSend.clear();
}

void SerialCommTask::receiveMessages()
{
  char smallBuf[2];
  memset(smallBuf, 0u, sizeof(smallBuf));
  while (0 != Serial.available())
  {
    //Header = 1byte messageId, 2byte messageSize
    uint8_t messageId = 0xFFu;
    Serial.readBytes(&smallBuf[0u], 1u);
    messageId = (uint8_t)smallBuf[0u];

    uint16_t messageSize = 0x0000u;
    Serial.readBytes(&smallBuf[0u], 2u);
    messageSize = smallBuf[1u] << 8u | smallBuf[0u];

    char bigBuf[512];
    memset(bigBuf, 0u, 512);
    Serial.readBytes(bigBuf, messageSize);

    MessageBase* message = protocol->getMessage(messageId);
    if (NULL != message)
    {
      message->decode(bigBuf, messageSize);
    }

    sendMsg(message);
  }
}
