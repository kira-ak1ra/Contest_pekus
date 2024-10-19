#include <iostream>

int main() {
  int n = 0;

  std::cin >> n;

  int binary[32] = {};

  for (int i = 0; i < 32; i++) {
    binary[i] = -1;
  }

  int i = 0;

  while (n > 0) {
    binary[i] = !(n % 2);
    n /= 2;
    i++;
  }

  int base = 1;
  int result = 0;
  for (int i = 0; i < 32; i++) {
    if (binary[i] != -1) {
      result += binary[i] * base;
      base *= 2;
    }
  }

  std::cout << result;
}
