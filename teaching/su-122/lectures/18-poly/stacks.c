/* Stacks
 * 15-122 Principles of Imperative Computation, Spring 2011
 * Frank Pfenning
 */

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "xalloc.h"
#include "contracts.h"
#include "stacks.h"

/* Linked lists */

typedef struct list* list;
struct list {
  void* data;			/* generic data */
  list next;
};

/* is_segment(start, end) will diverge if list is circular! */
bool is_segment(list start, list end)
{ list p = start;
  while (p != end) {
    if (p == NULL) return false;
    p = p->next;
  }
  return true;
}

/* Stacks */ 

struct stack {
  list top;
  list bottom;
};

bool is_stack (stack S) {
  if (S == NULL) return false;
  if (S->top == NULL || S->bottom == NULL) return false;
  if (!is_segment(S->top, S->bottom)) return false;
  return true;
}

bool stack_empty(stack S)
//@requires is_stack(S);
{
  REQUIRES(is_stack(S));
  return S->top == S->bottom;
}


stack stack_new()
//@ensures is_stack(\result);
//@ensures stack_empty(\result);
{
  REQUIRES(true);		/* no precondition */
  stack S = xmalloc(sizeof(struct stack));
  list l = xmalloc(sizeof(struct list));
  S->top = l;
  S->bottom = l;
  ENSURES(is_stack(S) && stack_empty(S));
  return S;
}

void stack_free(stack S)
//@requires is_stack(S) && stack_empty(S);
{ REQUIRES(is_stack(S) && stack_empty(S));
  assert(stack_empty(S));
  free(S->top); /* == S->bottom */
  free(S);
}

void push(stack S, void* e)
//@requires is_stack(S);
//@ensures is_stack(S) && !stack_empty(S);
{
  REQUIRES(is_stack(S));
  list first = xmalloc(sizeof(struct list));
  first->data = e;
  first->next = S->top;
  S->top = first;
  ENSURES(is_stack(S) && !stack_empty(S));
}

void* pop(stack S)
//@requires is_stack(S);
//@requires !stack_empty(S);
//@ensures is_stack(S);
{ REQUIRES(is_stack(S));
  assert(S != NULL && !stack_empty(S)); /* check this routinely */
  void* e = S->top->data;	/* save old stack element to return */
  list q = S->top;		/* save old list node to free */
  S->top = S->top->next;
  free(q);			/* free old list node */
  ENSURES(is_stack(S));
  return e;			/* return old stack element */
}

