#include <iostream>

/*

Generic Programming

"Writing code that works with a variety of types as arguments,
as long as those argument types meet specific syntantic and
semantic requirements" - Bjarne Stroustrup

- Macros **BEWARE**
- Function templates
- Class templates

-------------------------------------------------------------------

Macros:
- C++ preprocessor directives
- No type information
- Simple substitution

#define MAX_SIZE 100
#define PI 3.14159

// Here would be a macro function
#define SQUARE(a) ((a)*(a))

// The problem is the preprocessor doesn't know C++, it is a blind
// substitution. You shouldn't be doing the above, instead use
// templates. The other cool part about genic programming with
// templates is that the compiler knows everything at compile time.

-------------------------------------------------------------------

*/

// Overloading, which is fine, but we've already seen this:
int max(int a, int b) {
  return (a > b) ? a : b;
};

double max(double a, double b) {
  return (a > b) ? a : b;
};

char max(char a, char b) {
  return (a > b) ? a : b;
};

// Using generic programming through a function template:
// ------ typename/class are interchangeable below
// ------ also can be a non-type template param so like template<int N>
// Remember this will not cause the compiler to generte any code
// until a user uses a specialized version of the template.
template <typename T>
T generic_max(T a, T b) {
  // Remember here we are doing a simple comparison using ">"... So if we
  // were to use this template func with a user-defined class, lets say Person,
  // we would have to ensure we've overridden the > operator, otherwise this
  // will not compile.
  return (a > b) ? a : b;
}

struct Person {
  std::string name;
  int age;
  Person(std::string name, int age)
    : name{name}, age{age} {}
  bool operator>(const Person& rhs) const {
    return this->age > rhs.age;
  }
};

// Don't need friend func here because Person is a struct which is all public
std::ostream& operator<<(std::ostream& os, const Person& p) {
  os << p.name;
  return os;
}

int main() {
  int a {5};
  int b {3};
  double a1 {5.89};
  double b1 {3.34};
  char a2 {'a'};
  char b2 {'b'};

  // -------------------------------------------------------------------
  // Overloading, which is fine, but we've already seen this:
  std::cout << max(a, b) << std::endl;
  std::cout << max(a1, b1) << std::endl;
  std::cout << max(a2, b2) << std::endl;

  // -------------------------------------------------------------------
  // Using generic programming through a function template:
  std::cout << generic_max<int>(a, b) << std::endl;
  std::cout << generic_max<double>(a1, b1) << std::endl;
  std::cout << generic_max<char>(a2, b2) << std::endl;

  // -------------------------------------------------------------------
  // And with our user-defined Person
  Person a3 {"Bradford", 33};
  Person b3 {"Josce", 28};

  std::cout << generic_max<Person>(a3, b3) << std::endl;

  return 0;
}
