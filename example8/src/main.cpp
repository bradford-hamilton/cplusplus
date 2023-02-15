#include <iostream>
#include <vector>

using namespace std;

int main() {
  for (int i {1}; i <= 10; i++) {
    cout << i << endl;
  }

  for (int i {1}, j {3}; i <= 5; i++, j++) {
    cout << "i: " << i << endl;
    cout << "j: " << j << endl;
  }

  // Here we use a vector method .size() which returns an unsigned
  // int (makes sense, as vectors would never have signed int as a
  // size) - so we use unsigned int for variable.
  vector<int> nums {10, 20, 30, 40, 50};
  for (unsigned i {0}; i < nums.size(); i++) {
    cout << nums[i] << endl;
  }

  // Range based for loop.
  int scores[]{100, 90, 97};
  for (int score : scores) { // OR for more complex collections consider "auto" --- for (auto score : scores) {
    cout << score << endl;
  }

  // Can provide collection right in the loop if needed.
  for (auto temp : {60.2, 13.4, 47.5}) {
    cout << temp << endl;
  }

  for (auto ch : "Neat message") {
    cout << ch << endl;
  }

  // There are also while and do while loops.
  // You can use break and continue within loops.

  return 0;
}