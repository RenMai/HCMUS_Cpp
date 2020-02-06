#include"user.h"
#include<fstream>
#include<iostream>
#include"administrator.h"

bool load_user(user*& head, int &maxID)
{
	ifstream in;
	in.open("USER.txt");
	if (!in.is_open())
		return false;
	reset_user(head);		// reset list of user
	string trash;
	in >> maxID;
	while (!in.eof())
	{
		user *temp = new user;
		// load bool and int first
		in >> temp->sex >> temp->status;									// load sex, status
		in >> temp->birthday.dd >> temp->birthday.mm >> temp->birthday.yy;		// load birthday
		in >> temp->type;													// load user type
		in >> temp->id;				// load id
		// if this is a teacher, load subjects
		if (temp->type == 2)
		{
			teacher *tt = temp->teach = new teacher;
			in >> tt->subj_num;
			if (tt->subj_num > 0)
				tt->subj = new string[tt->subj_num];
			getline(in, trash);
			for (int i = 0; i < tt->subj_num; ++i)
				getline(in, tt->subj[i]);
		}
		else
		{
			temp->teach = 0;
			getline(in, trash);
		}
		// load string
		getline(in, temp->username);		// load username
		getline(in, temp->pass);			// laod password
		getline(in, temp->name);			// load full name
		getline(in, temp->address);			// load address
		// add new user to head
		temp->next = head;
		head = temp;
	}
	in.close();
	return true;
}
bool store_user(user* head, int maxID)
{
	ofstream out;
	out.open("USER.txt");
	if (!out.is_open())
		return false;
	user *temp = head;
	// travel from head to tail, write each node to file (store field the same order as load)
	out << maxID;
	while (temp != 0)
	{
		// store bool and int
		out << endl << temp->sex << " " << temp->status;									// store sex, status
		out << " " << temp->birthday.dd << " " << temp->birthday.mm << " " << temp->birthday.yy;		// store birthday
		out << " " << temp->type;															// store user type
		out << " " << temp->id;			// store id
		// if this is a teacher, store subjects
		if (temp->type == 2)
		{
			teacher *tt = temp->teach;
			out << " " << tt->subj_num;
			for (int i = 0; i < tt->subj_num; ++i)
				out << endl << tt->subj[i];
		}

		// store string
		out << endl << temp->username;		// store username
		out << endl << temp->pass;			// store password
		out << endl << temp->name;			// store ful name
		out << endl << temp->address;		// store address

		// to next user
		temp = temp->next;
	}
	out.close();
	return true;
}
void reset_user(user*& head)
{
	while (head != 0)
	{
		// move head to next, delete old ones until none left
		user *temp = head;
		head = head->next;
		delete temp;
	}
}
void copy_user(user &target, const user &src)
{
	// Copy string
	target.username = src.username;
	target.pass = src.pass;
	target.name = src.name;
	target.address = src.address;
	// Copy bool and int
	target.birthday = src.birthday;
	target.sex = src.sex;
	target.status = src.status;
	target.type = src.type;
	// If this is a teacher, copy teacher data
	if (target.type == 2)
	{
		teacher *tt = target.teach = new teacher;
		tt->subj_num = src.teach->subj_num;
		tt->subj = new string[tt->subj_num];
		for (int i = 0; i < tt->subj_num; ++i)
			tt->subj[i] = src.teach->subj[i];
	}
	else
		target.teach = 0;
	target.id = src.id;
}
void add_user(user *&list, user *account)
{
	account->next = list;
	list = account;
}
bool remove_user(user *&list, int ID)
{
	// if list is empty, do nothing
	if (list == 0)
		return false;
	// if ID is at head, remove head
	if (list->id == ID)
	{
		user *temp = list;
		list = list->next;
		delete temp;
		return true;
	}

	// go to user node before ID
	user *cur = list;
	while (cur->next != 0 && cur->id != ID)
		cur = cur->next;
	// ID not found
	if (cur->next == 0)
		return false;
	// delete next node, reset links
	user *temp = cur->next;
	cur->next = temp->next;
	delete temp;
	return true;
}

