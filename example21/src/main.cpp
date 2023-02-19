#include <iostream>
#include "Player.h"

/*

Static Class Members:
- A single data member that belongs to the class, not the objects.
- Useful to store class-wide information.
- Class functions can also be declared static.
- Can be called using the class name.
*/

void display_active_players() {
  std::cout
    << "Total Player objects: "
    << Player::get_num_players()
    << std::endl;
}

int main() {
  {
    display_active_players();           // Total Player objects: 0
    Player obj1 {"Josce", 50, 50};
    display_active_players();           // Total Player objects: 1
    Player obj2 {"Bradford", 100, 100};
    display_active_players();           // Total Player objects: 2
    Player obj3 {"Alex", 75, 75}; 
  }
  display_active_players();             // Total Player objects: 0

  Player *enemy = new Player{"Kate", 100, 100};
  display_active_players();             // Total Player objects: 1
  delete enemy;
  display_active_players();             // Total Player objects: 0

  return 0;
}
