#pragma once
#define MAX_USERS 3
#define MAX_NAME_LENGTH 50
#define MAX_PASS_LENGTH 20
typedef struct  {
	char *name;
	char *password;

}USER;


void new_user(int* num_users, USER* users);
void login_user(int* num_users, USER* users);
void delete_user(int* num_users, USER* users);
void display_users(int* num_users, USER* users);
void exit_manager(int* num_users, USER* users);