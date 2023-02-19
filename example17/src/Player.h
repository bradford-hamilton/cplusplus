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
  Player(std::string name);
  Player(std::string name, int health, int xp);
  // Destructor
  ~Player();
  // methods
  void set_name(std::string name_val);
};

#endif // _PLAYER_H_
