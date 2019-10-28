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
    m_message += "\nYou tried to access index ->" + std::to_string(index) + " which is invalid\n";
  }

  virtual const char *what() const noexcept
  {
    return m_message.c_str();
  }
};
