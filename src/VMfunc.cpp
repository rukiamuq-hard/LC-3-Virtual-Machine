#include "../include/core.hpp"
#include <cstdint>
#include <cstdio>

uint16_t check_key() {
  return WaitForSingleObject(GetStdHandle(STD_INPUT_HANDLE), 0) ==
         WAIT_OBJECT_0;
}

void mem_write(uint16_t address, uint16_t val) { memory[address] = val; }

uint16_t mem_read(uint16_t address) {
  if (address == MR_KBSR) {
    if (check_key()) {
      memory[MR_KBSR] = (1 << 15);
      memory[MR_KBDR] = std::getchar();
    } else {
      memory[MR_KBSR] = 0;
    }
  }
  return memory[address];
}

uint16_t swap16(uint16_t x) { return (x << 8) | (x >> 8); }

uint16_t sign_extend(uint16_t x, int bit_count) {
  if ((x >> (bit_count - 1)) & 1) {
    x |= (0xFFFF << bit_count);
  }
  return x;
}

void update_flags(uint16_t r) {
  if (reg[r] == 0) {
    reg[R_COND] = FL_ZRO;
  } else if (reg[r] >> 15) /* a 1 in the left-most bit indicates negative */
  {
    reg[R_COND] = FL_NEG;
  } else {
    reg[R_COND] = FL_POS;
  }
}

void read_image_file(FILE *file) {
  uint16_t origin;
  std::fread(&origin, sizeof(origin), 1, file);
  origin = swap16(origin);

  uint16_t max_read = UINT16_MAX - origin;
  uint16_t *p = memory + origin;
  std::size_t read = fread(p, sizeof(uint16_t), max_read, file);

  while (read-- > 0) {
    *p = swap16(*p);
    ++p;
  }
}

int read_image(const char *path) {
  FILE *file = nullptr;
  fopen_s(&file, path, "rb");
  if (!file)
    return 0;
  read_image_file(file);
  std::fclose(file);
  return 1;
}
