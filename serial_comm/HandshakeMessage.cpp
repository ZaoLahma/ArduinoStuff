#include "HandshakeMessage.h"

#include "Arduino.h"
#include "Messages.h"
#include "Utils.h"

HandshakeMessage::HandshakeMessage() :
MessageBase(Messages::HANDSHAKE),
payload(0u)
{
  
}

Vector<unsigned char> HandshakeMessage::encode() const
{
  unsigned char buf[2u] = {(unsigned char) (payload & 0xFF), (unsigned char) (payload >> 8)};
  
  Vector<unsigned char> retVal(1);
  retVal.push_back(buf[0]);
  retVal.push_back(buf[1]);
  
  return retVal;
}

void HandshakeMessage::decode(const unsigned char* data, const uint16_t size)
{
  UNUSED(size);
  payload = 0;
  payload = data[1] << 8u | (data[0] & 0x00FF);
}
