#ifndef HEADER_HEARTBEAT_MESSAGE
#define HEADER_HEARTBEAT_MESSAGE

#include "MessageBase.h"

class HeartbeatMessage : public MessageBase
{
  public:
  HeartbeatMessage();
  Vector<unsigned char> encode();
  void decode(const unsigned char* data, const uint16_t size);

  protected:
  private:
};

#endif
