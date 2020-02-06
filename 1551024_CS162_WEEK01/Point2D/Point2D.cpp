#include "Point2D.h"
void input_point(Point &x)
{
	cout << "Enter x: ";
	cin >> x.x;
	cout << "Enter y:";
	cin >> x.y;
}
void input_point_text(Point x[])
{
	ifstream fin;
	fin.open("input.txt");
	for (int i = 0; i <= 1; ++i)
	{
		fin >> x[i].x;
		fin >> x[i].y;
	}
	fin.close();
}
void output_point(Point x)
{
	cout << "(" << x.x << "," << x.y << ")" << endl;
}
void output_point_text(Point x)
{
	ofstream fout;
	fout.open("output.txt");
	fout << "Your point is: (" << x.x << "," << x.y << ")";
	fout.close();
}
void update_x(Point &x)
{
	float n;
	cout << "Enter the value of x you want to update: ";
	cin >> n;
	x.x = n;
}
void update_y(Point &x)
{
	float n;
	cout << "Enter the value of y you want to update: ";
	cin >> n;
	x.y = n;
}
void get_x(Point x)
{
	float n;
	n = x.x;
	cout << "The element x of point is: " << n << endl;
}
void get_y(Point x)
{
	float n;
	n = x.y;
	cout << "The element y of point is: " << n << endl;
}
float distance_point(Point a, Point b)
{
	float result;
	result = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
	return result;
}
bool first(Point x)
{
	if (x.x > 0 && x.y > 0) return true;
	return false;
}
bool third(Point x)
{
	if (x.x < 0 && x.y < 0) return true;
	return false;
}
Point move_up(Point x)
{
	Point result;
	result.x = x.x;
	result.y = x.y + 1;
	return result;
}
Point move_down(Point x)
{
	Point result;
	result.x = x.x;
	result.y = x.y - 1;
	return result;
}
Point move_left(Point x)
{
	Point result;
	result.x = x.x - 1;
	result.y = x.y;
	return result;
}
Point move_right(Point x)
{
	Point result;
	result.x = x.x + 1;
	result.y = x.y;
	return result;
}