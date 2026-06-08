enum {
  R_R0 = 0,
  R_R1,
  R_R2,
  R_R3,
  R_R4,
  R_R5,
  R_R6,
  R_R7,
  R_PC,
  R_COND,
  R_COUNT // programm counter
};

enum {
  OP_BR = 0,
  OP_ADD,
  OP_LD,
  OP_ST,
  OP_JSR,
  OP_AND,
  OP_LDR,
  OP_STR,
  OP_RTI,
  OP_NOT,
  OP_LDI,
  OP_STI,
  OP_JMP,
  OP_RES,
  OP_LEA,
  OP_TRAP
};

enum {
  FL_POS = 1 << 0, // P
  FL_ZRO = 1 << 1, // Z
  FL_NEG = 1 << 2, // N
};

enum { PC_START = 0x3000 };

enum {
  TRAP_GETC = 0x20,
  TRAP_OUT = 0x21,
  TRAP_PUTS = 0x22,
  TRAP_IN = 0x23,
  TRAP_PUTSP = 0x24,
  TRAP_HALT = 0x25
};

enum {
  MR_KBSR = 0xFE00, // keyboard stat
  MR_KBDR = 0XFE02  // keyboard data
};

#include <cstdint>
#include <cstdio>
#include <windows.h>

extern uint16_t memory[UINT16_MAX];
extern uint16_t reg[R_COUNT];

void mem_write(uint16_t address, uint16_t val);
uint16_t mem_read(uint16_t address);

int read_image(const char *path);

uint16_t swap16(uint16_t x);
uint16_t sign_extend(uint16_t x, int bit_count);
void update_flags(uint16_t r);

void read_image_file(FILE *file);

uint16_t check_key();
