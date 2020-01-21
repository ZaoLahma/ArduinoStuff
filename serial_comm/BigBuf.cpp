#include "BigBuf.h"

const uint16_t BigBuf::BIG_BUF_SIZE = 128u;

static unsigned char bufMemory[BigBuf::BIG_BUF_SIZE];
unsigned char* BigBuf::buf = bufMemory;

unsigned char* BigBuf::getBigBuf()
{
  return buf;
}
