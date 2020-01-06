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
}

void SerialCommTask::sendMessages()
{
  for (unsigned int i = 0u; i < messagesToSend.size(); ++i)
  {
    Serial.write((uint8_t)messagesToSend.element_at(i)->getType());
    char* data = messagesToSend.element_at(i)->encode();
    if (NULL != data)
    {
      Serial.write(1u);
      Serial.write(data, 1u);
    }
  }
}

void SerialCommTask::receiveMessages()
{
  char smallBuf;
  if (0 != Serial.available())
  {
    uint8_t messageId = 0xFFu;
    Serial.readBytes(&smallBuf, 1u);
    messageId = (uint8_t)smallBuf;
    MessageBase* msgBase = messagesToSend.element_at(0);
    HandshakeMessage* handshake = (HandshakeMessage*)msgBase;
    handshake->payload = messageId;
    digitalWrite(LED_BUILTIN, LOW);
    sendMessages();
  }
  else
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
}
