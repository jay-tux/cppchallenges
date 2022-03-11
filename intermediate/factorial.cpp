#include <iostream>

int main(int argc, const char **argv) {
  if (argc != 2) {
    std::cerr << "Expected exactly one argument: " << argv[0] << " <filename>"
              << std::endl;
    return -1;
  }

  size_t fac = std::stoi(argv[1]);
  size_t evens = 0;
  size_t fivefolds = 0;

  for (size_t i = 1; i <= fac; i++) {
    size_t j = i;
    while (j % 2 == 0) {
      evens++;
      j /= 2;
    }

    while (j % 5 == 0) {
      fivefolds++;
      j /= 5;
    }
  }

  size_t count = (evens > fivefolds) ? fivefolds : evens;

  std::cout << count << std::endl;
}
