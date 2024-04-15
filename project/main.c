#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#define MAX_USERS 3

int main(void) {

	USER users[MAX_USERS] = { 0 };
	int num_users = 0;
	int choice = 0;

	
	while (1) {
		system("cls");
		printf("unesite broj odabira izbornika : \n 1. new user \n 2. login_existing_user \n 3. delete_existing_user \n 4. search_user \n 5. exit_manager \n");

		scanf("%d", &choice);

		switch (choice) {

		case 1:  new_user(&num_users, users);  break;

		case 2:  login_user(&num_users, users); break;

		case 3:  delete_user(&num_users, users); break;

		case 4: display_users(&num_users, users);  break;

		case 5: exit_manager(&num_users, users);
			exit(EXIT_SUCCESS);
		default:  printf("Enter a valid choice.\n");  break;

		}

		system("pause");
	}



	return 0;
}