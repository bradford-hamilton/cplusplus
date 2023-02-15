#include <iostream>
#include <vector>

using namespace std;

/*

So after all the learns on pointers, what is a reference?
  1. An alias for a variable.
  2. Must be initialized to a variable when declared.
  3. Cannot be null.
  4. Once initialized, cannot be made to reference a different variable.
  5. Very useful as function parameters.
  6. Might be helpful to think of a reference as a constant pointer
    that is automatically dereferenced.

*/

int main() {
  // --------------------------------------------------
  // General idea (think #6 from points above)
  int num {100};
  int &num_ref {num};

  cout << num << endl;     // 100
  cout << num_ref << endl; // 100

  num = 200;

  cout << num << endl;     // 200
  cout << num_ref << endl; // 200

  num_ref = 300;

  cout << num << endl;     // 300
  cout << num_ref << endl; // 300
  // --------------------------------------------------

  // Using references in range based for loops (common)
  vector<string> names {"Bradford", "Josce", "Alex"};
  
  // Print each name in names using vector methods.
  cout << names.at(0) << endl;
  cout << names.at(1) << endl;
  cout << names.at(2) << endl;
  
  // Here we use "auto &name: names" which uses the reference
  // to name vs "auto name: names" which would be modifying a copy. 
  for (auto &name: names) {
    name = "Frank";
  }

  /*
  The following however would be illegal when used with const.

  for (auto const &name: names) {
    name = "Frank"
  }
  */
  
  // Print each name in names using a range loop.
  for (auto name: names) {
    cout << name << endl;
  }

  return 0;
}
