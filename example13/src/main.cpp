#include <iostream>

using namespace std;

// l-values are values that have names and are
// addressable (and modifiable if not a constant).

// r-values are non-addressable and non-assignable.
// So essentially a value that isn't an l-value - on
// the right-hand side of an assignment expression,
// a literal, a temporary which is intended to be
// non-modifiable.

int square (int &n);

int main() {
  // r-values can be assigned to l-values explicitly
  int x {100};
  int y {0};

  y = 100;    // r-value 100 assigned to l-value y
  x = x + y;  // r-value (x + y) assigned to l-value x

  // --------------------------------------------------
  
  // The references we've used are l-value references
  // because we're referencing l-values.
  int z {100};
  int &ref_z = z; // ref_z is a reference to an l-value
  ref_z = 1000; // legal

  /*
    The following throws a compiler error, as 100 is an r-value

    int &ref_new_z = 100;

    Compiler: "initial value of reference to non-const must be an lvalue"
  */

  // The same idea for when we pass by reference:
  
  int num {10};
  square(num); // Legal
  // square(5); - "initial value of reference to non-const must be an lvalue"

  return 0;
}

int square (int &n) {
  return n * n;
}
