#include"question.h"
#include<fstream>
using namespace std;

bool load_question(question*&list, int &maxID)
{
	ifstream fin;
	fin.open("question.txt");
	if (!fin.is_open())
		return false;	//quick check
	reset_question(list);		// reset input list
	string clr;
	fin >> maxID;
	while (!fin.eof())
	{
		question*temp = new question;
		// load bool and int first
		fin >> temp->viewable >> temp->subj_num >> temp->opt_num >> temp->ans_num;	// viewable + number of subject,option,answer
		fin >> temp->id;		// id
		getline(fin, clr);

		// load string
		getline(fin, temp->auth);		// load author
		getline(fin, temp->ques);		// load question
		getline(fin, temp->ans);		// load answer

		// load array of string
		temp->subj = new string[temp->subj_num];		// load array of subject
		for (int i = 0; i < temp->subj_num; ++i)
			getline(fin, temp->subj[i]);
		temp->opt = new string[temp->opt_num];			// load array of option
		for (int i = 0; i < temp->opt_num; ++i)
			getline(fin, temp->opt[i]);

		// add new question to head of list
		temp->next = list;
		list = temp;
	}
	fin.close();
	return true;
}
bool store_question(question*list, int maxID)
{
	ofstream fout;
	fout.open("question.txt");
	if (!fout.is_open())
		return false;	//quick check
	question*temp = list;
	// travel from head to tail, write each node to file (store field the same order as load)
	fout << maxID;
	while (temp != 0)
	{
		// store bool and int
		fout << endl << temp->viewable << " " << temp->subj_num << " " << temp->opt_num << " " << temp->ans_num;	// viewable + number of subject,option,answer
		fout << " " << temp->id;		// id
		// store string
		fout << endl << temp->auth;		// load author
		fout << endl << temp->ques;		// load question
		fout << endl << temp->ans;		// load answer

		// store array of string
		for (int i = 0; i < temp->subj_num; ++i)		// store array of subject
			fout << endl << temp->subj[i];
		for (int i = 0; i < temp->opt_num; ++i)			// store array of option
			fout << endl << temp->opt[i];

		// to next question
		temp = temp->next;
	}
	fout.close();
	return true;
}
void reset_question(question*&list)
{
	while (list != 0)
	{
		// move head to next node and delete old head
		question*temp = list;
		list = list->next;
		delete temp;
	}
}
void copy_question(question &target, const question &quest)
{
	// Copy array of subjects
	target.subj_num = quest.subj_num;
	target.subj = new string[target.subj_num];
	for (int i = 0; i < quest.subj_num; ++i)
		target.subj[i] = quest.subj[i];
	// Copy array of options
	target.opt_num = quest.opt_num;
	target.opt = new string[target.opt_num];
	for (int i = 0; i < quest.opt_num; ++i)
		target.opt[i] = quest.opt[i];
	// Copy other info
	target.auth = quest.auth;
	target.ques = quest.ques;
	target.ans = quest.ans;
	target.ans_num = quest.ans_num;
	target.viewable = quest.viewable;
	target.id = quest.id;
}
void add_question(question *&list, question *quest)
{
	quest->next = list;
	list = quest;
}
bool remove_question(question*&list, int ID)
{
	// if list is empty, do nothing
	if (list == 0)
		return false;
	// if ID is at head, remove head
	if (list->id == ID)
	{
		question *temp = list;
		list = list->next;
		delete temp;
		return true;
	}

	// go to question node before ID
	question *cur = list;
	while (cur->next != 0 && cur->id != ID)
		cur = cur->next;
	// ID not found
	if (cur->next == 0)
		return false;
	// delete next node, reset links
	question *temp = cur->next;
	cur->next = temp->next;
	delete temp;
	return true;
}

question *search_question(question *list, const question &filter)
{
	question *res = 0;
	question *cur = list;
	while (cur != 0)
	{
		// search by author, question, subject, only check substring found, not whole string match
		if (filter.auth != "" && cur->auth.find(filter.auth) == -1)		// if authors don't match, to next question
			cur = cur->next;
		else if (filter.ques != "" && cur->ques.find(filter.ques) == -1)		// if questions don't match, to next question
			cur = cur->next;
		else
		{
			for (int i = 0; i < cur->subj_num; ++i)
				if (cur->subj[i].find(filter.subj[0]) != -1)
				{
					// clone question and add to res at head
					question *qtemp = new question;
					copy_question(*qtemp, *cur);
					add_question(res, qtemp);
					break;		// stop checking subjects
				}
			cur = cur->next;		// to next question
		}
	}
	return res;
}
void display_questions(question *list, bool viewans)
{
	question *cur = list;
	while (cur != 0)
	{
		// display id
		cout << "Question ID: " << cur->id << endl;
		// display author, subject
		cout << "Author: " << cur->auth << endl;
		cout << "Subject: ";
		if (cur->subj_num > 0)
			cout << cur->subj[0];
		for (int i = 1; i < cur->subj_num; ++i)
			cout << "; " << cur->subj[i];
		cout << endl;
		// display question, option
		cout << "Question: " << cur->ques << endl;
		for (int i = 0; i < cur->opt_num; ++i)
			cout << i + 1 << ". " << cur->opt[i] << endl;
		// display answer
		if (viewans)
		{
			cout << "Answers: ";
			if (cur->ans_num == 1)
				cout << cur->ans[0];
			else
				for (int i = 0; i < cur->ans_num; ++i)
					cout << "\n\t" << cur->ans[i];
		}
		cout << endl;
		cur = cur->next;
	}
}