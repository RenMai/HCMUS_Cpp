#ifndef _FRACTION_H_
#define _FRACTION_H_

#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;

struct Point{
	float x;
	float y;
};

void input_point(Point &x);
void input_point_text(Point x[]);
void output_point(Point x);
void output_point_text(Point x);
void update_x(Point &x);
void update_y(Point &x);
void get_x(Point x);
void get_y(Point x);
float distance_point(Point a, Point b);
bool first(Point x);
bool third(Point x);
Point move_up(Point x);
Point move_down(Point x);
Point move_left(Point x);
Point move_right(Point x);

#endif