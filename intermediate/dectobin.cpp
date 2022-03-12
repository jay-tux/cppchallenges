#include <iostream>

int main(int argc, const char **argv) {
  if (argc != 2) {
    std::cerr << "Expected exactly one argument: " << argv[0] << " <filename>"
              << std::endl;
    return -1;
  }

  int val = std::stoi(argv[1]);
  std::cout << val << " = ";

  if (val == 0) {
    std::cout << '0' << std::endl;
    return 0;
  }

  short idx = sizeof(int) * 8;

  while ((val & (1 << idx)) == 0)
    idx--;

  for (; idx >= 0; idx--) {
    std::cout << ((val & (1 << idx)) ? '1' : '0');
  }
  std::cout << std::endl;
}
