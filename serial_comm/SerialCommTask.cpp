#include "SerialCommTask.h"

#include "Arduino.h"
#include "HandshakeMessage.h"

SerialCommTask::SerialCommTask(const uint16_t runPeriodicity, const unsigned long baudRate) : 
TaskBase(runPeriodicity)
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
      Serial.write(dataSize);
      Serial.write(data.data(), data.size());
    }
    delete messagesToSend.element_at(i);
  }
  messagesToSend.clear();
}

void SerialCommTask::receiveMessages()
{
  char smallBuf = 0u;
  if (0 != Serial.available())
  {
    //Header = 1byte messageId, 2byte messageSize
    uint8_t messageId = 0xFFu;
    Serial.readBytes(&smallBuf, 1u);
    messageId = (uint8_t)smallBuf;
    
    HandshakeMessage* handshake = new HandshakeMessage();
    handshake->payload = messageId;
    sendMsg(handshake);
    digitalWrite(LED_BUILTIN, LOW);
  }
  else
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
}
