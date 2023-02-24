#include <iostream>
#include <memory>
#include <vector>

/*

---------------------------------------------------------------------------------------------------

Smart Pointers
- Objects
- Can only point to heap-allocated memory and will automatically call delete when no longer needed
- CANNOT do pointer arithmatic with smart pointers!
- Defined by class templates
- Adheres to RAII pricipals
- Current C++ smart pointers:
  1. Unique Pointers (unique_ptr)
  2. Shared Pointers (shared_ptr)
  3. Weak Pointers (weak_ptr)
  4. Auto Pointers (auto_ptr) // Deprecated

---------------------------------------------------------------------------------------------------

RAII - Resouce Acquisition Is Initialized
- Common idiom or pattern used in software design based on container object lifetime
- RAII objects are allocated on the stack

- Resource Aquisition
  - Open a file
  - Allocate memory
  - Aquire a lock

- Is Initialization
  - The resource is acquired in a constructor

- Resource Relinquishing
  - Happens in the destructor
    - Close the file
    - Deallocate the memory
    - Release the lock

---------------------------------------------------------------------------------------------------

Issues with Raw Pointers
- C++ provides absolute flexibility with memory management
  - Allocation, deallocation, lifetime management
- Some potentially serious problems:
  - Unitialized (wild) pointers
  - Memory leaks
  - Dangling pointers (points to memory it thinks is valid, but is deallocated)
  - Not exception safe
- Ownership?
  - Who owns the pointer?
  - When should a pointer be deleted?

*/

// Basic test Account class for use with smart pointers below
class Account {
private:
  std::string name;
public:
  Account(std::string name_val) : name{name_val} {}
  void deposit(double amount) {
    std::cout << "desposit" << std::endl;
  }
  void withdraw(double amount) {
    std::cout << "withdraw" << std::endl;
  }
};

// Used for last example
class SomeClass {};
void my_deleter(SomeClass *raw_pointer) {
  std::cout << "custom function deleter" << std::endl;
  // Your custom deleter code ...
  delete raw_pointer;
};

