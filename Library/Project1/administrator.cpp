#include "administrator.h"
#include <iostream>
#include <fstream>
using namespace std;

void output_xml(const user *list)
{
	ofstream fout;
	fout.open("USER.xml");
	if (!fout.is_open())
	{
		cout << "Cannot write list of user to user.xml file." << endl;
		cin.get();
		return;
	}
	const user *cur = list;
	// travel from head to tail, write each node to file (store field the same order as load)
	fout << "<?xml version = \"1.0\" encoding = \"UTF-8\" standalone = \"no\" ?>\n";
	while (cur != 0)
	{
		fout << "<User>\n";
		fout << "\t<UserID>" << cur->id << "</UserID>\n";
		fout << "\t<Username>" << cur->username << "</Username>\n";
		fout << "\t<Fullname>" << cur->name << "</Fullname>\n";
		fout << "\t<Gender>" << (cur->sex ? "male" : "female") << "</Gender>\n";
		fout << "\t<DateOfBirth>" << cur->birthday.dd << "/" << cur->birthday.mm << "/" << cur->birthday.yy << "</DateOfBirth>\n";
		fout << "\t<Address>" << cur->address << "</Address>\n";
		fout << "\t<Status>" << (cur->status ? "activated" : "deactivated") << "</Status>\n";
		// output type
		fout << "\t<UserType>";
		switch (cur->type)
		{
		case 0: fout << "administrator"; break;
		case 1: fout << "teacher"; break;
		case 2: fout << "student"; break;
		default: fout << "wtf? how come?"; break;
		}
		fout << "</UserType>\n";
		// if teacher, output subjects
		if (cur->type == 2)
		{
			fout << "\t<Subjects>\n";
			for (int i = 0; i < cur->teach->subj_num; ++i)
				fout << "\t\t<Subj>" << cur->teach->subj[i] << "</Subj>\n";
			fout << "\t</Subjects>\n";
		}
		cur = cur->next;
	}
	fout.close();
	cout << "Printed" << endl;
	system("pause");
	system("cls");
}