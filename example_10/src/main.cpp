#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function definitions must go above main or compiler
// does not know they're defined. Obviously for normal 
// programs/apps this wouldn't make sense. Looks like
// function prototypes are the proper way to solve this.
// Maybe this is also where header (".h") files come
// into play?

// Example of same file func prototypes up top with full
// definitions below main.
void say_hello();
int add_numbers(int num1, int num2);

// You can also provide default arguments for parameters
// within a function's prototype.
void say_something(string msg = "Hey there!");

// Overloading functions - define multiple prototypes and
// functions with the same name but different args/arg types.
// Must have different args, NOT just a different return type.
// Function templates may come into play here later.
void display(int n);
void display(double d);
void display(string s);
void display(vector<string> v);

// NOTE: functions with an array passed are NOT pass by value.
// Address of array will be passed, which means items can be
// modified UNLESS you make the array arg a "const".
// Ex: void print_array(const int numbers[], size_t size);

// Pass by reference example.
void add_100_to_number(int &num);

int main() {
  say_hello();
  cout << add_numbers(1, 4) << endl;

  // Called with default arg.
  say_something();
  // Called with a provided arg.
  say_something("Neato");

  display(1);
  display(1.5);
  display("overloading");
  display(vector<string>{"neat", "strings", "inside"});

  int num {100};
  add_100_to_number(num);
  cout << "Num was 100 and is now " << num << endl;

  return 0;
}

void say_hello() {
  cout << "Hello!" << endl;
}

// By default args given to a func are pass-by-value.
// Whatever changes you make to the arg does NOT effect
// the original arg passed in.
int add_numbers(int num1, int num2) {
  if (num1 < 0 || num2 < 0) {
    return 0;
  }
  return num1 + num2;
}

void say_something(string msg) {
  cout << msg << endl;
}

void display(int n) {
  cout << "printing int " << n << endl;
}

void display(double d) {
  cout << "printing double " << d << endl;
}

void display(string s) {
  cout << "printing string " << s << endl;
}

void display(vector<string> v) {
  cout << "printing items from vector: " << endl;
  for (auto item : v) {
    cout << item;
  }
  cout << endl;
}

void add_100_to_number(int &num) {
  num += 100;
}