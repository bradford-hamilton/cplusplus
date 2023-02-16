#include <iostream>
#include "Player.h"

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

A default constructor is created when you do not provide one. Say you have
the Player class from below, but with no defined a constructor, you can still
call and use the default one. Below shows default constructor calls (again) in
the case that "Player" does not have one defined.

Player frank;
Player *mary = new Player;
delete mary;

Instead though you should always have your own user-defined no-args constrcutor
like the following:

class Account {
private:
  std::string name;
  double balance;
public:
  Account() {
    name = "None";
    balance = 0.0;
  }
};

Last note though is that if you do have a contructor defined, lets say just one,
and it is asking for arguments (so it isn't a "default constructor") C++ will then
no longer provide that default and objects will only be able to be created from
that class through the args-constructor.

*/

// This is showing both overloaded constructor calls as well as a
// destructor call. Notice destructor calls happen in the opposite
// direction from recently defined -> oldest defined when called
// after leaving scope.

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
