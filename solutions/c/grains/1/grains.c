#include "grains.h"
#include <stdint.h>
#define CHESSBOARD 64

uint64_t square(uint8_t index) {
  uint64_t grains = 1;
  if (index > CHESSBOARD || index < 1) {
    return 0;
  }
  if (index == 1) {
    return grains;
  }
  for (uint8_t i = 1; i < index; i++) {
    grains *= 2;
  }
  return grains;
}

uint64_t total() {
  uint64_t total = 0;
  for (uint8_t i = 1; i <= CHESSBOARD; i++) {
    total += square(i);
  }
  return total;
}
