#include "HandshakeMessage.h"

#include "Arduino.h"
#include "Messages.h"

HandshakeMessage::HandshakeMessage() :
MessageBase(Messages::HANDSHAKE)
{
  
}

char* HandshakeMessage::encode()
{
  return (char*)&payload;
}

MessageBase* HandshakeMessage::decode(const char* data)
{
  return this;
}
