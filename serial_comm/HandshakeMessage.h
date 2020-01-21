#ifndef HANDSHAKEMESSAGE_HEADER
#define HANDSHAKEMESSAGE_HEADER

#include "MessageBase.h"
#include <stdint.h>

/**
 * A communication initiation Message
 */
class HandshakeMessage : public MessageBase
{
  public:
  HandshakeMessage();
  Vector<unsigned char> encode() const;
  void decode(const unsigned char* data, const uint16_t size);
  int16_t payload;
  protected:
  private:
};

#endif
