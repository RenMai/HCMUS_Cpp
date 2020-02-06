#include "Header.h"

point ::point ()
{
	x=0;
	y=0;
}

point :: point (int xx, int yy)
{
	x=xx;
	y=yy;
};

float point :: dis (point p1,point p2)
{
	float dt;
	dt =  sqrt (1.0*(p1.x-p2.x)*(p1.x-p2.x)
		+ 1.0*(p1.y-p2.y)*(p1.y-p2.y));
	return dt;
}

triangle :: triangle()
{
	d1=0;
	d2=0;
	d3=0;
};

triangle :: triangle (float da, float db, float dc)
{
	d1=da;
	d2=db;
	d3=dc;
};

double triangle::para()
{
	return d1+d2+d3;
};

double triangle :: area()
{
	double p=(this->para())/2;
	return sqrt ( p*(p-this->d1)*(p-this->d2)*(p-this->d3));
};

rectangle :: rectangle ()
{
	w=0;
	r=0;
};

rectangle :: rectangle (float wi,float ra)
{
	w=wi;
	r=ra;
};

double rectangle::paraRec()
{
	return 2*((this->w)+(this->r));
};

double rectangle ::areaRec()
{
	return (this->w)*(this->r);
};

void shape ::input(shape &s)
{
	int n;
	cout << "Enter type:";
	cin >> n;
	if (n==1)
	{
		cout << "Enter slides: "<<endl;
		float d1,d2,d3;
		triangle tri(d1,d2,d3);
		s.t=tri;
		s.paraS=tri.para();
	}
	if (n==2)
	{
		cout << "Enter ranges and wides:" << endl;
		float w,r;
		rectangle rec(w,r);
		s.r=rec;
		s.paraS=rec.paraRec();
		s.areaS=rec.areaRec();
	}
	if (n==3)
	{
		cout << "Enter the radius:" << endl;
		float r;
		circle cir(r);
		s.c=cir;
		s.paraS=cir.paraCir();
		s.areaS=cir.areaCir();
	}
};	

circle :: circle ()
{
	r=0.0;
};


circle :: circle (float radius)
{
	r= radius;
};

double circle::paraCir()
{
	return 3.14 * (2 * (this->r));
};

double circle::areaCir()
{
	return 3.14 * (this->r)*(this->r);
}