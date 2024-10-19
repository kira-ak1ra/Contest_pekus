#include <iostream>

int main() {
  char* s1 = new char[1000000];
  char* s2 = new char[1000000];

  std::cin.getline(s1, 1000000);
  std::cin.getline(s2, 1000000);

  int len1 = 0;
  int len2 = 0;

  for (int i = 0; i < 1000000; i++) {
    if (s1[i] != 0) {
      len1++;
    } else {
      break;
    }
  }

  for (int i = 0; i < 1000000; i++) {
    if (s2[i] != 0) {
      len2++;
    } else {
      break;
    }
  }

  if (len1 != len2) {
    std::cout << "NO";
    return 0;
  }

  int letters1[256] = { 0 };
  int letters2[256] = { 0 };

  for (int i = 0; i < len1; i++) {
    int pos = s1[i];
    letters1[pos] += 1;
  }

  for (int i = 0; i < len2; i++) {
    int pos = s2[i];
    letters2[pos] += 1;
  }

  for (int i = 0; i < 256; i++) {
    if (letters1[i] != letters2[i]) {
      std::cout << "NO";
      delete[] s1;
      delete[] s2;
      return 0;
    }
  }

  std::cout << "YES";

  delete[] s1;
  delete[] s2;
}