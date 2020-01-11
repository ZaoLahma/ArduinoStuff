#include "LogMessage.h"

#include "Messages.h"
#include "Utils.h"

LogMessage::LogMessage(const String message) : MessageBase(Messages::LOG), payload(message)
{
  
}

Vector<char> LogMessage::encode()
{
  Vector<char> retVal(payload.length());

  for (unsigned int i = 0u; i < payload.length(); ++i)
  {
    retVal.push_back(payload.charAt(i));
  }

  return retVal;
}

void LogMessage::decode(const char* data, const uint16_t size)
{
  //Empty by choice
  UNUSED(data);
  UNUSED(size);
}
