#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;

struct Circle
{
	float x;
	float y;
	float radius;
};

void input_circle(Circle &x);
void input_circle_text(Circle x[]);
void output_circle(Circle x);
void output_circle_text(Circle x);
float area(Circle x);
float perimeter(Circle x);
#endif