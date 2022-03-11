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

  size_t count;
  std::string in;
  while (strm && !strm.eof()) {
    std::getline(strm, in);
    count++;
  }

  std::cout << count << std::endl;
}
