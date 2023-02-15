#include <iostream>

using namespace std;

int main() {
  cout << "Hello, welcome to Frank's Carpet Cleaning Service" << endl;

  cout << "\nHow many small rooms would you like cleaned?" << endl;
  int small_rooms {0};
  cin >> small_rooms;

  cout << "\nHow many large rooms would you like cleaned?" << endl;  
  int large_rooms {0};
  cin >> large_rooms;

  const double price_per_small_room {25.0};
  const double price_per_large_room {35.0};
  const double tax_rate {0.06};
  const int estimated_expiry_time {30}; // days

  cout << "\nEstimate for carpet cleaning service" << endl;
  cout << "Number of small rooms: " << small_rooms << endl;
  cout << "Number of large rooms: " << large_rooms << endl;
  cout << "Price per small room: $" << price_per_small_room << endl;
  cout << "Price per large room: $" << price_per_large_room << endl;
  cout << "Cost: $" << (price_per_small_room * small_rooms) + (price_per_large_room * large_rooms) << endl;
  cout << "Tax: $" << ((price_per_small_room * small_rooms) + (price_per_large_room * large_rooms) * tax_rate) << endl;
  cout << "--------------------------------------------" << endl;

  double small_rooms_total_estimate;
  double large_rooms_total_estimate;
  small_rooms_total_estimate = (price_per_small_room * small_rooms) + (price_per_small_room * small_rooms * tax_rate);
  large_rooms_total_estimate = (price_per_large_room * large_rooms) + (price_per_large_room * large_rooms * tax_rate);

  cout << "Total estimate: $" << small_rooms_total_estimate + large_rooms_total_estimate << endl;
  cout << "This estimate is valid for " << estimated_expiry_time << " days" << endl;

  return 0;
}