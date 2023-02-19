#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

class Player {
private:
  std::string name;
  int health;
  int xp;
public:
  // Overloaded constructor
  Player();
  Player(std::string name_val);
  Player(std::string name_val, int health_val, int xp_val);

  // Copy constructor
  Player(const Player &source);

  // Destructor
  ~Player();

  // methods
  void set_name(std::string name_val);
  std::string get_name();
  int get_health();
  int get_xp();
};

#endif //_PLAYER_H_
