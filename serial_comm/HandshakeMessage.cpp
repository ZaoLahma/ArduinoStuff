#include "HandshakeMessage.h"

#include "Arduino.h"
#include "Messages.h"

HandshakeMessage::HandshakeMessage() :
MessageBase(Messages::HANDSHAKE)
{
  
}

char* HandshakeMessage::encode()
{
  return NULL;
}
