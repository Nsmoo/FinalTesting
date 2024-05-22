#include <iostream>

void invert(uint8_t* x, int len, uint8_t mask) {
  for(int i =  0; i < len; i++) {
    *x = *x ^ mask;
    ++x;
  }
}

int main() {
  const int l = 4;
  uint8_t A[l] = {0b00101011, 0b11010100, 0b11011011, 0b00100100};
  uint8_t mask = 0b11011011;

  invert(A, l, mask);

  for(int i = 0; i < l; i++) {
    for(int j = sizeof(uint8_t) * 8 - 1; j >= 0; j--) {
      std::cout << ((A[i] >> j) & 1);
    }
    std::cout << " ";
  }
  std::cout << "\n";
  return 0;
}