#include <iostream>
#include <vector>

size_t get_pascal(int depth, int offset) {
  if (offset == 0 || offset == depth || depth <= 1)
    return 1;

  std::vector<std::vector<size_t>> dp;

  for (int d = 0; d <= depth; d++) {
    dp.push_back(std::vector<size_t>());
    dp[d].push_back(1);
    for (int i = 1; i < d; i++) {
      dp[d].push_back(dp[d - 1][i - 1] + dp[d - 1][i]);
    }
    dp[d].push_back(1);
  }

  return dp[depth][offset];

  // return get_pascal(depth - 1, offset - 1) + get_pascal(depth - 1, offset);
}

int main() {
  int depth, offset;
  std::cout << "Depth ( = row)? ";
  std::cin >> depth;

  if (depth < 0) {
    std::cerr << "Depth should be >= 0" << std::endl;
    return -1;
  }

  std::cout << "Horizontal offset ( = column)? ";
  std::cin >> offset;

  if (offset < 0 || offset > depth) {
    std::cerr << "Offset should be in [0, " << depth << "[." << std::endl;
    return -1;
  }

  std::cout << get_pascal(depth, offset) << std::endl;
}
