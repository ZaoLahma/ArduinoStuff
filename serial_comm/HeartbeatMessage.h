#ifndef HEADER_HEARTBEAT_MESSAGE
#define HEADER_HEARTBEAT_MESSAGE

#include "MessageBase.h"

class HeartbeatMessage : public MessageBase
{
  public:
  HeartbeatMessage();
  Vector<char> encode();
  void decode(const char* data, const uint16_t size);

  protected:
  private:
};

#endif
