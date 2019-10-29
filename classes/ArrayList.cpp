#include <iostream>
#include "../headers/ArrayList.hpp"
#include "IndexException.cpp"

template <typename T>
ArrayList<T>::ArrayList(int size)
{
  if (size != 0)
  {
    m_ptr = new T[size]{};
    m_size = size;
  }
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList &source)
{
  if (!source.isEmpty())
  {
    m_size = source.m_size;

    m_ptr = new T[m_size];
    for (int i = 0; i < m_size; i += 1)
    {
      m_ptr[i] = source.m_ptr[i];
    }
  }
}

template <typename T>
ArrayList<T>::ArrayList(ArrayList &&source)
{
  // transfer owenership from the source
  m_size = source.m_size;
  m_ptr = source.m_ptr;

  // clear the cource
  source.m_ptr = nullptr;
  source.m_size = 0;
}

template <typename T>
ArrayList<T>::~ArrayList()
{
  delete[] m_ptr;
}

template <typename T>
int ArrayList<T>::size() const
{
  return m_size;
}

template <typename T>
bool ArrayList<T>::isEmpty() const
{
  return (m_size == 0);
}

template <typename T>
bool ArrayList<T>::isValidIndex(int index) const
{
  return (index >= 0) && (index < m_size);
}

template <typename T>
T &ArrayList<T>::operator[](int index)
{
  if (!isValidIndex(index))
  {
    throw ArrayIndexException(index);
  }
  return m_ptr[index];
}

template <typename T>
T ArrayList<T>::operator[](int index) const
{
  if (!isValidIndex(index))
  {
    throw ArrayIndexException(index);
  }
  return m_ptr[index];
}

template <typename T>
void swap(ArrayList<T> &source, ArrayList<T> &destination) noexcept
{
  // member wise swap
  std::swap(source.m_ptr, destination.m_ptr);
  std::swap(source.m_size, destination.m_size);
}

template <typename T>
ArrayList<T> &ArrayList<T>::operator=(ArrayList<T> &source)
{
  // Using "copy and swap idiom"
  swap(*this, source);
  return *this;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const ArrayList<T> &a)
{
  os << "[ ";
  for (int i = 0; i < a.size(); i += 1)
  {
    os << a[i] << " ";
  }
  os << " ]";
  return os;
}
