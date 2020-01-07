#ifndef HANDSHAKEMESSAGE_HEADER
#define HANDSHAKEMESSAGE_HEADER

#include "MessageBase.h"
#include <stdint.h>

class HandshakeMessage : public MessageBase
{
  public:
  HandshakeMessage();
  Vector<char> encode();
  uint8_t payload;
  protected:
  private:
};

#endif
