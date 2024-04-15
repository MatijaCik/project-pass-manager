#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"



void new_user(int* num_users, USER* users){
	
	if (*num_users >= MAX_USERS) {
		printf("user capacity limit reached , please remove a user or expand memory \n");
	}
	else {
		users[*num_users].name = malloc(MAX_NAME_LENGTH * sizeof(char));
		if (users[*num_users].name == NULL) {
			printf("Memory allocation failed for user name.\n");
			return;
		}

		users[*num_users].password = malloc(MAX_PASS_LENGTH * sizeof(char));
		if (users[*num_users].password == NULL) {
			printf("Memory allocation failed for user password.\n");
			free(users[*num_users].name); // Free previously allocated memory
			return;
		}

		printf("enter your name :  \n");
		scanf("%49s", users[*num_users].name);
		while (getchar() != '\n');
		printf("enter your password for log in \n");
		scanf("%19s", users[*num_users].password);
		while (getchar() != '\n');
		(*num_users)++;
	}
}

void login_user(int* num_users, USER* users) {
	 char username[MAX_NAME_LENGTH];
 char password[MAX_PASS_LENGTH];
	int i;

	printf("Enter username: ");
	scanf("%49s", username);
	printf("Enter password: ");
	scanf("%s", password);

	for (i = 0; i < *num_users; i++) {
		if (strcmp(username, users[i].name) == 0 && strcmp(password, users[i].password) == 0) {
			printf("Login successful.\n");
			return;
		}
	}

	printf("Invalid username or password.\n");
}

void delete_user(int* num_users, USER* users) {
	char answer;
	char username[MAX_NAME_LENGTH];
	int i = 0;
	int found = 0;
	
	printf("Enter username to delete: ");
	scanf("%s", username);

	printf("do you really wanna delete user :  %s ", username);
	printf("Y/n?\n");
	scanf(" %c", &answer);

	if (answer == 'Y') {

	for (i = 0; i < *num_users; i++) {
		if (strcmp(username, users[i].name) == 0) {
			found = 1;
			*num_users -= 1;
			for (; i < *num_users; i++) {
				strcpy(users[i].name, users[i + 1].name);
				strcpy(users[i].password, users[i + 1].password);
			}
			printf("User '%s' deleted.\n", username);
			break;
		}
		}
	}else{
		printf("username isnt deleted \n");
	}

	if (!found)
		printf("User '%s' not found.\n", username);
}

void display_users(int* num_users, USER* users) {
	int i;
	if (num_users == 0) {
		printf("No users found.\n");
		return;
	}
	printf("Users:\n");
	for (i = 0; i < *num_users; i++) {
		printf("Users: %s\n", users[i].name);
	}

}
void free_users( USER* users) {
	int num_users = 0;
	for (int i = 0; i < num_users; i++) {
		free(users[i].name);
		free(users[i].password);
	}
}
void exit_manager(int* num_users, USER* users) {
	free_users(users);
}