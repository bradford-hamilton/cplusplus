#include <iostream>

/*

Structs vs. classes
- In addition to classes we can define structs.
- Struct comes from C.
- Essentially the same as a class but members are public by default.
- Classes (as seen below) default to private if not specified.

  -----------------------------------------------------------------------

  class Person {
    std::string name;
    std::string get_name();
  };

  Person p;
  p.name = "Frank";                         // compiler error - private
  std::cout << p.get_name() << std::endl;   // compiler error - private

  -----------------------------------------------------------------------

  struct Person {
    std::string name;
    std::string get_name();
  };

  Person p;
  p.name = "Frank";                         // OK - public
  std::cout << p.get_name() << std::endl;   // OK - public

  -----------------------------------------------------------------------

  So if the only real difference is public/private, when does it make sense
  to use a class vs. a struct?

  Struct:
    - For passive objects with public access
    - Don't declare methods in struct

  Class:
    - Use class for active objects with private access
    - Implement getters and setters as needed
    - Implement member methods as needed

*/

int main() {
  struct Person {
    std::string name;
  };

  Person p;
  p.name = "Josce";

  std::cout << p.name << std::endl;

  return 0;
}