user *search_user(user *list, const user &filter)
{
	user *res = 0;
	user *cur = list;
	while (cur != 0)
	{
		// search by username, fullname, sex, status, type, only check substring found, not whole string match
		if (cur->username.find(filter.username) == -1)		// if usernames don't match, to next user
			cur = cur->next;
		/*else if (cur->name.find(filter.name) == -1)		// if fullnames don't match, to next user
			cur = cur->next;
		else if (cur->sex != filter.sex)			// if sexes don't match, to next user
			cur = cur->next;
		else if (cur->status != filter.status)		// if statuses don't match, to next user
			cur = cur->next;
		else if (cur->type != filter.type)		// if types don't match, to next user
			cur = cur->next;*/
		else
		{
			// clone user and add to res at head
			user *qtemp = new user;
			copy_user(*qtemp, *cur);
			add_user(res, qtemp);
			cur = cur->next;		// to next user
		}
	}
	return res;
}
void display_user(user *list)
{
	user *cur = list;
	while (cur != 0)
	{
		// display id
		cout << "User ID: " << cur->id << endl;
		// display username, fullname, address
		cout << "Username: " << cur->username << endl;
		cout << "Full name: " << cur->name << endl;
		cout << "Address: " << cur->address << endl;
		// display birthday
		cout << "Date of birth: " << cur->birthday.dd << "/" << cur->birthday.mm << "/" << cur->birthday.yy << endl;
		// display sex
		cout << "Sex: " << (cur->sex ? "male" : "female") << endl;
		// display status
		cout << "Status: " << (cur->status ? "activated" : "deactivated") << endl;
		// display type
		cout << "User type: ";
		switch (cur->type)
		{
		case 1: cout << "administrator\n"; break;
		case 2: cout << "teacher\n"; break;
		case 3: cout << "student\n"; break;
		default: cout << "unknown type? (O.o)\n"; break;
		}
		// if teacher, display teacher data
		if (cur->type == 2)
		{
			cout << "Subjects: ";
			if (cur->teach->subj_num > 0)
				cout << cur->teach->subj[0];
			for (int i = 1; i < cur->teach->subj_num; ++i)
				cout << " " << cur->teach->subj[0];
			cout << endl;
		}
		cur = cur->next;
	}
}

// login menu, let user type username, password or exit
user *login(user *list)
{
	string uname, password;
	user *data = 0;
	while (data == 0)
	{
		input_string("Type username: ", uname);
		input_string("Type password: ", password);
		user *data = list;
		while (data != 0)
		{
			if (data->username == uname && data->pass == encrypt(password))
				return data;
			data = data->next;
		}
		if (data == 0)
			cout << "Your username and password do not match. Please type again" << endl;
		else if (!data->status)
		{
			cout << "This account is currently banned. You cannot log in.";
			cin.get();
			data = 0;
		}
	}
	return data;
}
void menu_change_password(user *data)
{
	string oldpass, newpass;
	while (true)
	{

		input_string("Enter current password: ", oldpass);
		input_string("Enter new password: ", newpass);
		if (data->pass != encrypt(oldpass))
			cout << "You entered the current password incorrectly. Please type again." << endl;
		else
		{
			data->pass = encrypt(newpass);
			cout << "Password successfully changed." << endl;;
			break;
		}
	}
	system("pause");
	system("cls");
}
void menu_update_data(user *data)
{
	// change fullname,address
	input_string("Enter full name: ", data->name);
	input_string("Enter address: ", data->address);
	// change birthday
	cout << "Enter date of birth (dd/mm/yyyy) ";
	while (true)
	{
		input_number("", 1, 31, data->birthday.dd);
		input_number("", 1, 12, data->birthday.mm);
		input_number("", 1, 9999, data->birthday.yy);
		if (data->birthday.check())
			break;
		cout << "The entered date is invalid. Please type again: ";
	}
	// change sex
	input_yesno("Enter sex (yes for male, no for female): ", data->sex);
	cout << "Your info has been updated successfully" << endl;
	system("pause");
	system("cls");
}

