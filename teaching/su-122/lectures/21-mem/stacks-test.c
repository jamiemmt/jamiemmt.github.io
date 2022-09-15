/* Testing generic stacks
 * 15-122 Principles of Imperative Computation, Fall 2010
 * Frank Pfenning
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "xalloc.h"
#include "contracts.h"
#include "stacks.h"

void int_free(void* p) {
  free((int*)p);		/* this coercion is optional */
}

int main () {
  stack S = stack_new();
  int x = 1;
  int y = 2;
  push(S, &x);
  push(S, &y);
  printf("%d\n", *(int*)pop(S) + *(int*)pop(S));
  push(S, &x);
  stack_free(S, NULL);		/* cannot free pointers to stack */
  stack W = stack_new();	/* cannot reuse S */
  int* a = xmalloc(sizeof(int));
  int* b = xmalloc(sizeof(int));
  push(W, a);
  push(W, b);
  stack_free(W, &int_free);	/* free pointers to heap */
  printf("All tests succeeded!\n");
  return 0;
}
