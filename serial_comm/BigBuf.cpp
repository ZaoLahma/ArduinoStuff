#include "BigBuf.h"

const uint16_t BigBuf::BIG_BUF_SIZE = 128u;

static char bufMemory[BigBuf::BIG_BUF_SIZE];
char* BigBuf::buf = bufMemory;

char* BigBuf::getBigBuf()
{
  return buf;
}
