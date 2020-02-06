#include<string>
#include<iostream>
#include<fstream>
#include"user.h"
using namespace std;
struct opt
{
public:
	string option;		//list of option
	opt* next;
};
struct question
{
public:
	string ques;		//question
	string subject;		//name of subject
	string author;		//name of author
	bool viewable;		//check if this question viewable to student.
	int multians;		//the number of answer
	question *next;		//link to the next question
	opt *option;
	string ans;			//the true answer

};

bool load_question(question*&ques);
bool display_question(question*ques);
bool write_hand(question*&ques);
bool display_option(question*ques);
void display_all_question(question*ques);
question* access(question*ques,int n);
int count_ques(question*ques);
bool teacher_view(question*ques, user *us);
void filter(question*&head, question*&notviewable);
void add_ques_tail(question*&head, question*p);