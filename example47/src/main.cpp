#include <iostream>
#include <vector>

/*

Enumumerations (enums)
- A user defined type that models a set of constant integral values
  Ex:
  - Days of a week
  - Months of the year
  - Suits in a deck of cards
  - States of a system
  - Directions on a compass

Unscoped structure:

enum-key enum-name : enumerator-type {};

Scoped structure:

enum class/struct enum-name : enumerator-type {};

*/

int main() {
  // -------------------------------------- Unscoped Enumerations --------------------------------------

  // Implicit initialization
  //     0     1     2
  enum {Red, Green, Blue};

  // Explicit initialization
  enum {Left = 1, Middle = 2, Right = 3};

  // Explicir/Implicit initialization
  enum {One = 1, Two, Three};

  std::cout << Red << std::endl;
  std::cout << sizeof(Red) << std::endl; // 4

  // --------------------------------------------------------
  enum Compass: uint8_t {
    North = 0,
    South,
    East,
    West
  };
  std::cout << sizeof(North) << std::endl; // 1

  // --------------------------------------------------------
  // Using a switch statement with unscoped enumerations uses jump tables
  // under the hood and provides equal access time for each branch of the
  // switch.

  // -------------------------------------- Scoped Enumerations --------------------------------------
  // class and struct are interchangable here
  enum class Days {
    Monday = 0,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday,
  };
  // Must now acess with Days::Monday vs just Monday.

  return 0;
}
