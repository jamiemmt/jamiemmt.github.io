#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stacks.h"

int main () {
  stack S = stack_new();
  char* s = "15122";
  push(s, S);
  int y = 3+*(int*)pop(S);
  printf("result = %d\n", y);
  return 0;
}
