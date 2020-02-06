#include "teacher.h"

void menu_teacher_view(question *list, const string &username)
{
	// enter question search criteria
	question filter;
	filter.auth = username;
	filter.subj = new string[1];
	cout << "You will now enter search criteria.\nSearched strings do not need to totally match actual strings to be displayed.\nLeave a field blank if you do not wish to filter that field." << endl;
	input_string("Enter subject: ", filter.subj[0]);
	input_string("Enter question: ", filter.ques);
	// perform filtering, display result
	question *res = search_question(list, filter);
	if (res == 0)
	{
		cout << "No result matches your criteria." << endl;
		system("pause");
		system("cls");
		return;
	}
	display_questions(res, true);
	cin.get();
	system("cls");
}
question *menu_teacher_question(const string &name, int questID)
{
	// input new question info
	question *quest = new question;
	quest->auth = name;
	input_number("Enter number of subjects: ", 1, 999, quest->subj_num);
	quest->subj = new string[quest->subj_num];
	for (int i = 0; i < quest->subj_num; ++i)
		input_string("Enter subject name: ", quest->subj[i]);
	input_string("Enter question: ", quest->ques);
	input_number("Enter number of options: ", 1, 999, quest->opt_num);
	quest->opt = new string[quest->opt_num];
	for (int i = 0; i < quest->opt_num; ++i)
		input_string("Enter option: ", quest->opt[i]);
	input_number("Enter number of answers: ", 1, 999, quest->ans_num);
	input_string("Enter answer: ", quest->ans);
	input_yesno("Is this question viewable? ", quest->viewable);
	quest->id = questID;
	return quest;
}
void menu_teacher_create(question *&list, const string &name, int &questID)
{
	question *quest = menu_teacher_question(name, ++questID);
	add_question(list, quest);
	cout << "The question has been created" << endl;
	system("pause");
	system("cls");
}
void menu_teacher_alter(question *list, const string &name)
{
	// enter question id to alter
	int id;
	input_number("Enter ID of question to alter:", 0, 2147483647, id);
	// find question with correct id
	question *find = list;
	while (find != 0 && find->id != id)
		find = find->next;
	// if id not found
	if (find == 0)
	{
		cout << "The ID you entered is non-existent." << endl;
		cin.get();
	}
	// if not your question
	else if (find->auth != name)
	{
		cout << "You cannot alter questions that are not yours." << endl;
		cin.get();
	}
	else
	{
		// add new question (temporary), copy info, delete it
		question *quest = menu_teacher_question(find->auth, find->id);
		copy_question(*find, *quest);
		delete quest;
	}
}
void menu_teacher_remove(question *&list, const string &name)
{
	// enter question id to remove
	int id;
	input_number("Enter ID of question to remove:", 0, 2147483647, id);
	// find question with correct id
	question *find = list;
	while (find != 0 && find->id != id)
		find = find->next;
	// if id not foudn
	if (find == 0)
	{
		cout << "The ID you entered is non-existent." << endl;
		cin.get();
	}
	// if not your question
	else if (find->auth != name)
	{
		cout << "You cannot remove other author's questions." << endl;
		cin.get();
	}
	else
	{
		remove_question(list, id);
		cout << "Removal completed." << endl;
	}
}