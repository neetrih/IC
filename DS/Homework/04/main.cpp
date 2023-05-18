#include<iostream>
#include<ctime> 
#include"Vector.h"
#include"complex.cpp"
using namespace std;


int main()
{
	Complex a[10];
	for(int i=0;i<10;i++){
		a[i].init(rand()%i+1,rand()%i+2);
	} 

	return 0;
}
