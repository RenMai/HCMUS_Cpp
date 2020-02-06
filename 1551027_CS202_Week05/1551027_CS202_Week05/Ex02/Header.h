#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class point 
{
private : int x,y;
public:
	point();
	point(int xx, int yy);
	float dis(point p1, point p2);
};

class triangle 
{
private : float d1,d2,d3;
public : 
	triangle ();
	triangle (float da,float db,
		float dc);
	double para();
	double area();
};

class circle
{
private : float r;
public: 
	circle ();
	circle (float radius);
	double paraCir();
	double areaCir();

};

class rectangle 
{ 
private : float w,r;
public :
	rectangle ();
	rectangle (float wi,float ra);
	double paraRec();
	double areaRec();
};

class shape 
{
private : point p;
public :
	triangle t;
	circle c;
	rectangle r;
	void input (shape &s);
	double paraS;
	double areaS;
};