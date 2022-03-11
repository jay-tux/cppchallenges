#include <fstream>
#include <iostream>

int main(int argc, const char **argv) {
  if (argc != 2) {
    std::cerr << "Expected exactly one argument: " << argv[0] << " <filename>"
              << std::endl;
    return -1;
  }

  std::ifstream strm(argv[1]);
  if (!strm.good()) {
    std::cerr << "File " << argv[1] << " does not exist or is not readable."
              << std::endl;
    return -1;
  }

  auto size = strm.seekg(0, std::ios_base::end).tellg();

  std::cout << size << std::endl;
}
