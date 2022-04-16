#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED
/* inclusions */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "user.h"
#include "tweet.h"

/* system lists */
// users list.
Users_list u_list;

// tweets stack
Stack tweet_Stack;

/* functions */
void system_init(void);

void get_system_userNames(void);

void post_tweet(User *pu);

void getNewsFeed(void);

#endif // SYSTEM_H_INCLUDED
