#ifndef _NEAT_STRING_H_
#define _NEAT_STRING_H_

class NeatString {
private:
  char *str; // Pointer to a char[] that holds a C-style string
public:
  // No-arg constructor
  NeatString();
  // Overloaded constructor
  NeatString(const char *s);
  // Copy constructor
  NeatString(const NeatString &source);
  // Move constructor
  NeatString(NeatString &&source);

  // Operator overload for COPY assignment
  NeatString &operator=(const NeatString &rhs);

  // Operator overload for MOVE assignment
  NeatString &operator=(NeatString &&rhs);

  // Unary operator overload example
  NeatString operator-() const;
  // NeatString operator++(); // pre-increment
  // NeatString operator++(int); // post-increment
  // NeatString operator!() const;

  // Binary operator (==) overload example
  bool operator==(const NeatString &rhs);

  // Binary operator (+) overload example
  NeatString operator+(const NeatString &rhs) const;

  // Destructor
  ~NeatString();

  // Methods
  void display() const;
  int get_length() const;
  const char *get_str() const;
};

#endif // _NEAT_STRING_H_
