#ifndef HEADER_MESSAGE_BASE
#define HEADER_MESSAGE_BASE

#include "Messages.h"
#include "Vector.h"

class MessageBase
{
  public:
  MessageBase(const Messages& type);
  virtual ~MessageBase() {}
  virtual Vector<char> encode() = 0;
  Messages getType();

  protected:
  const Messages msgType;

  private:
};

#endif
