#include "HeartbeatMessage.h"

#include "Messages.h"
#include "Utils.h"

HeartbeatMessage::HeartbeatMessage() : MessageBase(Messages::HEARTBEAT)
{
  
}

Vector<char> HeartbeatMessage::encode()
{
  Vector<char> retVal(1);
  return retVal;
}
  
void HeartbeatMessage::decode(const char* data, const uint16_t size)
{
  UNUSED(data);
  UNUSED(size);
}
