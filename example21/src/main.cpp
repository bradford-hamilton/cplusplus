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
  std::cout << Player::get_num_players() << std::endl;
}

int main() {

  {
    display_active_players();         // 0
    Player obj1 {"Josce", 0, 0};
    display_active_players();         // 1
    Player obj2 {"Bradford", 0, 0};
    display_active_players();         // 2
    Player obj3 {"Bradford", 0, 0}; 
  }

  display_active_players();           // 0

  return 0;
}
