#include <iostream>
#include <cassert>
#include "../classes/ArrayList.cpp"

int main(int argc, char **argv)
{
  try
  {
    std::cout << "Creating an empty array" << std::endl;

    ArrayList<int> a{};
    std::cout << "Size of a = " << a.size() << std::endl;
    assert(a.isEmpty());

    std::cout << "---------------------------------------" << std::endl;

    std::cout << "Creating and array with 10 elements" << std::endl;
    ArrayList<int> b{10};

    std::cout << "Size of b = " << b.size() << std::endl;
    assert(!b.isEmpty());

    // fill values in b
    for (int i = 0; i < b.size(); i += 1)
    {
      b[i] = i * 10 + 1;
    }

    std::cout << "Display the items of b: " << std::endl;
    std::cout << b << std::endl;

    std::cout << "b[1] = " << b[1] << std::endl;

    std::cout << "\n--------------------------------" << std::endl;
    std::cout << "Creating a copy of b :" << std::endl;
    // create a copy of b in c
    ArrayList<int> c = b;

    std::cout << "Display the items of c :" << std::endl;
    std::cout << c << std::endl;

    std::cout << "\nTring to access c[13] = " << c[13] << std::endl;

    return 0;
  }
  catch (const std::exception &e)
  {
    std::cout << "\n\n***************************************" << std::endl;
    std::cout << "Sorry, the program crashed :(" << std::endl;
    std::cout << "--Error Report--" << std::endl;
    std::cerr << e.what() << std::endl;
    return -1;
  }
}