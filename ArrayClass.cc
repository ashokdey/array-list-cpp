#include "IndexException.cc"

class IntArray
{
private:
  int *m_ptr{nullptr};
  int m_size{0};

public:
  IntArray() = default;

  explicit IntArray(int size)
  {
    if (size != 0)
    {
      m_ptr = new int[size]{};
      m_size = size;
    }
  }

  // free the memory utilized
  ~IntArray()
  {
    delete[] m_ptr;
  }

  int size() const
  {
    return m_size;
  }

  bool isEmpty() const
  {
    return (m_size == 0);
  }

  bool isValidIndex(int index) const
  {
    return (index >= 0) && (index < m_size);
  }

  // provide element access using overloading
  int &operator[](int index)
  {
    if (!isValidIndex(index))
    {
      throw ArrayIndexException(index);
    }
    return m_ptr[index];
  }

  // read only access to the elements
  int operator[](int index) const
  {
    if (!isValidIndex(index))
    {
      throw ArrayIndexException(index);
    }
    return m_ptr[index];
  }
};
