#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main() {
  // You should be using c++ strings which are objects, but
  // I will show some C-style strings first. A C-style string
  // is a sequence of characters, contiguous in memory,
  // implemented as an array of characters, and is terminated
  // by a null character (null).

  // You can #include <cstring> for C helper funcs for
  // copying, concatenation, comparison, searching, etc.

  char str[80];
  strcpy(str, "Hello");
  strcat(str, "World");
  cout << strlen(str);
  strcmp(str, "Some other string");

  // C++ strings
  // std namespace, contiguous in memory, dynamic size, works
  // with input and output streams, lots of useful methods,
  // can be easily converted to a C-style string if needed,
  // and they are safer.

  string s1; // Initialized to empty string - ""
  string s2 {"Frank"};
  string s3 {s2};
  string s4 {"Frank", 3}; // "Fra".
  string s5 {s3, 0, 2}; // "Fr"
  string s6 (3, 'X'); // XXX - uses constructor syntax

  // Can reassign:
  string str1;
  str1 = "Neato";
  cout << str1 << endl;

  // Concat strings
  string part1 {"C++"};
  string part2 {"is a powerful"};
  string sentence;
  sentence = part1 + " " + part2 + " language";
  cout << sentence << endl;

  // Use the C++ string methods
  cout << sentence.at(2) << endl;
  cout << sentence.length() << endl;

  return 0;
}
