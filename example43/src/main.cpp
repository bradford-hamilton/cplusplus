#include <iostream>
#include <string>
#include <vector>

// Class templates

// Template classes are typically completely contained in
// header file with no corresponding .cpp file
template <typename T>
class Item {
private:
  std::string name;
  T value;
public:
  Item(std::string name, T value)
    : name{name}, value{value} {}

  std::string get_name() const { return name; }

  T get_value() const { return value; }
};

template <typename T1, typename T2>
struct MyPair {
  T1 first;
  T2 second;
};

int main() {
  Item<int> item1 {"Frank", 100};
  std::cout << item1.get_name() << item1.get_value() << std::endl;

  Item<std::string> item2 {"Frank", "String value"};
  std::cout << item2.get_name() << item2.get_value() << std::endl;

  Item<Item<std::string>> item3 {"Frank", {"C++", "Professor"}};
  std::cout << item3.get_name() << std::endl;
  std::cout << item3.get_value().get_name() << std::endl;
  std::cout << item3.get_value().get_value() << std::endl;

  // ---------------------------------------------------------------
  std::vector<Item<double>> vec {};
  vec.push_back(Item<double>{"Bradford", 100});
  vec.push_back(Item<double>{"Josce", 200});
  vec.push_back(Item<double>{"Alex", 300});

  for (auto &item: vec) {
    std::cout << item.get_name() << " " << item.get_value() << std::endl;
  }

  // ---------------------------------------------------------------
  MyPair<std::string, int> p1 {"Frank", 100};
  MyPair<int, double> p2 {100, 200.56};
  
  std::cout << p1.first << ", " << p1.second << std::endl;
  std::cout << p2.first << ", " << p2.second << std::endl;

  return 0;
}
