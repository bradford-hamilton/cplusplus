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

*/

int main() {
  Player empty; // Calls three arg constructor THEN no arg constructor
  Player frank{"Frank"}; // Calls three arg constructor THEN one arg constructor
  Player villain{"Villain"}; // Calls three arg constructor only

  return 0;
}
