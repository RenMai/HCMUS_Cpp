#include"APCS.h"

void input_student(APCS &x)
{

	cout << "Enter student ID:" << endl;
	cin >> x.ID;
	cout << "Enter student name:" << endl;
	cin.getline(x.name, 100, '\n');
	cout << "Enter the number of course the student enrolled:";
	cin >> x.ncourse;
	for (int i = 1; i <= x.ncourse; ++i)
	{
		input_course(x.courid[i]);
	}

}
void nput_course(int &n)
{
	cout << "Enter course id:";
	cin >> n;
	cout << "Enter cour name";
	cin.getline(n.name)
}