#include<iostream>
#include<cmath>
using namespace std;

class Complex 
{

private:
	double a;
	double b;
	double mod;
	
public:
	
	void init ( double i, double j) // ‰»Î 
	{
		a = i;
		b = j;
	}
	void abscomplex()
	{
		double r;
		r = a*a+b*b;
		mod = sqrt(r);
	}
	void s()
	{
		cout <<a<<b;
	}
}; 

