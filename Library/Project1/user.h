#pragma once
#include"utility.h"
#include"teacher.h"
#include<string>
#include<iostream>
using namespace std;

struct user
{
	string username, pass, name, address;		// username,password,fullname,address
	date birthday;				// date of birth
	bool sex, status;			// sex (T/F -> male/female), status (T/F -> active/inactive)
	int type;			// user type (0/1/2 -> admin/teacher/student)
	teacher *teach;		// teacher data if this is a teacher
	int id;				// user id
	user* next;			// link to next user in list
};

bool load_user(user*& list, int &maxID);		// load data from file
bool store_user(user* list, int maxID);			// store data to fiel
void reset_user(user*& list);			// delete all user from this list

void copy_user(user &target, const user &src);		// copy user from src to target
void add_user(user *&list, user *account);			// add a user to head of list
bool remove_user(user *&list, int ID);			// remove a user having ID from list

user *search_user(user *list, const user &filter);			// return a list of user based on search filter
void display_user(user *list);

// login menu, let user type username, password or exit
user *login(user *list);
void menu_change_password(user *data);
void menu_update_data(user *data);

void menu_admin_getAll(user *list);
void menu_admin_view(user *list);
user *menu_admin_user(int userID);
user *menu_admin_id(user *list);
void menu_admin_create(user *&list, int &userID);
void menu_admin_alter(user *list, user *data);
void menu_admin_remove(user *&list, user *data);
void menu_admin_ban(user *list, user *data);
void menu_admin_activate(user *list);
void menu_admin_resetPassword(user *list);
void menu_admin(user *&list, int &userID, user *data);