void menu_admin_getAll(user *list)
{
	user *cur = list;
	while (cur != 0)
	{
		cout << cur->username << " - " << cur->id << endl;
		cur = cur->next;
	}
	system("pause");
	system("cls");
}
void menu_admin_view(user *list)
{
	// enter user search criteria
	user filter;
	cout << "You will now enter search criteria.\nSearched strings do not need to totally match actual strings to be displayed.\n";
	input_string("Enter username: ", filter.username);
	user *res = search_user(list, filter);
	if (res == 0)
	{
		cout << "No result matches your criteria.\n";
		return;
	}
	display_user(res);
	cin.get();
	system("cls");
}
user *menu_admin_user(int userID)
{
	// input username,fullname,address
	user *account = new user;
	account->pass = encrypt("1234");
	input_string("Enter username: ", account->username);
	input_string("Enter full name: ", account->name);
	input_string("Enter address: ", account->address);
	// input birthday
	cout << "Enter date of birth (dd/mm/yyyy) ";
	while (true)
	{
		input_number("", 1, 31, account->birthday.dd);
		input_number("", 1, 12, account->birthday.mm);
		input_number("", 1, 9999, account->birthday.yy);
		if (account->birthday.check())
			break;
		cout << "The entered date is invalid. Please type again: ";
	}
	// input sex
	account->status = true;
	input_yesno("Enter sex (yes for male, no for female): ", account->sex);
	// input type
	input_number("Enter user type (1/2/3 for administrator/teacher/student): ", 1, 3, account->type);
	// if this is a new teacher, input teacher data
	if (account->type == 2)
	{
		teacher *tt = account->teach = new teacher;
		input_number("Enter number of subjects: ", 1, 999, tt->subj_num);
		tt->subj = new string[tt->subj_num];
		for (int i = 0; i < tt->subj_num; ++i)
			input_string("Enter subject name: ", tt->subj[i]);
	}
	else
		account->teach = 0;
	account->id = userID;
	return account;
}
user *menu_admin_id(user *list)
{
	int id;
	input_number("Enter ID of user:", 0, 2147483647, id);
	// find user with correct id
	user *find = list;
	while (find != 0 && find->id != id)
		find = find->next;
	// if id not found
	if (find == 0)
	{
		cout << "The ID you entered is non-existent.";
		cin.get();
	}
	return find;
}
void menu_admin_create(user *&list, int &userID)
{
	user *account = menu_admin_user(++userID);
	add_user(list, account);
	cout << "Account has been created successfully." << endl;
	system("pause");
	system("cls");
}
void menu_admin_alter(user *list, user *data)
{
	int id;
	user *find = menu_admin_id(list);
	if (find != 0)
	{
		if (find->id == data->id)
		{
			cout << "You cannot alter your own account.\n";
			return;
		}
		// add new user (temporary), copy info, delete it
		user *account = menu_admin_user(find->id);
		copy_user(*find, *account);
		delete account;
	}
	system("cls");
}
void menu_admin_remove(user *&list, user *data)
{
	user *find = menu_admin_id(list);
	if (find != 0)
	{
		if (find->id == data->id)
		{
			cout << "You cannot remove your own account.\n";
			return;
		}
		bool confirm;
		input_yesno("Are you sure you want to remove this account? This action cannot be undone. ", confirm);
		if (confirm)
		{
			remove_user(list, find->id);
			cout << "Removal completed.";
			cin.get();
		}
	}
	system("pause");
	system("cls");
}
void menu_admin_ban(user *list, user *data)
{
	user *find = menu_admin_id(list);
	if (find != 0)
	{
		if (find->id == data->id)
		{
			cout << "You cannot ban your own account." << endl;
			return;
		}
		bool confirm;
		input_yesno("Are you sure you want to ban this account? This may adversely affect the user. ", confirm);
		if (confirm)
		{
			find->status = false;
			cout << "Account successfully banned." << endl;
			cin.get();
		}
		system("pause");
		system("cls");
	}
}
void menu_admin_activate(user *list)
{
	user *find = menu_admin_id(list);
	if (find != 0)
	{
		find->status = true;
		cout << "Account successfully activated." << endl;
		cin.get();
	}
	system("cls");
}
void menu_admin_resetPassword(user *list)
{
	user *find = menu_admin_id(list);
	if (find != 0)
	{
		find->pass = encrypt("1234");
		cout << "Account password reset to '1234'";
		cin.get();
	}
	system("cls");
}
void menu_admin(user *&list, int &userID, user *data)
{
	system("cls");
	int choice = 0;
	while (choice != 11)
	{
		cout << "0. Get ALL username.\n";
		cout << "1. View users.\n";
		cout << "2. Create a new account.\n";
		cout << "3. Update a user's information.\n";
		cout << "4. Reset a user's password.\n";
		cout << "5. Ban a user.\n";
		cout << "6. Activate/Unban a user.\n";
		cout << "7. Remove an account.\n";
		cout << "8. Print xml file of accounts.\n";
		cout << "9. Change password.\n";
		cout << "10. Update information.\n";
		cout << "11. Log-out.\n";
		input_number("Enter your choice: ", 0, 11, choice);
		switch (choice)
		{
		case 0: menu_admin_getAll(list); break;
		case 1: menu_admin_view(list); break;
		case 2: menu_admin_create(list, userID); store_user(list, userID); break;
		case 3: menu_admin_alter(list, data); store_user(list, userID); break;
		case 4: menu_admin_resetPassword(list); store_user(list, userID); break;
		case 5: menu_admin_ban(list, data); store_user(list, userID); break;
		case 6: menu_admin_activate(list); store_user(list, userID); break;
		case 7: menu_admin_remove(list, data); store_user(list, userID); break;
		case 8: output_xml(list); break;
		case 9: menu_change_password(data); store_user(list, userID); break;
		case 10: menu_update_data(data); store_user(list, userID); break;
		}
	}
}