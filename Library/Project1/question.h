#pragma once
#include<string>
#include<iostream>
using namespace std;

struct question
{
	string *subj, *opt;					// array of subject,option
	string ques, auth, ans;			// question,author,answer
	int subj_num, opt_num, ans_num;			// the number of subject,option,answer
	bool viewable;					// check if this question viewable to student
	int id;					// question id
	question *next;			// link to the next question in list
};

bool load_question(question *&list, int &maxID);		// load all questions from files
bool store_question(question *list, int maxID);			// store all questions to file
void reset_question(question *&list);		// delete all questions from list

void copy_question(question &target, const question &quest);		// copy question from quest to target
void add_question(question *&list, question *quest);			// add a question to head of list
bool remove_question(question *&list, int ID);		// remove a question having ID from list

question *search_question(question *list, const question &filter);			// return a list of question based on search filterz
void display_questions(question *list, bool viewans);