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
  std::cout << std::boolalpha;
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

  // -----------------------------------------------------------------------------

  NeatString bradford {"Bradford"};
  NeatString josce {"JOSCE"};
  NeatString another_bradford {"Bradford"};

  bradford.display(); // Bradford:8
  josce.display();    // JOSCE:5

  NeatString lower_jo = -josce;
  lower_jo.display(); // josce:5

  std::cout << (bradford == josce) << std::endl; // false
  std::cout << (bradford == another_bradford) << std::endl; // true

  NeatString str1 {"Strings are"};
  NeatString str2 {" neat"};
  NeatString brad_n_jo = str1 + str2;

  brad_n_jo.display(); // Strings are neat:16

  std::cout << (str1+str2).get_str() << std::endl; // Strings are neat

  // -----------------------------------------------------------------------------

  NeatString len5_str {"abcdef"};
  NeatString len7_str {"abcdefgh"};
  std::cout << (len5_str > len7_str) << std::endl; // false
  std::cout << (len7_str > len5_str) << std::endl; // true

  // -----------------------------------------------------------------------------

  NeatString its_for_the_stream {"better be in stream"};
  std::cout << its_for_the_stream << std::endl; // better be in stream
  std::cout << "Enter a string:" << std::endl;
  NeatString neat_strings_in;
  std::cin >> neat_strings_in;
  std::cout << neat_strings_in << std::endl;

  return 0;
}
