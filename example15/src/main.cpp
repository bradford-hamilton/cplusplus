#include <iostream>
#include <string>
#include <vector>

// Classes, OOP, structs, etc.

// Classes are a blueprint from which objects are created.
// std::vector and std::string are both classes.

// Objects are created from a class. Represents a specific
// instance of that class.

/*

  Class member access:

  public: accessible everywhere
  private: accessible only by members or friends of the class
  protected: used with inheritence - update when you learn more.

  Used as seen below with "public", where everything underneath
  gets that level of access.

*/

class Player {
public:
  // attributes (can be initialized here, but will use constructor soon)
  std::string name {"Player"};
  int health {95};
  int xp {3};

  // methods
  void talk(std::string text_to_say) {
    std::cout << name << "says " << text_to_say << std::endl;
  }

  bool is_dead() {
    return health < 1;
  }
};

class Account {
public:
  // attributes (can be initialized here, but will use constructor soon)
  std::string name {"Account"};
  double balance {0.0};

  // methods
  bool deposit(double amount) {
    balance += amount;
    return true;
  }

  bool withdraw(double amount) {
    balance -= amount;
    return true;
  }
};

int main() {
  // Initializing players
  Player frank;
  Player hero;
  // Can create a pointer to a player, but do not forget
  // to clean up memory afterwords.
  Player *enemy = new Player();
  delete enemy;

  // Create a Player on the heap, don't forget to free memory.
  Player *heap_player {nullptr};
  heap_player = new Player;
  delete heap_player;

  // ---------------------------------------------------------

  // Create an array of Player
  Player players[] {frank, hero};

  // Create a vector of Player
  std::vector<Player> player_vec {frank};
  player_vec.push_back(hero);

  // ---------------------------------------------------------

  // Accounts
  Account frank_account;
  Account jim_account;

  // If you have a pointer to the account, you have to either
  // dereference first or use the member of pointer operator "->".
  // The "->" operator should be used, but good to know both.
  Account *frank_account2 = new Account();
  // Dereference by hand
  (*frank_account2).balance;
  (*frank_account2).deposit(1000.00);
  // Use the member of pointer operator.
  frank_account2->balance;
  frank_account2->deposit(1000.00);

  std::cout << frank_account2->balance << std::endl; // 2000

  // ---------------------------------------------------------
  
  // Create player without constructor and update attributes
  Player josce;
  josce.name = "Josce";
  josce.health = 100;
  josce.xp = 12;
  std::cout << josce.xp << std::endl;

  return 0;
}
