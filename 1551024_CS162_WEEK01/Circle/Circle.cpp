#include "Circle.h"

void input_circle(Circle &x)
{
	cout << "Enter x: ";
	cin >> x.x;
	cout << "Enter y:";
	cin >> x.y;
	cout << "Enter the radius:";
	cin >> x.radius;
}
void input_circle_text(Circle x[])
{
	ifstream fin;
	fin.open("input.txt");
	int i = 0;
	fin >> x[i].x;
	fin >> x[i].y;
	fin >> x[i].radius;
	fin.close();
}
void output_circle(Circle x)
{
	cout << "Your circle is: The center I(" << x.x << "," << x.y << ") and the radius R = " << x.radius << endl;
}
void output_circle_text(Circle x)
{
	ofstream fout;
	fout.open("output.txt");
	fout << "Your circle is: The center I(" << x.x << "," << x.y << ") and the radius R= " << x.radius;
	fout.close();
}
float area(Circle x)
{
	float n;
	n = x.radius * x.radius * 3.14;
	return n;
}
float perimeter(Circle x)
{
	float n;
	n = 2 * x.radius * 3.14;
	return n;
}