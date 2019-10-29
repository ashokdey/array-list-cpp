#ifndef ARRAY_LIST
#define ARRAY_LIST

template <typename T>

class ArrayList
{
private:
  T *m_ptr{nullptr};
  int m_size{0};

public:
  ArrayList() = default;
  explicit ArrayList(int size);

  // the copy constructor
  ArrayList(const T &source);

  // the move constructor
  ArrayList(T &&source);

  // the destructor to free memory
  ~ArrayList();

  int size() const;
  bool isEmpty() const;
  bool isValidIndex(int index) const;

  // provide element access using overloading [] operator
  T &operator[](int index);

  // read only access to the elements
  T operator[](int index) const;

  // implement a swap() for ArrayList
  friend void swap(T &source, T &destination) noexcept;

  // implement copy and swap idiom, overriding = operator
  T &operator=(T &source);

  // override the << operator to display the array
  friend std::ostream &operator<<(std::ostream &os, const T &a);
};

#endif