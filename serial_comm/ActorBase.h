#ifndef HEADER_ACTOR_BASE
#define HEADER_ACTOR_BASE

class ActorBase
{
  public:
  static const unsigned int UINT_MAX = 0xFFFFFFFFu;
  void run(const unsigned int newTimeStamp);

  ActorBase(const unsigned int _runPeriodicity);

  protected:
  const unsigned int runPeriodicity;
  unsigned int currTimeStamp = 0;
    
  virtual void execute(const unsigned int newTime) = 0;

  private:
};

#endif
