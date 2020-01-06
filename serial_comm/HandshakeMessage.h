#ifndef HANDSHAKEMESSAGE_HEADER
#define HANDSHAKEMESSAGE_HEADER

#include "MessageBase.h"

class HandshakeMessage : public MessageBase
{
  public:
  HandshakeMessage();
  char* encode();
  protected:
  private:
};

#endif
