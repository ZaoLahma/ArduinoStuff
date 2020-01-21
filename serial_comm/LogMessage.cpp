#include "LogMessage.h"

#include "Messages.h"
#include "Utils.h"

LogMessage::LogMessage(const String message) : MessageBase(Messages::LOG), payload(message)
{
  
}

Vector<unsigned char> LogMessage::encode()
{
  Vector<unsigned char> retVal(payload.length());

  for (unsigned int i = 0u; i < payload.length(); ++i)
  {
    retVal.push_back(payload.charAt(i));
  }

  return retVal;
}

void LogMessage::decode(const unsigned char* data, const uint16_t size)
{
  //Intentionally left empty
  UNUSED(data);
  UNUSED(size);
}
