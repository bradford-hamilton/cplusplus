#include <iostream>

using namespace std;

int main() {
  bool neato {true};

  if (neato) {
    cout << "If" << endl;
  } else {
    cout << "Else" << endl;
  }

  neato ? cout << "Ternary true\n" : cout << "Ternary false\n";

  enum Color { red, green, blue };

  Color given_color {green};

  switch (given_color) {
    case red:
      cout << "The given color is red" << endl;
      break;
    case green:
      cout << "The given color is green" << endl;
      break;
    case blue:
      cout << "The given color is blue" << endl;
      break;
    default:
      cout << "Illegal";
  }

  return 0;
}