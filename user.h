#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

/* inclusions */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/* definitions */
#define MAX_USERS       100
#define MAX_USERNAME    50
#define MAX_FOLLOWERS   30
#define MAX_FOLLOWING   30

/*users structure */
typedef struct user{
    char username[MAX_USERNAME];
    char followers[MAX_FOLLOWERS];
    int num_followers;
    char following[MAX_FOLLOWING];
    int num_following;
}User;

/* all users in one place "users list" */
typedef struct users{
    User entry[MAX_USERS];
    int size;
}Users_list;

/* functions */
void create_user(int index, Users_list *pul);

void Add_user(Users_list *pul);

void Remove_user(Users_list *pul, int ID);

int is_unique(char username[MAX_USERNAME], Users_list *pul);
#endif // USER_H_INCLUDED