int main() {
  /*
  
  - unique_ptr - simple smart pointer - very efficient!
  - unique_ptr<T>
    - Points to an object of type T on the heap
    - It is unique - there can only be one unique_ptr<T> pointing to the object on the heap.
    - Owns what it points to
    - Cannot be assigned or copied
    - CAN be moved
    - When the pointer is destoyed, what it points to is automatically destroyed.
  
  */

  {
    std::unique_ptr<int> p1 {new int {100}};
    std::cout << *p1 << std::endl; // 100
    *p1 = 200;
    std::cout << *p1 << std::endl; // 200

    // Some unique_ptr methods
    std::cout << p1.get() << std::endl; // 0x600002ad8050
    p1.reset(); // p1 now set to nullptr
    if (p1) {
      std::cout << "will not execute" << std::endl;
    }
  } // automatically deleted/cleaned up

  // Example used with a user defined class type (we don't have an Account class here)
  {
    std::unique_ptr<Account> a1 {new Account{"Larry"}};
    a1->deposit(1000);
    a1->withdraw(1000);
  }

  {
    std::vector<std::unique_ptr<int>> vec;
    std::unique_ptr<int> ptr {new int {100}};
    // vec.push_back(ptr); // Error - copy not allowed
    vec.push_back(std::move(ptr)); // OK
  } // automatically deleted/cleaned up

  // ---------------------------------------------------------------------------------------------------

  // BEST/PROPER WAY create unique pointers since C++14 is using "make_unique"
  // where we use initialization values used by the type's constructor, which
  // is way more efficient.
  {
    std::unique_ptr<int> p1 = std::make_unique<int>(100);
    std::unique_ptr<Account> a1 = std::make_unique<Account>("Curly");
    auto p2 = std::make_unique<int>(200);
  } // automatically deleted/cleaned up

  // ---------------------------------------------------------------------------------------------------

  /*
    Shared Pointers
    - Provides shared ownership of heap objects
    - shared_ptr<T>
      - Points to an object of type T on the heap
      - It is not unique - there can be many shared pointers pointing to the same object on the heap
      - Establishes shared ownership relationship
      - CAN be assigned and copied
      - CAN be moved
      - Doesn't support managing arrays by default
      - When the use count is zero, the manged object on the heap is destoyed
  */

  {
    std::shared_ptr<int> p1 {new int {100}};
    std::cout << *p1 << std::endl; // 100
    *p1 = 200;
    std::cout << *p1 << std::endl; // 200
  } // automatically deleted/cleaned up

  // BEST/PROPER WAY create shared pointers since C++14 is using "make_shared"
  // where we use initialization values used by the type's constructor, which
  // is way more efficient.

  {
    std::shared_ptr<int> p1 = std::make_shared<int>(100);
    std::shared_ptr<Account> a1 = std::make_shared<Account>("Curly");
    auto p2 = std::make_shared<int>(100);
    std::shared_ptr<int> p3;
    p3 = p1; // Copy assign OK
  } // automatically deleted/cleaned up

  // use_count method returns the number of shared pointer objects that are 
  // currently referring to the same heap object.
  {
    std::cout << "---------Use counts---------" << std::endl;
    std::shared_ptr<int> p1 = std::make_shared<int>(100);
    std::cout << p1.use_count() << std::endl; // 1
    std::shared_ptr<int> p2 {p1};             // Shared ownership
    std::cout << p1.use_count() << std::endl; // 2
    p1.reset();                               // Decrement the use_count; p1 is nulled out;
    std::cout << p1.use_count() << std::endl; // 0
    std::cout << p2.use_count() << std::endl; // 1
  } // automatically deleted/cleaned up

  // As mentioned, shared pointers can be copied, assigned, and moved
  {
    std::vector<std::shared_ptr<int>> vec;
    std::shared_ptr<int> ptr = std::make_shared<int>(100);
    vec.push_back(ptr); // OK - copy IS allowed
    std::cout << ptr.use_count() << std::endl; // 2
  } // automatically deleted/cleaned up

  // All 3 pointers point to the SAME object on the heap!
  // When the use_count becomes 0, the heap object is deallocated
  {
    std::shared_ptr<int> p1 = std::make_shared<int>(100); // use_count: 1
    std::shared_ptr<int> p2 {p1};                         // use_count: 2
    std::shared_ptr<int> p3;
    p3 = p1;                                              // use_count: 3
  } // automatically deleted/cleaned up

  // ---------------------------------------------------------------------------------------------------

  /*
    Weak Pointers
    - Provides non-owning "weak" reference
    - weak_ptr<T>
      - Points to an object of type T on the heap
      - Does not participate in owning relationship
      - Always created from a shared_ptr
      - Does NOT increment or decrement reference use count
      - Used to prevent strong reference cycles which could prevent objects from being deleted

    When A refers to B and B refers to A, the strong ownership prevents heap deallocation:

            A                                    B
    ------------------                  ------------------
    |                 |   ---------->   |                |
    |                 |                 |                |
    |  shared_ptr<B>  |                 |  shared_ptr<A> |
    |                 |                 |                |
    |                 |   <----------   |                |
    ------------------                  ------------------

  Solution - make one of the pointers non-owning or "weak". Now heap storage is deallocated properly:

            A                                    B
    ------------------                  ------------------
    |                 |   ---------->   |                |
    |                 |                 |                |
    |  shared_ptr<B>  |                 |  weak_ptr<A>   |
    |                 |                 |                |
    |                 |   <----------   |                |
    ------------------                  ------------------
  */

  class B; // Forward declaration

  class A {
  private:
    std::shared_ptr<B> b_ptr;
  public:
    void set_B(std::shared_ptr<B> &b) {
      b_ptr = b;
    }
    A() { std::cout << "A constructor" << std::endl; }
    ~A() { std::cout << "A destructor" << std::endl; }
  };

  class B {
  private:
    // Originally: "std::shared_ptr<A> a_ptr"
    std::weak_ptr<A> a_ptr;
  public:
    void set_A(std::shared_ptr<A> &a) {
      a_ptr = a;
    }
    B() { std::cout << "B constructor" << std::endl; }
    ~B() { std::cout << "B destructor" << std::endl; }
  };


  {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    a->set_B(b);
    b->set_A(a);
    // At this point (when both classes have shared pointers) when a and b go out of scope
    // they still both have a reference count of 1 so the destructors are not called and
    // memory is not freed. That is until you create a weak pointer from one to the other
    // (whichever makes sense) which we did above in class B and is why this code is valid.
  }

  // Custom deleters
  // Sometimes when we destroy a smart pointer we need more than to just destroy the object on
  // the heap. These are special use-cases. C++ smart pointers allow you to provide custom
  // deleters. There are lots of ways to acheive this - functions, lambdas, others...
  {
    // Example using a function to provide a custom deleter
    std::shared_ptr<SomeClass> ptr { new SomeClass{}, my_deleter };
  }

  {
    // Example using a lamda to provide a custom deleter
    std::shared_ptr<SomeClass> ptr (new SomeClass{},
      [] (SomeClass *ptr) {
        std::cout << "custom lambda deleter" << std::endl;
        delete ptr;
      });
  }

  return 0;
}
