#include"question.h"

//load question from file
bool load_question(question*&ques)
{
	ifstream fin;
	fin.open("question.txt");
	if (!fin.is_open())
		return false;	//quick check
	int num; //number of question
	fin >> num;
	if (num == 0) return false;
	string clr;
	getline(fin, clr);//clear  line

	ques = new question;
	question*temp = ques;

	getline(fin, temp->ques);		//load question
	getline(fin, temp->subject);	//load subject
	getline(fin, temp->author);		//load author

	fin >> temp->viewable;			//check if this question viewable to student or not
	getline(fin, clr);				//

	fin >> temp->multians;			//check if this question has multi answer or not
	getline(fin, clr);

	getline(fin, temp->ans);		//load answer
	if (temp->multians == 0)
	{
		temp->option = NULL;
		return false;
	}
	else
	{
		temp->option = new opt;
		getline(fin, temp->	option->option);
		temp->option->next = NULL;
		opt*cur = temp->option;
		for (int i = 1; i < temp->multians; ++i)
		{ 
			cur->next = new opt;
			cur = cur->next;
			getline(fin, cur->option);
			cur->next = NULL;
		}
	}
	temp->next = NULL;
	for (int j = 1; j < num; ++j)
	{
		temp->next = new question;
		temp = temp->next;
		getline(fin, temp->ques);		//load question
		getline(fin, temp->subject);	//load subject
		getline(fin, temp->author);		//load author
		fin >> temp->viewable;			//check if this question viewable to student or not
		getline(fin, clr);				//clear
		fin >> temp->multians;			//check if this question has multi answer or not
		getline(fin, clr);				//clear
		getline(fin, temp->ans);		//load answer
		if (temp->multians == 0)
		{
			temp->option = NULL;
			return false;
		}
		else
		{
			temp->option = new opt;
			getline(fin, temp->option->option);
			temp->option->next = NULL;
			opt*cur = temp->option;
			for (int i = 1; i < temp->multians; ++i)
			{
				cur->next = new opt;
				cur = cur->next;
				getline(fin, cur->option);
				cur->next = NULL;
			}
		}
		temp->next = NULL;
	}

	fin.close();
	return true;
}
//display a question
bool display_question(question*ques)
{
	if (!ques)
		return false;
		cout << "Question:" << ques->ques << endl;
		cout << "Subject:" << ques->subject << endl;
		cout << "Author:" << ques->author << endl;
		if (ques->viewable) cout << "Viewable" << endl;
		else cout << "Not viewable" << endl;
		cout << "Number of answer:" << ques->multians << endl;
		cout << "List of option: "; 
		display_option(ques);
		cout << "The true answer: " << ques->ans << endl;
	return true;
}
//write question by hand
bool write_hand(question*&ques)
{
	ques->option = new opt;
	cin >> ques->ques;
	cin >> ques->subject;
	cin >> ques->author;
	cin >> ques->viewable;
	cin >> ques->multians;
	cin >> ques->option->option;
	opt*temp = ques->option;
	for (int i = 1; i < ques->multians; ++i)
	{
		temp->next = new opt;
		temp = temp->next;
		cin >> temp->option;
		temp->next = NULL;
	}
	cin >> ques->ans;
	return true;
}
//display the option of the question
bool display_option(question*ques)
{
	if (ques == NULL)
		return false;
	while (ques->option != NULL)
	{
		cout << ques->option->option << "\t";
		ques->option = ques->option->next;
	}
	cout << endl;
	return true;
}
//display all question
void display_all_question(question*ques)
{
	while (ques != NULL)
	{
		display_question(ques);
		ques = ques->next;
	}
}
question* access(question*ques, int n)
{
	if (ques == NULL) return NULL;
	question*temp = ques;
	for (int i = 1; i < n; ++i)
	{
		temp = temp->next;
	}
	return temp;
}
int count_ques(question*ques)
{
	int k = 0;
	if (ques == NULL) return k;
	question*temp = ques;
	while (temp != NULL)
	{
		++k;
		temp = temp->next;
	}
	return k;
}
void filter(question*&head, question*&notviewable)
{
	question*viewable = NULL, *cur;
	notviewable = NULL;
	while (head)
	{
		cur = head;
		head = head->next;
		cur->next = NULL;
		if (cur->viewable)	//condiction
		{
			add_ques_tail(viewable, cur);
		}
		else add_ques_tail(notviewable, cur);
	}
	head = viewable;
}
void add_ques_tail(question*&head, question*p)
{
	if (!head)
	{
		head = p;
		return;
	}
	question*cur = head;
	while (cur->next)
		cur = cur->next;
	cur->next = p;
}
