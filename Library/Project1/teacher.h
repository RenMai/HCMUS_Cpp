#pragma once
#include <string>
#include"question.h"
#include"utility.h"

using namespace std;

struct teacher
{
	string *subj;	// array of subject
	int subj_num;	// number of subjectz
};

void menu_teacher_view(question *list, const string &username);
question *menu_teacher_question(const string &name, int questID);
void menu_teacher_create(question *&list, const string &name, int &questID);
void menu_teacher_alter(question *list, const string &name);
void menu_teacher_remove(question *&list, const string &name);