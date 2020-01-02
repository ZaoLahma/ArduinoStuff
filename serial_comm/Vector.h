#ifndef HEADER_VECTOR
#define HEADER_VECTOR

#include "Arduino.h"

template <class T>
class Vector
{
  public:
  Vector<T>(const unsigned int vectorCapacity) : elementCapacity(vectorCapacity), numDataElements(0)
  {
    for (unsigned int i = 0; i < elementCapacity; ++i)
    {
      elements[i].element = NULL;
    }
  }

  void push_back(T* element)
  {
    for (unsigned int i = 0; i < elementCapacity; ++i)
    {
      if (NULL == elements[i].element)
      {
        elements[i].element = element;
        numDataElements++;
        break;
      }
    }
  }

  T* get(const unsigned int index)
  {
    if (index <= get_size())
    {
      return elements[index].element;
    }

    return NULL;
  }

  const unsigned int get_size()
  {
    return numDataElements;
  }

  protected:
  unsigned int elementCapacity = 8;
  
  class ElementWrapper
  {
    public:
    T* element;
  };
  
  ElementWrapper* elements = new ElementWrapper[elementCapacity];

  private:
  unsigned int numDataElements;
  
};

#endif
