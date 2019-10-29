class IntArray
{
private:
  int *m_ptr{nullptr};
  int m_size{0};

public:
  IntArray() = default;
  explicit IntArray(int size);
  ~IntArray();

  int size() const;
  bool isEmpty() const;
  bool isValidIndex(int index) const;
  // provide element access using overloading
  int &operator[](int index);
  // read only access to the elements
  int operator[](int index) const;
  friend std::ostream &operator<<(std::ostream &os, const IntArray &a);
};
