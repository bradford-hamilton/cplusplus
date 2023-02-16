#include <iostream>

/*
Constructors are:
  - Special member method
  - Invoked during object creation
  - Useful for initialization
  - Same name as the class (think old solidity)
  - No return type is specified
  - Can be overloaded

Destructors are:
  - Special member method
  - Same name as the class preceded with a tilde "~"
  - Invoked automatically when the object is destroyed
  - No return type and no parameters
  - Only 1 destructor is allowed per class and NO overloading
  - Useful for releasing memory and other resources
  - When a variable goes out of scope, destructor called automatically
*/

// Player class with overloaded constructor and a destructor all
// in same file here for simplicity's sake. This is showing both
// overloaded constructor calls as well as a destructor call. Notice
// destructor calls happen in the opposite direction from recently
// defined -> oldest defined when called after leaving scope.
class Player {

private:
  std::string name;
  int health;
  int xp;

public:
  // Overloaded constructor
  Player() {
    std::cout << "No args constructor called" << std::endl;
  };
  Player(std::string name) {
    std::cout << "name arg constructor called" << std::endl;
  };
  Player(std::string name, int health, int xp) {
    std::cout << "name, health, and xp constructor called" << std::endl;
  };
  // Destructor
  ~Player() {
    std::cout << name << " destructor called" << std::endl;
  };
  // methods
  void set_name(std::string name_val) {
    name = name_val;
  }
};

int main() {
  // Blocks for showing the construction of an object followed by its
  // destruction after leaving scope.
  
  {
    Player slayer;
    slayer.set_name("Slayer");
  }

  {
    Player frank;
    frank.set_name("Frank");
    Player hero("Hero");
    hero.set_name("Hero");
    Player villain("Villain", 100, 12);
    villain.set_name("Villain");
  } // Destructed villain, hero, frank in that order after losing scope here

  {
    Player *enemy = new Player;
    enemy->set_name("Enemy");

    Player *level_boss = new Player("Level Boss");
    level_boss->set_name("Level Boss");

    delete enemy;
    delete level_boss;
  }

  return 0;
}
