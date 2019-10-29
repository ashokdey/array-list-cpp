#pragma once
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
  ArrayList(const ArrayList &source);

  // the move constructor
  ArrayList(ArrayList &&source);

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
  friend void swap(ArrayList<T> &source, ArrayList<T> &destination) noexcept;

  // implement copy and swap idiom, overriding = operator
  ArrayList<T> &operator=(ArrayList<T> &source);

  // override the << operator to display the array
  template <typename U> //[https://stackoverflow.com/questions/4660123/overloading-friend-operator-for-template-class]
  friend std::ostream &operator<<(std::ostream &os, const ArrayList<U> &a);
};
