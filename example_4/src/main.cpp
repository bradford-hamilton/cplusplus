#include <iostream>
#include <climits>

using namespace std;

int main () {
  cout << "-----------" << endl;
  cout << "sizeof info" << endl;
  cout << "-----------" << endl;

  cout << "char: " << sizeof(char) << " bytes" << endl;
  cout << "int: " << sizeof(int) << " bytes" << endl;
  cout << "unsigned int: " << sizeof(unsigned int) << " bytes" << endl;
  cout << "short: " << sizeof(short) << " bytes" << endl;
  cout << "long: " << sizeof(long) << " bytes" << endl;
  cout << "long long: " << sizeof(long long) << " bytes" << endl;
  cout << "float: " << sizeof(float) << " bytes" << endl;
  cout << "double: " << sizeof(double) << " bytes" << endl;
  cout << "long double: " << sizeof(long double) << " bytes" << endl;

  // Values taken from climits
  cout << "-----------" << endl;
  cout << "climits info" << endl;
  cout << "-----------" << endl;

  cout << "Minimum values: " << endl;
  cout << "char: " << CHAR_MIN << endl;
  cout << "int: " << INT_MIN << endl;
  cout << "short: " << SHRT_MIN << endl;
  cout << "long: " << LONG_MIN << endl;
  cout << "long long: " << LLONG_MIN << endl;

  cout << "Maximum values: " << endl;
  cout << "char: " << CHAR_MAX << endl;
  cout << "int: " << INT_MAX << endl;
  cout << "short: " << SHRT_MAX << endl;
  cout << "long: " << LONG_MAX << endl;
  cout << "long long: " << LLONG_MAX << endl;

  // You can use sizeof for variables as well.
  int some_number {23456};
  cout << "the size of some_number is " << sizeof(some_number) << " bytes" << endl;
}