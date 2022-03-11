#include <iomanip>
#include <iostream>

#define LOWER 10
#define UPPER 100
#define MAXSTEP 10

int main() {
  auto conv = [](float celc) { return celc * 9.0f / 5.0f + 32.0f; };

  uint low, high, step;
  std::cout << "Lower limit (0 <= x <= " << LOWER << ")? ";
  std::cin >> low;
  if (low > LOWER) {
    std::cerr << "Invalid lower bound." << std::endl;
    return -1;
  }

  std::cout << "Upper limit (" << low << " < x <= " << UPPER << ")? ";
  std::cin >> high;
  if (high <= low || high > UPPER) {
    std::cerr << "Invalid upper bound." << std::endl;
    return -1;
  }

  std::cout << "Step size (0 < x <= " << MAXSTEP << ")? ";
  std::cin >> step;
  if (step > MAXSTEP) {
    std::cerr << "Invalid step size." << std::endl;
    return -1;
  }

  std::cout << "\tCELCIUS\t\tFAHRENHEIT" << std::endl;
  std::cout << "\t-------\t\t----------" << std::endl;
  while (low <= high) {
    std::cout << "\t" << std::fixed << (float)low << "\t" << std::fixed
              << conv(low) << std::endl;
    low += step;
  }
}
