#include "question.h"
#include "user.h"
#include "administrator.h"
#include "teacher.h"
#include "student.h"
#include "utility.h"
#include <iostream>
using namespace std;
void menu_teacher(question *qlist, user *ulist, maxID &maxid, user *data)
{
	system("cls");
	int choice = 0;
	while (choice != 7)
	{
		cout << "1. Display your questions.\n";
		cout << "2. Create a new question.\n";
		cout << "3. Alter an existing question.\n";
		cout << "4. Remove an existing question.\n";
		cout << "5. Change password.\n";
		cout << "6. Update information.\n";
		cout << "7. Log-out.\n";
		input_number("Enter your choice: ", 1, 7, choice);
		switch (choice)
		{
		case 1: menu_teacher_view(qlist, data->name); break;
		case 2: menu_teacher_create(qlist, data->name, maxid.questID); store_question(qlist, maxid.questID); break;
		case 3: menu_teacher_alter(qlist, data->name); store_question(qlist, maxid.questID); break;
		case 4: menu_teacher_remove(qlist, data->name); store_question(qlist, maxid.questID); break;
		case 5: menu_change_password(data); store_user(ulist, maxid.userID); break;
		case 6: menu_update_data(data); store_user(ulist, maxid.userID); break;
		}
	}
}
void menu_student(question *qlist, user *ulist, maxID &maxid, user *data)
{
	system("cls");
	int choice = 0;
	while (choice != 4)
	{
		cout << "1. View questions.\n";
		cout << "2. Change password.\n";
		cout << "3. Update information.\n";
		cout << "4. Log-out.\n";
		input_number("Enter your choice: ", 1, 4, choice);
		switch (choice)
		{
		case 1: menu_student_view(qlist); break;
		case 2: menu_change_password(data); store_user(ulist, maxid.userID); break;
		case 3: menu_update_data(data); store_user(ulist, maxid.userID); break;
		}
	}
}
void main()
{
	// attempt to load user from file
	user *ulist = 0;
	maxID maxid;
	if (!load_user(ulist, maxid.userID))
	{
		cout << "Error loading users. Please check if USER.txt is available for reading." << endl;
		cin.get();
		return;
	}
	// attempt to load question from file
	question *qlist = 0;
	if (!load_question(qlist, maxid.questID))
	{
		cout << "Error loading questions. Please check if QUESTION.txt is available for reading." << endl;
		cin.get();
		return;
	}
	// login
	user *data = login(ulist);
	// go to correct menu based on user type
	switch (data->type)
	{
	case 1: menu_admin(ulist, maxid.userID, data); break;
	case 2: menu_teacher(qlist, ulist, maxid, data); break;
	case 3: menu_student(qlist, ulist, maxid, data); break;
	}
}