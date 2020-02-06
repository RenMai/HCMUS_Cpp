#include "Point2D.h"

int main()
{
	char input;
	float a = 0;
	cout << "Enter a to input the point by keyboard; Enter b to input the point by text : " << endl;
	cin >> input;
	Point point[2];
	if (input == 'a')
	{
		input_point(point[0]);
	}
	else if (input == 'b') input_point_text(point);
	else
	{
		cout << "Your input is valid. Please try again." << endl;
		return 0;
	}
	cout << "Your point: "; output_point(point[0]);
	output_point_text(point[0]);
	update_x(point[0]);
	update_y(point[0]);
	get_x(point[0]);
	get_y(point[0]);
	cout << "Enter the second point." << endl;
	input_point(point[1]);
	a = distance_point(point[0], point[1]);
	cout << "The Euclidean distance between 2 point is: " << a << endl;
	if (first(point[0])) cout << "This point belongs to the first quadrant" << endl;
	else  if (third(point[0])) cout << "This point belongs to the third quadrant" << endl;
	else cout << "This point doesn't belongs to the first quadrant or the third quadrant" << endl;
	cout << "Move a point to up by one unit. "; output_point(move_up(point[0]));
	cout << "Move a point to bottom by one unit. "; output_point(move_down(point[0]));
	cout << "Move a point to left by one unit. "; output_point(move_left(point[0]));
	cout << "Move a point to right by one unit. "; output_point(move_right(point[0]));
	return 0;
}