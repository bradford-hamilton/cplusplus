#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Arrays ------------------------------------------------------------

  // Array, but telling compiler to figure out the length.
  char vowels[] {'a', 'e', 'i', 'o', 'u'};
  cout << "The first vowel is " << vowels[0] << endl;
  cout << "The last vowel is " << vowels[4] << endl;
  // Standard arrays are fixed length and type and do not do any bounds checking.
  // If we try accessing vowels[5], it will give us whatever is in that memory
  // location which in this case would be random. The array is stored at array[0].

  double high_temps[] {90.1, 89.8, 77.5, 81.6};
  cout << "The first temp is " << high_temps[0] << endl;
  high_temps[0] = 100.7;
  cout << "The first temp is now " << high_temps[0] << endl;

  int test_scores[5];
  cout << "Uninitialized array with garbage values, here is test_scores[0]: " << test_scores[0] << endl;

  // Vectors ------------------------------------------------------------
  // Elements same type, stored contiguously in memory, very efficient.
  // vector <int> scores; // Empty
  // vector <int> initialized_scores (5); // Starts with 5 elements, sets all elements to 0.
  // vector <int> initialized_scores_2 (365, 10); // Starts with 365 elements, sets them all to 10.
  vector <int> initialized_scores_3 {100, 98, 103, 95, 97}; // Initialize with values.
  cout << "Initialized scores at 0 index: " << initialized_scores_3[0] << endl;
  
  // A vector is actually a c++ object with methods, so you can do things like:
  cout << "initialized_scores_3.at(0): " << initialized_scores_3.at(0) << endl;

  // Add another score, as vectors dynamically allocate.
  initialized_scores_3.push_back(150);
  cout << "initialized_scores_3.at(0): " << initialized_scores_3.at(5) << endl;

  // Many vector methods do bounds checking, like accessing indexes through .at()
  // Because index 6 is not currently allocated, it will throw an error instead of trying
  // to give us whatever random nonsense was in that memory location like an array.

  // cout << "initialized_scores_3.at(0): " << initialized_scores_3.at(6) << endl;

  cout << "Size of initialized scores vector: " << initialized_scores_3.size() << endl;

  // 2D vector
  vector<vector<int>> two_dimensional_vector {{1, 2, 3}, {4, 5, 6}};
  cout << "First vector, first value: " << two_dimensional_vector.at(0).at(0) << endl;

  return 0;
}