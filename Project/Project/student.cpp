#include"student.h"
#include<string>
#include<iostream>

//search by subject
void searchsub(question *q)
{
	int k = 0;
	question *ques = q;
	string subj;
	cout << "Enter the name subject: ";
	cin.get();
	getline(cin, subj);
	while (ques != NULL)
	{
		transform(subj.begin(), subj.end(), subj.begin(), ::tolower);	
		transform(ques->subject.begin(), ques->subject.end(), ques->subject.begin(), ::tolower);
		//transform 2 string to lowcase to compare.
		if (subj.compare(ques->subject) == 0)	//find what subject the question is.
		{
			if (ques->viewable == 1)
			{
				++k;	//count the question.
				cout << k << ". " << ques->ques << endl;
				cout << "Do you want to view the answer?(y/n)" << endl;
				char y;
				cin >> y;
				if (y == 'y' || y == 'Y')
					cout << "The answer is: " << ques->ans << endl;
			}
		}
		ques = ques->next;	//check the	next question in the list
	}
	if (k == 0) cout << "There's no question in this subject." << endl;
}  
//search by author
void searchaut(question *q)
{
	int k = 0;
	question *ques = q;
	string author;
	cout << "Enter the name of the author: ";
	cin.get();
	getline(cin, author);
	while (ques != NULL)
	{
		transform(author.begin(), author.end(), author.begin(), ::tolower);
		transform(ques->author.begin(), ques->author.end(), ques->author.begin(), ::tolower);
		//transform 2 string to lowcase to compare.
		if (author.compare(ques->author) == 0)	//find the author.
		{
			if (ques->viewable==1)
			{
				++k;	//count the question.
				cout << k << ". " << ques->ques << endl;
				char y;
				cout << "Do you want to view the answer?(y/n)" << endl;
				cin >> y;
				if (y == 'y' || y == 'Y')
					cout << "The answer is: " << ques->ans << endl;
			}
		}
		ques = ques->next;	//check the	next question in the list
	}
	if (k == 0) cout << "There's no author name: " << author << endl;
}
//search by keywod
void searchkey(question *q)
{
	question*ques = q;
	int k = 0;
	string key;
	cout << "Enter the question: " << endl;
	cin.get();
	getline(cin, key);
	while (ques != NULL)
	{
		//search keyword 1 by 1
		for (int i = 0; i < ques->ques.length(); ++i)
		{
			if (ques->ques[i] == key[0])
			{
				for (int j = 0; j < key.length(); ++j)
				{
					if (ques->ques[i + j] != key[j])
						break;
					if (j == key.length() - 1)
					{
						if (ques->viewable == 1)
						{
							cout << "The question is: " << ques->ques << endl;
							++k;	//count the question.
							char y;
							cout << "Do you want to view the answer?(y/n)" << endl;
							cin >> y;
							if (y == 'y' || y == 'Y')
								cout << "The answer is: " << ques->ans << endl;
						}
					}

				}
			}
		}
		ques = ques->next;	//check the	next question in the list
	}
	if (k == 0) cout << "Can't find any question!\n";
} 
void student
{
	int k, n;
	//question*list = new question;
	//write_hand(list);
	//display_question(list);
	question*list_question;
	question*tail = NULL;
	load_question(list_question);
	//filter(list_question, tail);
	//display_all_question(list_question);
	//cout << "----------------------------------------------------" << endl;
	//display_all_question(tail);

	cout << count_ques(list_question) << endl;
	cout << "1. Search the question." << endl;
	cout << "2. Update information." << endl;
	cout << "3. Log out" << endl;
	cout << "4. Exit" << endl;
	cin >> n;
	switch (n)
	{
	case 1:
		cout << "1. Search by subject." << endl;
		cout << "2. Search by author." << endl;
		cout << "3. Search by keyword." << endl;
		cin >> k;
		switch (k)
		{
		case 1:
			searchsub(list_question);
			break;
		case 2:
			searchaut(list_question);
			break;
		case 3:
			searchkey(list_question);
			break;
		default:
			if (k != 1 || k != 2 || k != 3)
				cout << "Input Valid" << endl;
			break;
		}
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		//chay ham write down
	}
	system("pause");
}