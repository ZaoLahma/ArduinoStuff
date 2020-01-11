#include "HandshakeMessage.h"

#include "Arduino.h"
#include "Messages.h"

HandshakeMessage::HandshakeMessage() :
MessageBase(Messages::HANDSHAKE)
{
  
}

Vector<char> HandshakeMessage::encode()
{
  char buf[2u] = {(char) (payload & 0xFF), (char) (payload >> 8)};
  
  Vector<char> retVal(1);
  retVal.push_back(buf[0]);
  retVal.push_back(buf[1]);
  
  return retVal;
}

void HandshakeMessage::decode(const char* data, const uint16_t size)
{
  payload = 0;
  payload = data[1] << 8u | (data[0] & 0x00FF);
}
