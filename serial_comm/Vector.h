#ifndef HEADER_VECTOR
#define HEADER_VECTOR

#include "Arduino.h"
#include <stdint.h>

template <class T>
class Vector
{
  public:
  Vector<T>(const uint16_t vectorCapacity) : elementCapacity(vectorCapacity), numDataElements(0u)
  {
    if (0u == elementCapacity)
    {
      elementCapacity++;
    }
    elements = new T[elementCapacity];
  }

  ~Vector<T>()
  {
    delete[] elements;
  }

  void push_back(const T& element)
  {
    if (!(numDataElements < elementCapacity))
    {
      //Copy all values to new array
      elementCapacity = 2u * elementCapacity;
      T* elementsCopy = new T[elementCapacity];
      for (uint16_t i = 0u; i < numDataElements; ++i)
      {
        elementsCopy[i] = elements[i];
      }
      delete[] elements;
      elements = elementsCopy;
    }
    
    elements[numDataElements] = element;
    numDataElements++;
  }

  T& element_at(const uint16_t index)
  {
    return elements[index];
  }

  T* data()
  {
    return elements;
  }

  uint16_t size()
  {
    return numDataElements;
  }

  void clear()
  {
    numDataElements = 0u;
  }
  
  protected:
  uint16_t elementCapacity;
  
  T* elements;

  uint16_t numDataElements;

  private:
  
};

#endif
