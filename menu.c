/*
 * Auth: CADE PREISTER
 * Date: 11-09-24 (Due: 11-10-24)
 * Course: CSCI-2240 (Sec: 851)
 * Desc: ASSIGNMENT-06, Menu system.
 */

#include <stdio.h>
#include <stdbool.h>
#define ARRAY_SIZES 32

void print_menu(void);

/* Main Function */
int main(void)
{
    char first_name[ARRAY_SIZES] = "(Not Given)";
    char last_name[ARRAY_SIZES] = "(Not Given)";
    char home_city[ARRAY_SIZES] = "(Not Given)";
    char home_state[ARRAY_SIZES] = "(Not Given)";
    int exit_attempts = 0;
    int selection;

    bool got_first = false;
    bool got_last = false;
    bool got_city = false;
    bool got_state = false;
    bool got_everything = false;
    bool allow_exit = false;

    printf("*** User Information Menu System ***");
    print_menu();

    while (scanf("%d", &selection) == 1)
    {
        switch (selection)
        {
            case (1):
                if (!got_first)
           	{
             	    printf("Enter your First Name: ");
                    scanf("%s", first_name);
                    got_first = true;
                }
                else
                {
                    printf("Already have a first name.");
                }
                break;

            case (2):
                if (!got_last)
                {
                    printf("Enter your Last Name: ");
                    scanf("%s", last_name);
                    got_last = true;
                }
                else
                {
                    printf("Already have a last name.");
                }
                break;

            case (3):
                if (!got_city)
                {
                    printf("Enter your Home City: ");
                    scanf("%s", home_city);
                    got_city = true;
                }
                else
                {
                    printf("Already have a home city.");
                }
                break;

            case (4):
                if (!got_state)
                {
                    printf("Enter your Home State: ");
                    scanf("%s", home_state);
                    got_state = true;
                }
                else
                {
                    printf("Already have a home state.");
                }
                break;

             case (5):
                 if (got_first && got_last && got_city && got_state)
                 {
                     printf("That's everything. Thanks!\n");
                     printf("User Info Summary:\nFirst Name: %s\nLast Name: %s\nHome City: %s\nHome State: %s\n",
                             first_name, last_name, home_city, home_state);
	             got_everything = true;
		     return 0;
         	 } else if (!allow_exit) {
		     printf("You still have some info to provide!\n");
		     allow_exit = true;
		 } else {
		     printf("Ok, if you insist!\n");
                     printf("User Info Summary:\nFirst Name: %s\nLast Name: %s\nHome City: %s\nHome State: %s\n",
                             first_name, last_name, home_city, home_state);
                     return 0;
		 }
		 break;
	     default:
		 printf("Invalid selection!\n");
		 exit_attempts++;
		 if (exit_attempts >= 2)
		 {
		     printf("User Info Summary:\nFirst Name: %s\nLast Name: %s\nHome City: %s\nHome State: %s\n",
                             first_name, last_name, home_city, home_state);
	             return 0;
		 }
		 break;
            }
	if (selection == 5 && got_everything)
	{
	    break;
	}

	print_menu();
    }

    printf("User Info Summary:\nFirst Name: %s\nLast Name: %s\nHome City: %s\nHome State: %s\n",
               first_name, last_name, home_city, home_state);

    return 0;
}

void print_menu(void)
{
    printf("\n");
    printf("[1] Provide your First Name.\n");
    printf("[2] Provide your Last Name.\n");
    printf("[3] Provide Home City.\n");
    printf("[4] Provide Home State. \n");
    printf("[5] Exit\n\n");
    printf("Please make a selection and press [ENTER]: ");
}
