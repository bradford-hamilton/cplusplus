#include <iostream>
#include <string>
#include <vector>
#include "Array.h"

// Create a generic array template class
int main() {
  Array<int, 4> nums {1024};

  std::cout << "The size of nums is: " << nums.get_size() << std::endl;
  std::cout << "nums[0]: " << nums[0] << std::endl; // 1024
  std::cout << "nums[1]: " << nums[1] << std::endl; // 1024
  std::cout << "nums[2]: " << nums[2] << std::endl; // 1024
  std::cout << "nums[3]: " << nums[3] << std::endl; // 1024

  nums.fill(2048);

  std::cout << "The size of nums is: " << nums.get_size() << std::endl;
  std::cout << "nums[0]: " << nums[0] << std::endl; // 2048
  std::cout << "nums[1]: " << nums[1] << std::endl; // 2048
  std::cout << "nums[2]: " << nums[2] << std::endl; // 2048
  std::cout << "nums[3]: " << nums[3] << std::endl; // 2048

  return 0;
}
