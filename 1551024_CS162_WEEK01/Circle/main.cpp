#include "Circle.h"

int main()
{
	char input;
	cout << "Enter a to input the circle by keyboard; Enter b to input the circle by text : " << endl;
	cin >> input;
	Circle circle[1];
	if (input == 'a')
	{
		input_circle(circle[0]);
	}
	else if (input == 'b') input_circle_text(circle);
	else
	{
		cout << "Your input is valid. Please try again." << endl;
		return 0;
	}
	output_circle(circle[0]);
	output_circle_text(circle[0]);
	cout << "The area of the circle is: " << area(circle[0]) << endl;
	cout << "The perimeter of the circle is: " << perimeter(circle[0]) << endl;
	return 0;
}