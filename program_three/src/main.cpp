#include <iostream>

using namespace std;

int main() {
  char middle_initial {'H'};
  cout << "My middle name starts with " << middle_initial << endl;

  // Same as "unsigned short exam_score {55};"
  unsigned short int exam_score {55};
  cout << "My exam score was " << exam_score << endl;

  int countries_represented {65};
  cout << "There were " << countries_represented << " countries represented in my meeting" << endl;
  
  long people_in_florida {20610000};
  cout << "There are about " << people_in_florida << " people in Florida" << endl;

  long people_on_earth {7'600'000'000};
  cout << "There are about " << people_on_earth << " people on earth" << endl;

  long long distance_to_alpha_centauri {9'461'000'000'000};
  cout << "The distance to Alpha Centauri is " << distance_to_alpha_centauri << endl;

  float car_payment {401.23};
  cout << "My car payment is " << car_payment << endl;

  double pi {3.14159};
  cout << "Pi is " << pi << endl;

  long double large_amount {2.7e120};
  cout << large_amount << " is a very big number" << endl;

  bool game_over {false};
  cout << "The value of game_over is " << game_over << endl;

  // Overflow example
  short value1 {30000};
  short value2 {1000};
  short product;
  product = value1 * value2; // Does not fit in a short and overflows to print -15488
  cout << "Product is " << product << endl;
}