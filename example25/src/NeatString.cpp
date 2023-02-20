#include <iostream>
#include <cstring>
#include "NeatString.h"

// No-args constructor
NeatString::NeatString()
  : str{nullptr} {
  str = new char[1];
  *str = '\0';
}

// Overloaded constructor
NeatString::NeatString(const char *s)
  : str{nullptr} {
  if (s == nullptr) {
    str = new char[1];
    *str = '\0';
  } else {
    str = new char[std::strlen(s)+1];
    std::strcpy(str, s);
  }
}

// Copy constructor
NeatString::NeatString(const NeatString &source)
  : str{nullptr} {
  str = new char[std::strlen(source.str)+1];
  std::strcpy(str, source.str);
  std::cout << "Copy constructor" << std::endl;
}

// Move constructor
NeatString::NeatString(NeatString &&source)
  : str{source.str} {
  source.str = nullptr;
  std::cout << "Move constructor" << std::endl;
}

// Overload COPY assignment operator
NeatString &NeatString::operator=(const NeatString &rhs) {
  std::cout << "Copy assignment" << std::endl;

  // First check for self assignment (s1 = s1) and return
  // the current object (this) if so.
  if (this == &rhs) {
    return *this;
  }

  // Deallocate storage for this->str since we are overwriting it.
  delete [] this->str;

  // Allocate storage on the heap for the deep copy.
  str = new char[std::strlen(rhs.str)+1];

  // Copy right hand side's str to the newly allocated storage.
  std::strcpy(this->str, rhs.str);

  // Return lhs by reference to allow chain assignment (s1 = s2 = s3).
  return *this;
}

// Overload MOVE assignment operator (so rhs value is an rvalue reference).
// Rhs can't be const since we'll be modifying the object when we move the data.
NeatString &NeatString::operator=(NeatString &&rhs) {
  std::cout << "Move assignment" << std::endl;

  // First check for self assignment (s1 = s1) and return
  // the current object (this) if so.
  if (this == &rhs) {
    return *this;
  }

  
  delete [] this->str; // Deallocate current storage
  this->str = rhs.str; // Steal the pointer
  rhs.str = nullptr;   // Null out the rhs object

  return *this;
}

// Overload unary operator using member method
NeatString NeatString::operator-() const {
  char *buff = new char[std::strlen(this->str)+1];
  std::strcpy(buff, this->str);

  for (size_t i = 0; i < std::strlen(buff); i++) {
    buff[i] = std::tolower(buff[i]);
  }

  NeatString temp {buff};
  delete [] buff;

  return temp;
}

// Binary operator (==) overload example
bool NeatString::operator==(const NeatString &rhs) {
  return (std::strcmp(this->str, rhs.str) == 0);
}

// Binary operator (+) overload example
NeatString NeatString::operator+(const NeatString &rhs) const {
  size_t buff_size = std::strlen(this->str) + std::strlen(rhs.str) + 1;
  char *buff = new char[buff_size];

  std::strcpy(buff, this->str);
  std::strcat(buff, rhs.str);

  NeatString temp {buff};
  delete [] buff;

  return temp;
}

// Destructor
NeatString::~NeatString() {
  delete [] str;
}

// Methods
void NeatString::display() const {
  std::cout << str << ":" << get_length() << std::endl;
}

int NeatString::get_length() const { return std::strlen(str); }

const char *NeatString::get_str() const { return str; }
