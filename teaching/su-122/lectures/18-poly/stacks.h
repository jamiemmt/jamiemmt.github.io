/* Interface for stacks
 * 15-122 Principles of Imperative Computation, Fall 2010
 * Frank Pfenning
 */

#include <stdbool.h>

#ifndef _STACKS_H_
#define _STACKS_H_

typedef struct stack* stack;
bool stack_empty(stack S);	/* O(1) */
stack stack_new();		/* O(1) */
void push(stack S, void* e);	/* O(1) */
void* pop(stack S);		/* O(1) */
void stack_free(stack S);	/* O(1), S must be empty! */

#endif
