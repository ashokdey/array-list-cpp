#include <iostream>
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

IntArray::IntArray(const IntArray &source)
{
  if (!source.isEmpty())
  {
    m_size = source.m_size;

    m_ptr = new int[m_size];
    for (int i = 0; i < m_size; i += 1)
    {
      m_ptr[i] = source.m_ptr[i];
    }
  }
}

IntArray::IntArray(IntArray &&source)
{
  // transfer owenership from the source
  m_size = source.m_size;
  m_ptr = source.m_ptr;

  // clear the cource
  source.m_ptr = nullptr;
  source.m_size = 0;
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

void swap(IntArray &source, IntArray &destination) noexcept
{
  // member wise swap
  std::swap(source.m_ptr, destination.m_ptr);
  std::swap(source.m_size, destination.m_size);
}

IntArray &IntArray::operator=(IntArray &source)
{
  // Using "copy and swap idiom"
  swap(*this, source);
  return *this;
}

std::ostream &operator<<(std::ostream &os, const IntArray &a)
{
  os << "[ ";
  for (int i = 0; i < a.size(); i += 1)
  {
    os << a[i] << " ";
  }
  os << " ]";
  return os;
}
