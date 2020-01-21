#ifndef HEADER_BIG_BUF
#define HEADER_BIG_BUF

#include <stdint.h>

/**
 * To be used for temporary storage of
 * large(ish) chunks of data.
 * 
 * The buffer is only guaranteed to keep
 * data during the execution of a function.
 * 
 * The buffer is not guaranteed to keep data
 * across executions of a function.
 */
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
