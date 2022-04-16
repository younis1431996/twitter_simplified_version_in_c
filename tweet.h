#ifndef TWEET_H_INCLUDED
#define TWEET_H_INCLUDED
/* inclusions*/
#include <stdio.h>
#include <stdlib.h>

/* definitions */
#define MAX_TWEET_LENGTH    270
#define MAX_NUM_OF_TWEETS   100
#define USR_LENGHT          50

typedef struct tweet{
    int id;
    char msg[MAX_TWEET_LENGTH];
    char user[USR_LENGHT];

}Tweet;

typedef Tweet StackEntry;

/* Stack structures */
typedef struct stacknode{
	StackEntry entry;
	struct stacknode *next;
}StackNode;

typedef struct stack{
	StackNode *top;
}Stack;

/* functions */
void create_tweet_stack(Stack *ps);

void push(StackEntry pe, Stack *ps);

void pop(StackEntry *pe, Stack *ps);
#endif // TWEET_H_INCLUDED
