#ifndef _PLAYER_H_
#define _PLAYER_H_

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
  // Destructor
  ~Player();
  // methods
  void set_name(std::string name_val);
};

#endif
