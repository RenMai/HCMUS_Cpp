#pragma once
#include"sub.h"
#include"conio.h"
#include<fstream>
#include<iostream>
#include<string>
#include "date.h"
using namespace std;
struct user
{
public:
	string username;
	string pass;
	string name;
	date birthday;
	string address;
	bool sex;
	int type;
	bool status;
	sub* subject;
	user*next;
	//login function
	//return pointer pointingat loging account.
	user* login();
	//write the list of user down to file.
	void write_an_user(ofstream& a);
	void display();

	//update function
	//update username;
	void update_username(user*head);
	//update password
	void update_pass();
	//update name
	void update_name();
	//update status
	void update_status();
	//update type
	void update_type();
	//update birthday
	void update_birthday();
	//update address
	void update_address();
	//update sex
	void update_sex();
	//update subject
	void update_subject();
	//update all information except password.
	void  update_info();
	//check if the user already in the list.
	bool find_username(string a);
	//return the address of the node before current node
	user*before(user*&head);
	//remove this node from the list
	//return pointer control that node
	user* remove(user*&head);
};
void write_user();
//encode and decode a string
string decode(string a);
//load data from file
bool load(user*&);
//display all information of an user
bool display_an_user(user*);
// delete all subje	ct in the list
void del_all(user*&);
//add an user to the list
//user* is pointer control new node
void add_user(user*&);
//write all user to file
void write_all_user(user*);
//count user
int count_user(user*);
//reuturn address of user at position k
user* access(user*&head, int k);
//return the position of cur in SLL head 
int pos(user*&head, user*cur);
//interface for user using find, sort and filter.
//input head pointer of SLL
//return the pointer control the user chosen
user* menu_filter_sort(user*&head);
user* menu_filter_by_username(user*&);
user* menu_filter_by_status(user*&);
user* menu_filter_by_type(user*&);
void sort_by_username(user*&);
user*menu_for_last_choice(user*&, int k);
void filter_by_username(user*& result, user*& rest, string user);
void filter_by_type(user*& result, user*& rest, int mode);
void filter_by_status(user*& result, user*& rest);
//add user at the end of list
void add_tail(user*&head, user*cur);