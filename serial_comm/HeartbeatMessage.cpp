#include "HeartbeatMessage.h"

#include "Messages.h"
#include "Utils.h"

HeartbeatMessage::HeartbeatMessage() : MessageBase(Messages::HEARTBEAT)
{
  
}

Vector<unsigned char> HeartbeatMessage::encode()
{
  Vector<unsigned char> retVal(1);
  return retVal;
}
  
void HeartbeatMessage::decode(const unsigned char* data, const uint16_t size)
{
  UNUSED(data);
  UNUSED(size);
}
