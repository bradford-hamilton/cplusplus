#include <iostream>

/*

Friends of a Class:
- A function or class that has access to private class members
  AND that function or class is NOT a member of the class it's
  accessing.
- This has been debated as something that breaks encapsulation.

- Friendship must be granted NOT taken:
  - Declared explicitly in the class that is granting friendship.
  - Declared in the function prototype with the keyword 'friend'.
- Friendship is NOT symmetric, it must be explicitly granted:
  - If A is a friend of B, B is NOT a friend of A.
- Friendship is not transitive, it must be explicitly granted:
  - If A is a friend of B AND B is a friend of C, A is NOT a friend to C.

*/

class Player {
private:
  // Tell the compiler this function has access to private members.
  friend void display_player(Player &p);

  // If we wanted to have a member function from another class get
  // access to Player privates (example here 'Account') it would look like:
  
  // friend void Account::display_players_privates(Player &p);

  // And finally we can add friendship to an entire class such that
  // anywhere/everything inside has access to all of the friend's privates:
  
  // friend class Account;

  std::string name;
  int health;
  int xp;
public:
  Player(std::string name, int health, int xp);
};

// Need to increment player count in the constructor(s) on every object.
Player::Player(std::string name, int health, int xp)
  : name{name}, health{health}, xp{xp} {}

void display_player(Player &p) {
  // Can access private class members to display.
  // Can also make changes to these private members if wanted.
  std::cout << p.name << std::endl;
  std::cout << p.health << std::endl;
  std::cout << p.xp << std::endl;
}

int main() {
  Player p {"Bradford", 100, 100};
  display_player(p);
  return 0;
}
