#include <iostream>

int main() {
  int favorite_number;

  std::cout << "Enter your favorite number between 1 and 100" << std::endl;
  std::cin >> favorite_number;
  std::cout << "Amazing, that's my favorite number too! ";
  std::cout << "No really!! ";
  std::cout << favorite_number;
  std::cout << " is my favorite number! " << std::endl;

  return 0;
}

// OR USING ENTIRE NAMESPACE
// #include <iostream>

// using namespace std;

// int main() {
//   int favorite_number;

//   cout << "Enter your favorite number between 1 and 100" << endl;
//   cin >> favorite_number;
//   cout << "Amazing, that's my favorite number too! ";
//   cout << "No really!! ";
//   cout << favorite_number;
//   cout << " is my favorite number! " << endl;

//   return 0;
// }


// OR USE SPECIFIC PARTS OF NAMESPACE
// #include <iostream>

// using std::cout;
// using std::cin;
// using std::endl;

// int main() {
//   int favorite_number;

//   cout << "Enter your favorite number between 1 and 100" << endl;
//   cin >> favorite_number;
//   cout << "Amazing, that's my favorite number too! ";
//   cout << "No really!! ";
//   cout << favorite_number;
//   cout << " is my favorite number! " << endl;

//   return 0;
// }
