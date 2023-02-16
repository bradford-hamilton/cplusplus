#include <iostream>
#include "Player.h"

// Overloaded onstructors
Player::Player() {
  std::cout << "No args constructor called" << std::endl;
};

Player::Player(std::string name) {
  std::cout << "name arg constructor called" << std::endl;
};

Player::Player(std::string name, int health, int xp) {
  std::cout << "name, health, and xp constructor called" << std::endl;
};

// Destructor
Player::~Player() {
  std::cout << name << " destructor called" << std::endl;
};

// Class methods
void Player::set_name(std::string name_val) {
  name = name_val;
};
