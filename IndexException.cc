#include <iostream>
#include <string>

class ArrayIndexException : public std::exception
{
private:
  std::string m_message = "\nFatal Error:\n ***Index out of bound***";

public:
  ArrayIndexException() = default;
  explicit ArrayIndexException(int index)
  {
    std::cout << m_message << "\nYou tried to access index ->"
              << index << " which is invalid\n"
              << std::endl;
  }
};
