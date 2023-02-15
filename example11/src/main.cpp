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

// With OOP, pointers are how polymorphism works.
// Really useful in embedded and systems applications.

// Prototypes
void double_data(int *int_ptr);
// Overloading
void display(const vector<string> *const vec);
void display(int *array, int sentinel);
// Returning a pointer
int *largest_int(int *int_ptr1, int *int_ptr2);
// Returning dynamically allocated memory
int *create_array(size_t size, int init_value = 0);

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
  cout << new_scores_ptr[0] << endl; // 100
  cout << new_scores_ptr[1] << endl; // 95
  cout << new_scores_ptr[2] << endl; // 83

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
  // addresses, not to what the data is they point to.
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

  // Pass by reference with pointers
  int value {100};
  int *another_int_ptr {nullptr};
  cout << value << endl;
  double_data(&value);
  cout << value << endl;
  another_int_ptr = &value;
  double_data(another_int_ptr);
  cout << value << endl;

  // Pass by reference with pointers on a constant vector.
  const vector<string> names {"Bradford", "Josce", "Alex"};
  display(&names);

  // Looping over dereferenced array, printing, and incrementing.
  int some_nums[] {12, 513, 64, 903, -1};
  display(some_nums, -1);

  // Func that returns a pointer
  int a {5};
  int b {3};
  int *ptr_to_largest_int {nullptr};
  ptr_to_largest_int = largest_int(&a, &b);
  cout << ptr_to_largest_int << endl;
  cout << *ptr_to_largest_int << endl;

  // Returning dynamically allocated memory
  int *my_neat_array {nullptr};
  my_neat_array = create_array(10, 2);
  cout << my_neat_array << endl;
  cout << *(my_neat_array + 1) << endl;
  cout << *(my_neat_array + 5) << endl;
  cout << *(my_neat_array + 9) << endl;
  delete [] my_neat_array;

  return 0;
}

void double_data(int *int_ptr) {
  *int_ptr *= 2;
}

// Takes a constant pointer that points to a constant vector meaning
// neither can be reassigned - compiler would complain.
void display(const vector<string> *const vec) {
  for (auto item : *vec) {
    cout << item << endl;
  }
}

void display(int *array, int sentinel) {
  while (*array != sentinel) {
    cout << *array++ << endl;
  }
}

int *largest_int(int *int_ptr1, int *int_ptr2) {
  if (*int_ptr1 > *int_ptr2) {
    return int_ptr1;
  }
  return int_ptr2;
}

int *create_array(size_t size, int init_value) {
  int *new_storage {nullptr};
  new_storage = new int[size];

  for (size_t i {0}; i < size; i++) {
    *(new_storage + i) = init_value;
  }

  return new_storage;
}

/*
Do not return a pointer to a local variable from within the function scope.
The variable was on the stack and the function terminates, so the variable
has ended its lifetime.

int *dont_do_this() {
  int size {};
  ...
  return &size;
}

int *or_this() {
  int size {};
  int *int_ptr {&size};
  ...
  return int_ptr;
}
*/

/*
Some pointer pitfalls

1. Uninitialized pointers
  // This points anywhere vs. nowhere
  int *int_ptr;

2. Dangling pointers
  // Pointer that is pointing to released memory.
  // Example: 2 pointers point to the same data -
    // one pointer releases the data with delete -
    // the other pointer accesses the release data.
  // Example: Pointer that points to memory that is invalid
    // Example: We saw this when returning a pointer to function's local variable.
3. Not checking if new failed to allocate memory
  // If 'new' fails an exception is thrown
    // We can use exception handling here.
4. Leaking memory
  // Forgetting to release allocated memory with delete
  // If you lose your pointer to the storage allocated on the heap
  // you have no way of accessing that storage again.
  // The memory is orphaned or leaked.
  // One of the most common pointer problems.
*/