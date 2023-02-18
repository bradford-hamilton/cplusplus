#include <iostream>
#include <vector>

// Move Semantics (introduced in C++11)

int main() {
  // Sometimes when we execute code the compiler will create unnamed temporary values.
  int total {0};
  total = 100 + 200; // lvalue is total, rvalue is (100 + 200)

  // 100 + 200 is evaluated and stored in an unnamed temp value.
  // The 300 is then stored in the variable "total".
  // Then the temp value is discarded.
  // The same happens with objects as well.

  // Copy constructors doing deep copies can have a significant performance
  // bottleneck so C++11 introduced move semantics and the move constructor.
  // The move constructor moves an object rather than copy it. This is optional
  // but recommended when you have a raw pointer. 'Copy elision' - C++ may
  // optimize copying away completely (RVO - return value optimization).

  /*
    rvalue references

  - Used in moving semantics and perfect forwarding.
  - Move semantics is all about rvalue references.
  - Used by move constructor and move assignment operator
    to efficiently move an object rather than copy it.
  - rvalue reference operator is "&&"
  */

  int x{100};
  int &l_ref = x;    // lvalue reference
  l_ref = 10;        // change x to 10

  int &&r_ref = 200; // rvalue reference
  r_ref = 300;       // change r_ref to 300 (changed the temp variable)

  // Move constructor - instead of making a deep copy, we want to move the
  // resource. Simply copies the address of the resource from source to the
  // current object and nulls out the pointer in the source pointer. This is
  // very efficient.

  // Move constructor syntax:
  // Type::Type(Type &&source);
  
  class Player {
  private:
    int *data;
  public:
    Player(int d) {
      data = new int;
      *data = d;
      std::cout << "Constructor called for: " << d << std::endl;
    }

    // Copy constructor
    Player(const Player &source) {
      data = new int;
      *data = *source.data;
    }

    // Move constuctor - steal the data and null out the source pointer
    Player(Player &&source) noexcept
      : data{source.data} {
      source.data = nullptr;
      std::cout << "Move constructor - moving resource: " << *data << std::endl;
    }

    // Desctructor
    ~Player() {
      if (data != nullptr) {
        std::cout << "Destructor freeing data for: " << *data << std::endl;
      } else {
        std::cout << "Destructor freeing data for nullptr" << std::endl;
      }
      delete data;
    }

    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
  };

  std::vector<Player> my_vec;
  my_vec.push_back(Player{10});
  my_vec.push_back(Player{20});
  my_vec.push_back(Player{30});
  // No copy constructor called at all in the above 3 expressions - all moves,
  // however had you not had a move constructor, vectors will default to copying
  // in the background as they grow/shrink.

  return 0;
}
