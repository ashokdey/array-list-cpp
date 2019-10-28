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
};
