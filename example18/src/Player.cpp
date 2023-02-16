#include <iostream>
#include "Player.h"

// Overloaded onstructors
Player::Player()
  : Player{"None", 0, 0} {
    std::cout << "No arg constructor" << std::endl;
};

Player::Player(std::string name_val)
  : Player{name_val, 0, 0} {
    std::cout << "One arg constructor" << std::endl;
};

Player::Player(std::string name_val, int health_val, int xp_val)
  : name{name_val}, health{health_val}, xp{xp_val} {
  std::cout << "Three arg constructor" << std::endl;
};

// Destructor
Player::~Player() {
  std::cout << "destructor called" << std::endl;
};

// Class methods
void Player::set_name(std::string name_val) {
  name = name_val;
};
