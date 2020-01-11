#ifndef HEADER_BIG_BUF
#define HEADER_BIG_BUF

#include <stdint.h>

class BigBuf
{
  public:
  static const uint16_t BIG_BUF_SIZE;
  static char* getBigBuf();

  protected:
  static char* buf;
  
  private:
};

#endif
