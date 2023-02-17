#include <iostream>
#include "Player.h"

// So far we've set all data member values in the constructor body. There
// is another approach called "Constructor Initialization Lists".
// - They are more efficient
// - They immediately follow the parameter list
// - They initialize the data members as the object is created!
// - The order of initialization is the order of the declaration of the class.

/*
  Previous way:

  Player::Player() {
    name = "None";
    health = 0;
    xp = 0;
  }

  Better way:

  Player::Player()
    : name{"None"}, health{0}, xp{0} {
      ... you can still write code here in the body
      ... and we know the data is already initialized
  }

  So one where we are taking values from the caller to intitialize with list:

  Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {
      ... you can still write code here in the body
      ... and we know the data is already initialized
  }
*/

// Often the code in constructors is very similar and so C++ allows
// for delegating constructors:
// - Code for one constructor can call another in the initialization list
// - Avoids duplicating code

/*

Player::Player(std::string name_val, int health_val, int xp_val)
  : name{name_val}, health{health_val}, xp{xp_val} {}

Player::Player()
  : Player{"None", 0, 0} {}

Player::Player(std::string name_val)
  : Player{name_val, 0, 0} {}

-----------------------------------------------------------------------------------

When it makes sense, you can use default params in the constructor which can
simplify code quite a bit. In this world you put the default params in the
header file class definition and just use one initialization list constructor.

-----------------------------------------------------------------------------------

Next is the "Copy Constructor" - C++ will provide its best default copy constructor
for when a copy of an object is needed, unless you provide a user-defined one.
- Passing object by value as a parameter
- Returning an object from a function by value
- Constructing one object based on another of the same class

Best practices:
- Provide a copy constructor when your class has raw pointer members
- Provide the copy constructor with a const reference parameter
- Use STL classes as they already provide copy constructors
- Avoid using raw pointer data members if possible

Type::Type(const Type &source);

so

Player::Player(const Player &source);

-----------------------------------------------------------------------------------

*/

// Quick function for showing the player copy constructor in action.
void display_player(Player p) {
  std::cout << p.get_name() << std::endl;
  std::cout << p.get_health() << std::endl;
  std::cout << p.get_xp() << std::endl;
}

int main() {
  Player empty; // Calls three arg constructor THEN no arg constructor
  Player frank{"Frank"}; // Calls three arg constructor THEN one arg constructor
  Player villain{"Villain"}; // Calls three arg constructor only

  // Copy constructor example
  Player alex{"Alex", 0, 0};
  display_player(alex); // Copy constructor called

  // FIVE deconstructions happened after end of program here - the obvious
  // four from above, but then also when "display_player" finishes executing
  // it also does another to destroy that copy.

  return 0;
}

// Major issues will come from doing a shallow copy on a class with a
// pointer member. This makes sense in the chain of events - A copy is made
// from &source and the pointer value is copied. Now we have 2 objects that
// with a member pointing to the same area of memory. When the copy goes out
// of scope (like in "display_player"), the destructor is then called which
// will delete the memory! Now the class that was copied from points to
// released memory. Or something close to this :)

// In your user-provided copy constructor you always want to use a deep copy
// when you have a raw pointer as a class member. This way each copy will have
// a pointer to unique storage on the heap.

class Deep {
private:
  int *data;
public:
  Deep(int d);
  Deep (const Deep &source);
  ~Deep();
};

Deep::Deep(int d) {
  data = new int;
  *data = d;
}

Deep::~Deep() {
  delete data;
  std::cout << "constructor freeing memory" << std::endl;
}

// Create new heap storage and assign the data that was _pointed to_
// from source member to this new heap location.
Deep::Deep(const Deep &source) : Deep{*source.data} {
  data = new int;
  *data = *source.data;
  std::cout << "deep copy constructor" << std::endl;
}
