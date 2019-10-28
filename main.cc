#include <iostream>
#include <cassert>
#include "ArrayClass.cc"

int main(int argc, char **argv)
{
  std::cout << "Creating an empty array" << std::endl;

  IntArray a{};
  std::cout << "Size of a = " << a.size() << std::endl;
  assert(a.isEmpty());

  std::cout << "---------------------------------------" << std::endl;

  std::cout << "Creating and array with 10 elements" << std::endl;
  IntArray b{10};
  std::cout << "Size of b = " << b.size() << std::endl;
  assert(!b.isEmpty());

  return 0;
}