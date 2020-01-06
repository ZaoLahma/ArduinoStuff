#ifndef HANDSHAKEMESSAGE_HEADER
#define HANDSHAKEMESSAGE_HEADER

#include "MessageBase.h"
#include <stdint.h>

class HandshakeMessage : public MessageBase
{
  public:
  HandshakeMessage();
  char* encode();
  uint8_t payload;
  MessageBase* decode(const char* data);
  protected:
  private:
};

#endif
