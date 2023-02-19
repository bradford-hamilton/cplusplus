#include <iostream>
#include "Player.h"

// Initialize static var num_players to 0. Typically happens here
// and yes it does look different than what we've seen so far.
int Player::num_players = 0;

// Since this func is static, it only has access to static data members.
int Player::get_num_players() {
  return num_players;
}

// Need to increment player count in the constructor(s) on every object.
Player::Player(std::string name, int health, int xp)
  : name{name}, health{health}, xp{xp} {
    num_players++;
}

// Copy constructor
Player::Player(const Player &source) 
  : Player{source.name, source.health, source.xp} {
}

Player::~Player() {
  num_players--;
}
