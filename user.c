/* inclusions */
#include "user.h"

/* static functions used only in this scope file */
static void add_user(int index, User u, Users_list *pul){
    int i;
    for(i=pul->size; i>=index; i--)
        pul->entry[i+1] = pul->entry[i];

    pul->entry[index] = u;
    pul->size++;
}

/* functions */
void create_user(int index, Users_list *pul){
    // create user.
    User u;

    // get UserName.
    printf("userName: ");
    gets(u.username);

    // check if unique or not.
    if(is_unique(u.username, pul)){
           // No followers.
           u.num_followers = 0;

           // No following.
           u.num_following = 0;

           // insert user to system users list.
           add_user(index, u, pul);
    }
    else{
        printf("repeated UserName...\n");
    }

}

void Add_user(Users_list *pul){
    // this function adds the new UserName in the last of system users list.
    create_user(pul->size, pul);
}

void Remove_user(Users_list *pul, int ID){
    int i, index=ID;

	// if not found.
	if(index+1 == pul->size){
        printf("UserName not found\n");
	}
    else{
            // if removed element is the first element.
            if(index==0){
                index=-1;
            }
            for(i=index+2; i<=pul->size; i++)
            pul->entry[i-1] = pul->entry[i];
            pul->size--;
    }

}

// this function to check if UserName is repeated or not.
int is_unique(char username[MAX_USERNAME], Users_list *pul){
    	// Search about it.
	for(int i=0; pul->size!=0 && i<pul->size; i++){
	    if(strcmp(username, pul->entry[i].username) == 0)
            return 0;
	}
	return 1;
}
