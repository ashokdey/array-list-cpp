#include <iostream>
#include <cassert>
#include "ArraySafe.cc"

int main(int argc, char **argv)
{
  try
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

    b[1] = 30;

    std::cout << "b[1] = " << b[1] << std::endl;
    std::cout << "Tring to access b[13] = " << b[13] << std::endl;

    return 0;
  }
  catch (const std::exception &e)
  {
    std::cout << "\n***************************************" << std::endl;
    std::cout << "Sorry, the program crashed :(" << std::endl;
    std::cout << "--Error Report--" << std::endl;
    std::cerr << e.what() << std::endl;
    return -1;
  }
}