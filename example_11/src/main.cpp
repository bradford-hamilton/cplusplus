#include <iostream>
#include <vector>

using namespace std;

// Pointers:

// A pointer is a variable which is an address.
// Another variable or function can be at that address.
// They have a type and to use the data the pointer is
// pointing at, you must know its type.

// Inside functions, pointers can be used to access data
// that are defined outside the function.

// Pointers can be used to operate on arrays very efficiently.

// We can allocate memory dynamically on the heap or free store.
// This memory doesn't even have a variable name and the only
// way to access it is via a pointer.

// With OO pointers are how polymorphism works.

// Really useful in embedded and systems applications.

// "&" - the address operator - unary operator - operand cannot be const or expression.
int main() {
  int num {10};
  cout << "Value of num is: " << num << endl;
  cout << "Size of of num is: " << sizeof(num) << endl;
  cout << "Address of num is: " << &num << endl;
  
  // Important to initialize pointers to point "nowhere" vs "anywhere".
  // nullptr introduced in C++11 represents 0 address.
  string *my_str_ptr {nullptr};
  cout << "value of my_str_ptr: " << my_str_ptr << endl; // 0x0
  cout << "address of my_str_ptr: " << &my_str_ptr << endl; // 0x16b14df10
  
  int score {10};
  int score2 {20};
  int *score_ptr {nullptr};
  score_ptr = &score; 
  score_ptr = &score2; // Pointers are variables and as such can be reassigned.
  cout << "The address of score2 and the value of the pointer should be the same. Address of score2: "
    << &score2
    << " and value of score_ptr: "
    << score_ptr
    << endl;
  /*
  double high_temp {100.7};
  score_ptr = &high_temp; - "incompatible pointer types assigning to 'int *' from 'double *'"
  */

  // Dereferencing a pointer and updating original value pointed at it by updating the pointer:
  int test_score {100};
  int *test_score_ptr {&test_score};

  cout << "test_score: " << test_score << endl;
  cout << "*test_score_ptr: " << *test_score_ptr << endl;
  *test_score_ptr = 200;
  cout << "test_score: " << test_score << endl;
  cout << "*test_score_ptr: " << *test_score_ptr << endl;

  // Example of vector pointer:
  vector<string> people {"Bradford", "Josce", "Alex"};
  vector<string> *people_ptr {&people};
  cout << "person at index 1 with people.at(1): " << people.at(1) << endl;
  cout << "person at index 1 with (*people_ptr).at(1): " << (*people_ptr).at(1) << endl;
  // Loop over the derefernced people_ptr as apposed to looping over "people".
  for (auto person : *people_ptr) {
    cout << person << endl;
  }

  // Allocating storage from the heap at runtime - remember you must also
  // free this storage or it can lead to memory leaks.
  // We can use pointers to access newly allocated heap storage.
  int *int_ptr {nullptr};
  int_ptr = new int; // Allocate an integer on the heap.
  cout << int_ptr << endl; // Address of "new int" - 0x6000000c8040
  cout << *int_ptr << endl; // 0 - Garbage integer since we never set it
  *int_ptr = 437;
  cout << *int_ptr << endl; // 437 as we are dereferencing what int_ptr points to, which is now 437.
  delete int_ptr; // Frees the allocated heap storage.

  // Dynamic memory allocation
  int *array_ptr {nullptr};
  int size {64};
  array_ptr = new int[size]; // Allocate array on heap
  delete [] array_ptr;

  // Since there is no variable for the memory, don't lose the ptr or you've
  // lost the data. Also don't forget to always clean up and free the memory.
  int *my_int_ptr {nullptr};
  my_int_ptr = new int; // Allocated int to heap and point at it with my_int_ptr
  delete my_int_ptr;

  // Allocate 120 continuous doubles on the heap
  size_t num_of_doubles {120};
  double *temp_ptr {nullptr};
  temp_ptr = new double[num_of_doubles];
  cout << "temp_ptr: " << temp_ptr << endl;
  delete [] temp_ptr;

  // The value of an array name is the address of the first element in the array.
  // The value of a pointer variable is an address.
  // If the pointer points to the same data type as the array element, then
  // the pointer and array name can be used interchangeably (almost).
  int new_scores[] {100, 95, 83};
  cout << new_scores << endl; // 0x16b105eb0
  cout << *new_scores << endl; // 100
  int *new_scores_ptr {new_scores};
  cout << new_scores_ptr << endl; // 0x16b105eb0
  cout << *new_scores_ptr << endl; // 100

  // This means we can use array subscripting on the pointer as well.

  // Array subscript notation ---------------------------------------
  cout << new_scores[0] << endl; // 100
  cout << new_scores[1] << endl; // 95
  cout << new_scores[2] << endl; // 83

  // Pointer subscript notation: ------------------------------------
  cout << new_scores_ptr[1] << endl; // 100
  cout << new_scores_ptr[2] << endl; // 95
  cout << new_scores_ptr[0] << endl; // 83

  // Using pointers in expressions with some basic pointer arithmetic.

  // Pointer offset notation: ---------------------------------------
  cout << new_scores_ptr << endl;       // 0x16d81deb0
  cout << (new_scores_ptr + 1) << endl; // 0x16d81deb4
  cout << (new_scores_ptr + 2) << endl; // 0x16d81deb8
  // The new_scores_ptr is an address (as we aren't dereferencing it), so notice
  // the math is happening to the pointer's address. Each time it is increased
  // by "1" -> the address moves up by 4. This is because each int in new_scores
  // takes up 4 bytes in memory, so essentially you are asking for the next 
  // element's address.

  // As you would expect, you can access the array's elements by dereferencing
  // the data at the address you have from the pointer arithmetic.
  cout << *new_scores_ptr << endl;       // 100
  cout << *(new_scores_ptr + 1) << endl; // 95
  cout << *(new_scores_ptr + 2) << endl; // 83

  // Array offset notation: -----------------------------------------
  cout << *new_scores << endl;       // 100
  cout << *(new_scores + 1) << endl; // 95
  cout << *(new_scores + 2) << endl; // 83

  // Pointer arithmetic
  // Pointers can be used in assignment expressions, arithmetic expressions,
  // and comparison expressions. Pointer arithmetic only makes sense with
  // raw arrays.
  
  // So the following increments a pointer to point to the next array element.
  // Increment/decrement will do so in chunks of whatever the underlying type is.
  // int_ptr++ will increment by 4 (for ints here).
  string s1 {"Frank"};
  string s2 {"Frank"};
  string *p1 {&s1};
  string *p2 {&s2};
  string *p3 {&s1};
  // For comparison remember we're comparing pointers as is so we're comparing
  // addresses, NOT to what the data is they point to.
  cout << boolalpha;
  cout << (p1 == p2) << endl; // false
  cout << (p1 == p3) << endl; // true
  // Unless of course we dereference them:
  cout << (*p1 == *p2) << endl; // true
  cout << (*p1 == *p3) << endl; // true

  // Finding distance between elements in array (C-style string here).
  char name[] {"Frank"};
  char *char_ptr1 {nullptr};
  char *char_ptr2 {nullptr};
  char_ptr1 = &name[0]; // F
  char_ptr2 = &name[3]; // n
  cout << "In the string "
    << name
    << ", "
    << *char_ptr2
    << " is "
    << (char_ptr2 - char_ptr1)
    << " characters away from "
    << *char_ptr1
    << endl;

  // Using const and pointers
  // There are several ways to qualify pointers:
  // 1. Pointers to constants
  // 2. Constant pointers.
  // 3. Constant pointers to constants.

  return 0;
}
