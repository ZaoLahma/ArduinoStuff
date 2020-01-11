#include "SerialProtocol.h"

#include "Messages.h"
#include "HandshakeMessage.h"
#include "Arduino.h"

MessageBase* SerialProtocol::getMessage(const uint8_t msgType) const
{
  Messages message = (Messages)msgType;

  MessageBase* retVal = NULL;

  switch (message)
  {
    case Messages::HANDSHAKE:
    {
      retVal = new HandshakeMessage();
    }
    break;
    default:
    break;
  }

  return retVal;
}
