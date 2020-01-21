#ifndef HEADER_BIG_BUF
#define HEADER_BIG_BUF

#include <stdint.h>

class BigBuf
{
  public:
  static const uint16_t BIG_BUF_SIZE;
  static unsigned char* getBigBuf();

  protected:
  static unsigned char* buf;
  
  private:
};

#endif
