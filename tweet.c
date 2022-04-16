/* inclusions */
#include "tweet.h"

void create_tweet_stack(Stack *ps){
    // initialize first pointer in the stack to null.
	ps->top = NULL;
}

void push(StackEntry pe, Stack *ps){
    // create new node.
	StackNode *pn = (StackNode*)malloc(sizeof(StackNode));

	// store element to the entry of the new node
	pn->entry = pe;

	// the next pointer will point to last top.
	pn->next = ps->top;

	// new top.
	ps->top = pn;
}

void pop(StackEntry *pe, Stack *ps){
    // save last top.
	StackNode *pn;
	pn = ps->top;

	// element value equal to the entry of last top.
	*pe = ps->top->entry;

	// new top.
	ps->top = ps->top->next;

	// deallocate last top memory.
	free(pn);
}
