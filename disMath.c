/*
* Compile and execute this program.
* What value is printed?
* Explain.
*/

#include <stdio.h>

int main () {
   unsigned int n = 4294967295; // n = 2^{32} - 1 
   printf("value = %u\n", n+1);
}

/*
*since int can only hold 4 bytes or 32 bits, 
*Using a number that is exactly 4 bits then adding 1 onto
*makes its memory location overflow to 0
*/