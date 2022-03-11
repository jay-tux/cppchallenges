#include <iostream>
#include <string>

int main(int argc, const char **argv) {
  if (argc != 3) {
    std::cerr << "Expected exactly one argument: " << argv[0]
              << " <large> <sub>" << std::endl;
    return -1;
  }

  const char star = 5;
  std::string large(argv[1]);
  std::string sub;

  for (size_t i = 0; i < std::string(argv[2]).length(); i++) {
    if (argv[2][i] == '*')
      sub += star;
    else if (argv[2][i] == '\\') {
      if (argv[2][i + 1] == '*') {
        i++;
        sub += '*';
      } else {
        sub += '\\';
      }
    } else
      sub += argv[2][i];
  }

  size_t subidx = 0;
  bool instar = false;
  long laststop = -1;
  bool found = false;
  for (size_t i = 0; i < large.length(); i++) {
    if (instar) {
      if (large[i] == sub[subidx]) {
        laststop = i;
        subidx++;
        if (subidx == sub.length()) {
          found = true;
          break;
        }
      }
    } else {
      if (large[i] == sub[subidx]) {
        subidx++;
        if (subidx == sub.length()) {
          found = true;
          break;
        }
        if (sub[subidx] == star) {
          instar = true;
          subidx++;
          if (subidx == sub.length()) {
            found = true;
            break;
          }
        }
      } else {
        subidx = 0;
      }
    }
  }

  std::cout << (found ? "true" : "false") << std::endl;
}
