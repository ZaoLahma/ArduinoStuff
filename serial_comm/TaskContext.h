#ifndef HEADER_TASK_CONTEXT
#define HEADER_TASK_CONTEXT

#include "TaskBase.h"
#include "Vector.h"

/**
 * The class is responsible for running
 * tasks that have been registered to it
 */
class TaskContext
{
  public:
  void run();
  void addTask(TaskBase* const task);

  protected:
  Vector<TaskBase*> tasks = Vector<TaskBase*>(1);

  private:
};

#endif
