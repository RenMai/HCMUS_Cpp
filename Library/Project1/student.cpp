#include"student.h"

void menu_student_view(question *list)
{
	// enter question search criteria
	question filter;
	filter.subj = new string[1];
	cout << "You will now enter search criteria.\nSearched strings do not need to totally match actual strings to be displayed.\nLeave a field blank if you do not wish to filter that field." << endl;
	input_string("Enter author: ", filter.auth);
	input_string("Enter subject: ", filter.subj[0]);
	input_string("Enter question: ", filter.ques);
	input_yesno("Display answers? ", filter.viewable);
	// perform filtering, display result
	question *res = search_question(list, filter);
	if (res == 0)
	{
		cout << "No result matches your criteria." << endl;
		system("pause");
		system("cls");
		return;
	}
	display_questions(res, filter.viewable);
	cin.get();
	system("pause");
	system("cls");
}