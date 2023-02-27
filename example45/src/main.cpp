#include <iostream>
#include <vector>

/*

----------------------------------------------------------------------------

The Standard Template Library (STL)
- A library of powerful, reusable, adaptable, generic classes and functions
- Implemented using C++ templates
- Implements common data structures and algorithms
- Huge class library, created by Alexander Stepanov in 1994
- Known time and size complexity
- Tried and tested
- Consistent, fast, type safe, and extensible
- Main 3 elements of the STL are containers, algorithms, and iterators

----------------------------------------------------------------------------

Types of containers:
- Sequence containers: array, vector, list, forward_list, deque
- Associative containers: set, multi set, map, multi map
- Container adapters: stack, queue, priority queue

----------------------------------------------------------------------------

Types of iterators:
- Input iterators: from the container to the program
- Output iterators: from the program to the container
- Forward iterators: navigate one item at a time in one direction
- Bi-directional iterators: navigate one item at a time in both directions
- Random access iterators: directly access a container item

std::vector<int> vec {1, 2, 3};

vec.begin() returns an iterator pointing to first element                      -> [1][2][3][ ]
vec.end() returns an iterator pointing to the element AFTER the last element      [1][2][3][ ] <-

This pattern is everywhere in STL.

Can set iterator vars:

std::vector<int> vec {1, 2, 3};

std::vector<int>::iterator it = vec.begin();
OR
auto it = vec.begin();

Iterators have all sorts of supported operations like:
++it
it++
it = it1
*it
it->
it == it1

----------------------------------------------------------------------------

Types of algorithms:
- About 60 algorithms in the STL
- Non-modifying
- Modifying

----------------------------------------------------------------------------

*/

int main() {
  std::vector<int> vec {1, 2, 3};
  auto it = vec.begin();

  while (it != vec.end()) {
    std::cout << *it << " ";
    ++it;
  }

  // 1, 2, 3

  std::cout << "\n---------------------------------------" << std::endl;

  for (auto it = vec.begin(); it != vec.end(); it++) {
    std::cout << *it << " ";
  }

  // 1, 2, 3

  std::cout << "\n---------------------------------------" << std::endl;

  // There are some other types of iterators as well:
  // begin() and end() - iterator
  // cbegin() and cend() - const iterator
  // rbegin() and rend() - reverse iterator
  // crbegin() and crend() - const reverse iterator

  for (auto it = vec.rbegin(); it != vec.rend(); it++) {
    std::cout << *it << " ";
  }

  // 3, 2, 1
  // Notice how this is a reverse iterator and when we increment it (it++) we traverse in reverse

  std::cout << "\n---------------------------------------" << std::endl;

  return 0;
}
