#include<iostream>
#include<vector>

#define INVERT_BITS_OK 0
#define INVERT_BITS_NULLPTR -1
#define INVERT_BITS_SIZE_ERROR -2
#define INVERT_BITS_NO_MASK -3

int invertBits(uint8_t* ptr, int size, std::vector<bool> mask) {

  if (!ptr) {
    return INVERT_BITS_NULLPTR;
  }

  if (size <= 0) {
    return INVERT_BITS_SIZE_ERROR;
  }

  if (mask.empty()) {
    return INVERT_BITS_NO_MASK;
  }

  auto a = mask.begin();
  for (int i = 0; i < size; i++) {
    for (int j = 7; j >= 0; j--) {
      if (*a) {
        ptr[i] ^= (1 << j);
      }
      a++;
      if (a == mask.end()) {
        a = mask.begin();
      }
    }
  }
  return INVERT_BITS_OK;
}

int main() {
  const int l = 4;
  uint8_t A[l] = {0b00000000, 0b01010101, 0b10101010, 0b11111111};
  std::vector<bool> mask = {0, 1};

  invertBits(A, l, mask);

  for (int i = 0; i < l; i++) {
    for (int j = 7; j >= 0; j--) {
      std::cout << ((A[i] >> j) & 1);
    }
    std::cout << " ";
  }
  std::cout << "\n";
}