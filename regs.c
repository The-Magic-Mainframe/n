/*
regs.c - z-series registers
*/
#include <stdint.h>
#include <stdio.h>

#include "regs.h"

greg gg[16];
greg *gg0 = &gg[0];
greg *gg1 = &gg[1];
greg *gg2 = &gg[2];
greg *gg3 = &gg[3];
greg *gg4 = &gg[4];
greg *gg5 = &gg[5];
greg *gg6 = &gg[6];
greg *gg7 = &gg[7];
greg *gg8 = &gg[8];
greg *gg9 = &gg[9];
greg *gg10 = &gg[10];
greg *gg11 = &gg[11];
greg *gg12 = &gg[12];
greg *gg13 = &gg[13];
greg *gg14 = &gg[14];
greg *gg15 = &gg[15];

void LG(greg *r, uint64_t *value) {
  /*
  z/Architecture LOAD instruction. Load 8 byte value from memory
  into a register.
  */
  *r = *value;
}

int main(void) {
  /*
  Main entry point;
  */
  uint64_t value = 666;
  gg[0] = 4;
  *gg3 = gg[0];
  gg[10] = *gg3;
  printf("Contents of register 10: %ld\n", *gg10);
  LG(gg10, &value);
  printf("Contents of register 10: %ld\n", *gg10);
}
