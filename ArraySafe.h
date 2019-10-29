class IntArray
{
private:
  int *m_ptr{nullptr};
  int m_size{0};

public:
  IntArray() = default;
  explicit IntArray(int size);

  // the copy constructor
  IntArray(const IntArray &source);

  // the move constructor
  IntArray(IntArray &&source);

  // the destructor to free memory
  ~IntArray();

  int size() const;
  bool isEmpty() const;
  bool isValidIndex(int index) const;

  // provide element access using overloading [] operator
  int &operator[](int index);

  // read only access to the elements
  int operator[](int index) const;

  // implement a swap() for IntArray
  friend void swap(IntArray &source, IntArray &destination) noexcept;

  // implement copy and swap idiom, overriding = operator
  IntArray &operator=(IntArray &source);

  // override the << operator to display the array
  friend std::ostream &operator<<(std::ostream &os, const IntArray &a);
};
