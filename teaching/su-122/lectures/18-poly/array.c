#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
  /* int[] A = alloc_array(int, 2); */
  int* A = malloc(2*sizeof(int));
  A = (int*)"abc";
  int x = 3;
  int y = 0;
  if (x/y == x/y)
    printf("true\n");
  int z = 0x7FFFFFFF;
  if (z+1 > z)
    printf("oh,no\n");
  /* printf("maxint+1 = %d\n", z+1); */
  /* A[0] = 45; */
  printf("%d\n", A[0]);
  return 0;
}
