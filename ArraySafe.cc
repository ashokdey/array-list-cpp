#include "ArraySafe.h"
#include "IndexException.cc"

IntArray::IntArray(int size)
{
  if (size != 0)
  {
    m_ptr = new int[size]{};
    m_size = size;
  }
}

IntArray::~IntArray()
{
  delete[] m_ptr;
}

int IntArray::size() const
{
  return m_size;
}

bool IntArray::isEmpty() const
{
  return (m_size == 0);
}

bool IntArray::isValidIndex(int index) const
{
  return (index >= 0) && (index < m_size);
}

int &IntArray::operator[](int index)
{
  if (!isValidIndex(index))
  {
    throw ArrayIndexException(index);
  }
  return m_ptr[index];
}

int IntArray::operator[](int index) const
{
  if (!isValidIndex(index))
  {
    throw ArrayIndexException(index);
  }
  return m_ptr[index];
}