#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "system.h"

/* definitions */
#define INIT_USERNAMES 3

/* functions */
int option(void)
{
    int control;
    printf("[0] follow user       [1] unfollow user\n");
    printf("[2] delete account    [3] end turn\n");
    printf("[4] twitter news feed [5] post tweet\n");
    printf("[6] end twitter\n");
    printf("Function: ");
    scanf("%d", &control);
    printf("\n");
    return control;
}

void account_information(int ID)
{
    // Goto UserName account.
    printf("[ID: %d]           [UserName: %s]\n", ID, u_list.entry[ID].username);
    printf("[Following: %d]    [Followers: %d]\n\n", u_list.entry[ID].num_following, u_list.entry[ID].num_followers);

    for(int i=0; i<u_list.entry[ID].num_following; i++)
    {
        if(u_list.entry[ID].num_following == 0) break;
        printf("-%s\n", &u_list.entry[ID].following[i]);
    }
}
int main()
{
    // system initialization.
    system_init();

    /* (1)initially insert user names. */
    printf("======================== *Twitter Simplified version in C v1.0* ========================\n");
    printf(">> UserNames insertion....\n");
    for(int i=0; i<INIT_USERNAMES; i++){
        create_user(i,&u_list);
    }

    /* (2) Print all userNames */
    printf("=============================== *All UserNames* ===============================\n");
    get_system_userNames();
    printf("\n");
    printf("===============================================================================\n");
    /* Twitter System */
    int ID = 0;
    int control = 0;

    // Get UserName ID, UserName selection..
    printf("Select userName ID: ");
    scanf("%d", &ID);
    printf("**********************************************************************\n");

    // Goto UserName account.
    account_information(ID);

    for(;;)
    {
        // Select option.
        control = option();

        // Following user.
        if(control==0)
        {
            printf("*********** follow users ***********\n");
            // print all users.
            for(int j=0; j<u_list.size; j++)
            {
                if(j==ID) continue;
                printf("  [ID: %d]\t[UserName: %s]\n",j, u_list.entry[j].username);
            }

            int _id;
            printf("Select UserName ID to follow: ");
            scanf("%d", &_id);

            strcpy(&u_list.entry[ID].following[u_list.entry[ID].num_following], u_list.entry[_id].username);
            strcpy(&u_list.entry[_id].followers[u_list.entry[_id].num_followers], u_list.entry[ID].username);

            u_list.entry[ID].num_following += 1;
            u_list.entry[_id].num_followers += 1;

            printf("\n");
        }
        // unfollow user.
        else if(control == 1)
        {
            // print all users.
            for(int j=0; j<u_list.size; j++)
            {
                if(j==ID) continue;
                printf("  [ID: %d]\t[UserName: %s]\n",j, u_list.entry[j].username);
            }

            int _id;
            printf("Select UserName ID to unfollow: ");
            scanf("%d", &_id);

            u_list.entry[ID].following[_id] = NULL;
            u_list.entry[_id].followers[ID] = NULL;

            u_list.entry[ID].num_following -=1;
            u_list.entry[_id].num_followers -=1;
        }
        // delete account.
        else if(control==2)
        {
            Remove_user(&u_list, ID);
            // print all users.
            for(int j=0; j<u_list.size; j++)
            {
                printf("[ID: %d]\t[UserName: %s]\n",j, u_list.entry[j].username);
            }

            printf("Select userName ID: ");
            scanf("%d", &ID);
            printf("--------------------\n");
            account_information(ID);
        }
        // end turn.
        else if(control==3)
        {
            printf("Select userName ID: ");
            scanf("%d", &ID);
            printf("--------------------\n");
            account_information(ID);
        }
        // twitter news feed.
        else if(control==4)
        {
            getNewsFeed();
        }
        // post tweet.
        else if(control==5)
        {
            User *pu = &(u_list.entry[ID]);
            post_tweet(pu);
        }
        // end twitter.
        else if(control==6)
        {
            return 0;
        }
    }
    return 0;
}
