#ifndef HANDSHAKEMESSAGE_HEADER
#define HANDSHAKEMESSAGE_HEADER

#include "MessageBase.h"
#include <stdint.h>

class HandshakeMessage : public MessageBase
{
  public:
  HandshakeMessage();
  Vector<unsigned char> encode();
  void decode(const unsigned char* data, const uint16_t size);
  int16_t payload;
  protected:
  private:
};

#endif
