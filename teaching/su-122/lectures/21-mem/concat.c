/* String concatenation
 * 15-122 Principles of Imperative Computation, Spring 2011
 * Frank Pfenning
 */
/* Simple example of working with strings */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* concat(char* s1, char* s2) {
  int l1 = strlen(s1);
  int l2 = strlen(s2);
  char* r = malloc(sizeof(char)*(l1+l2+1));
  if (r == NULL) abort();
  for (int i = 0; i < l1; i++) {
    // assert(0 <= i && i < l1);
    r[i] = s1[i];
  }
  for (int i = 0; i < l2; i++) {
    // assert(0 <= l1+i && l1+i < l1+l2);
    r[l1+i] = s2[i];
  }
  r[l1+l2] = '\0';
  return r;
}

int main () {
  char* w = concat(" ", "world!");
  char* hw = concat("Hello", w);
  printf("%s\n", hw);
  free(w);
  free(hw);
  return 0;
}

  
