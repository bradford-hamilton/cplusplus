#include <iostream>
#include <fstream>
#include <string>

/*

Files, streams, and I/O
- fstream and ifstream are commonly used for input files
- fstream and ofstream are commonly used for output files

*/

int main() {
  // ----------------------------------------------------------------------------------
  std::string line;
  int num;
  double total;

  std::ifstream in_file {"src/neatfile.txt", std::ios::in}; // open file in input mode
  if (!in_file) {
    std::cerr << "Problem opening in_file" << std::endl;
    return 1;
  }
  std::cout << "File opened successfully" << std::endl;

  while (in_file >> line >> num >> total) {
    std::cout << std::setw(10) << std::left << line
      << std::setw(10) << num
      << std::setw(10) << total
      << std::endl;
  }

  in_file.close(); // Don't forget to close file

  // ----------------------------------------------------------------------------------

  std::string name {"Bradford"};
  int age {33};
  double weight {181.567};

  std::ofstream out_file {"src/ouput.txt", std::ios::out}; // open file in output mode
  if (!out_file) {
    std::cerr << "Problem opening out_file" << std::endl;
    return 1;
  }

  out_file << " " << name << " " << age << " " << weight;

  out_file.close(); // Don't forget to close file

  return 0;
}
