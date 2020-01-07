#include "HandshakeMessage.h"

#include "Arduino.h"
#include "Messages.h"

HandshakeMessage::HandshakeMessage() :
MessageBase(Messages::HANDSHAKE)
{
  
}

Vector<char> HandshakeMessage::encode()
{
  Vector<char> retVal(1);
  retVal.push_back((char)payload);
  return retVal;
}
