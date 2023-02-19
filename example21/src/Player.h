#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player {
private:
  static int num_players;
  std::string name;
  int health;
  int xp;
public:
  static int get_num_players();
  // Constructor
  Player(std::string name, int health, int xp);
  // Copy constructor
  Player(const Player &source);
  // Destructor
  ~Player();
};

#endif // _PLAYER_H_
