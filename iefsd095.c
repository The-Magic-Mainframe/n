/*
iefsd095.c - Block Character Routine

See: https://www.ibm.com/docs/en/zos/latest?topic=works-using-block-character-routine
*/
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "regs.h"

struct Parmlist {
  // 4-byte address of the character string to be formatted
  uint32_t string;
  // 4-byte address of a fullword field containing the line 
  //   (row) number to be constructed
  uint32_t lineno;
  // 4-byte address of the output construction area where this
  //   routine will build a line of the block character string
  uint32_t outarea;
  // 4-byte address of a fullworld field containing the number
  //   of characters in the string
  uint32_t length;
  // 4-byte address of the PROC name in the SSOB extension
  uint32_t procname;
  // 4-byte address of the STEP name in the SSOB extension
  uint32_t stepname;
  // 4-byte address of the data set DD name in the SSOB extension
  uint32_t ddname;
};

int iefsd095(greg r1) {
  /*
  The block character routine constructs block letters, block
  numbers, and a blank. The separator routine furnishes the 
  desired character string and the construction area. The block
  characters are constructed one position at a time. Each complete
  character is contained in 12 lines and 12 columns; therefore,
  a block character area consists of 144 print positions. For each
  position, the routine provides either a space or the character
  itself.

  This routine is compatible with the IEFSD095 routine provided
  by IBM for z/OS and has additional features.
  */
  return 0;
}

int main(void) {
  /*
  Main entry point;
  */
  greg r1;
  const char *mystring = "ACF2SME";
  struct Parmlist myparm = {
    .string = (uint32_t) mystring,
    .length = strlen(mystring)
  };
  
  r1 = (uint64_t) &myparm;
  return iefsd095(r1);
}
