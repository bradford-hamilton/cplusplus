#include <iostream>
#include "NeatString.h"

/*

Operator Overloading:
- Overloading the assignment operator (=) with copy/move semantics.
- Overloading operators as member functions.
- Overloading operators as global functions.
- Overloading stream insertion (<<) and extraction (>>) operators.
- Must be explicitly defined (except a default from compiler for assignment)

*/

int main() {
  // Copy assignment operator (=)
  // C++ provides a default assignment operator used for assigning
  // one object to another:

  // NeatString s1 {"Frank"};
  // NeatString s2 = s1;      // Initialization NOT assignment, same as NeatString s2 {s1};
  // s2 = s1;                 // Assignment

  // Default is memberwise assignment (shallow copy). If we have
  // raw pointer data member we MUST deep copy.
  // Operator overload syntax:
  // Type &Type::operator=(const Type &rhs);

  // -----------------------------------------------------------------------------

  NeatString a {"Hello"}; // Overloaded constructor
  NeatString b;           // No-args constructor
  b = a;                  // COPY assignment: b.operator=(a)
  b = "This is a test";   // MOVE assignment: b.operator=("This is a test")

  // -----------------------------------------------------------------------------

  // Move assignment operator (=)
  // - C++ will use the copy assignment operator if no move assignment operator is defined.
  // - If we have a raw pointer member we should overload the move assignment operator for efficiency.

  NeatString s1;            // No-args constructor
  s1 = NeatString{"Neato"}; // Overloaded constructor then MOVE operator= called
  s1 = "Frank";             // Overloaded constructor then MOVE operator= called

  return 0;
}
