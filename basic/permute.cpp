#include <iostream>
#include <string>
#include <vector>

std::string except(std::string in, size_t i) {
  std::string res = in;
  res.erase(i, 1);
  return res;
}

std::vector<std::string> permute(std::string in) {
  if (in.length() == 0) {
    return std::vector<std::string>();
  } else if (in.length() == 1) {
    return std::vector<std::string>({in});
  }

  std::vector<std::string> res;

  for (size_t i = 0; i < in.size(); i++) {
    for (std::string str : permute(except(in, i))) {
      res.push_back(in[i] + str);
    }
  }

  return res;
}

int main(int argc, const char **argv) {
  if (argc != 2) {
    std::cerr << "Expected exactly one argument: " << argv[0] << " <filename>"
              << std::endl;
    return -1;
  }

  for (std::string &elem : permute(argv[1])) {
    std::cout << elem << std::endl;
  }
}
