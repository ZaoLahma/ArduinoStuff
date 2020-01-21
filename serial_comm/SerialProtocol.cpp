#include "SerialProtocol.h"

#include "Messages.h"
#include "HandshakeMessage.h"
#include "HeartbeatMessage.h"
#include "Arduino.h"

Vector<unsigned char> SerialProtocol::encodeMessage(const MessageBase& message) const
{
  Vector<unsigned char> data = Vector<unsigned char>(1u);
  data.push_back((unsigned char)message.getType());

  Vector<unsigned char> payload = message.encode();

  for (unsigned int i = 0; i < payload.size(); ++i)
  {
    data.push_back(payload.element_at(i));
  }

  return data;
}

MessageBase* SerialProtocol::decodeMessage(const unsigned char* data, const uint16_t size) const
{
  Messages messageId = (Messages)data[0];
  
  MessageBase* retVal = NULL;

  switch (messageId)
  {
    case Messages::HANDSHAKE:
    {
      retVal = new HandshakeMessage();
    }
    break;
    case Messages::HEARTBEAT:
    {
      retVal = new HeartbeatMessage();
    }
    break;
    default:
    break;
  }

  if (NULL != retVal)
  {
    retVal->decode(&data[1], (size - 1u));
  }

  return retVal;
}
