
#include"../../List/list.h"
#include"../../List/queue.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void ct(int lst[],int n)
{
	for(int i=0;i<n;i++){
		//TODO
		cout<<lst[i]<<" ";
		
		
	}
	cout<<endl;
	
}

int main()


{
	cout<<"生成的十个高度数据"<<endl;
	int n=10,i;
	int lst[n];
	for(i=0;i<n;i++)
	{
		lst[i]=0;
	}
	srand(time(0));
	
	n=10;
	for(int i=0;i<n;i++){
		//TODO
		lst[i]=(rand() % 105)+1;
		
	}
	ct(lst ,n);
	int left=0,right=0,max=0,flag1=1,flag2=1,Mmax=0;
	for(int i=0;i<n;i++){
		//TODO
		flag1=1;
		flag2=1;
		left=i;
		right=i;
		while(flag1==1){
			//TODO
		
		if(left>0 && lst[left]>=lst[i]){
			//TODO
			--left;
		}
			else{flag1--;}
		}
		while(flag2==1){
			//TODO
		
		if(right<n-1 && lst[right]>=lst[i])
		{
			++right;
		}
			else{flag2--;}
		}
		max=lst[i]*(right-left);
		if(Mmax<max)
		{
			Mmax=max;
		}
	}
	cout<<"最大面积为"<<endl;
	cout<<Mmax<<endl;
	return 0;
	
	
	
}
