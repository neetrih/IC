
#include"../../vector/vector.h"
#include"../../vector/Complex.h"
#include <chrono>
#include<cmath>
#include<ctime>
#include<vector>
int i;
Complex t[110];
int n=10;




int main()
{
	cout<<"loading...--生成向量" <<endl;
	int n=10;
	int j;
	
	for(i=1;i<=10;i++)
	{
		t[i].get_Real(rand() % 20 + 10);
		t[i].get_Imaginary(rand() % 20 + 10);
		t[i].get_modulus();
		t[i].display();}    //show it
//查找
	cout<<endl<<"输入你要找的向量的模"<<endl;
	cin>>j;
	
	
	int k=0;
	int index;
	
	void cz( int j);
{

	for(i=0;i<n;i++)
	{
		t[i].get_modulus();
		if(t[i].m_modulus==j)
		{
			t[i].display();
			k+=1;
		}
	}
	if(k==0)
		
		
	{cout<<"没有找到"<<endl;}
	
}
	//插入
	cout<<"请输入插入的复数的实部";
	
	cin>>t[100].m_real;
	cout<<"请输入虚部";
	cin>>t[100].m_imag;
	cout<<"输入插入的位置(1---10)";
	cin>>index;
	n+=1;
	
	

	for(i=n;i>index;i--)
	{
	 t[i].m_imag=t[i-1].m_imag;
		t[i].m_real=t[i-1].m_real;
	}
	t[index].m_imag=t[100].m_imag;
	t[index].m_real=t[100].m_real;
	for(int i=1;i<=n;i++){
		
		t[i].display();
	}
	//删除
	cout<<"你要删除哪项？（1--11）";
	cin>>index;
	for(i=index;i<n;i++)
	{
		t[i].m_imag=t[i+1].m_imag;
		t[i].m_real=t[i+1].m_real;
		
		
	}
		
	n-=1;
	for(int i=1;i<=n;i++){
		
		t[i].display();
	}
	cout<<endl;
	// 唯一化

	
	
	//下面是冒泡排序和归并排序的时间比较
	time_t t1;
	time_t t2;
	int p;
	double s;
	
	
	Complex u[30000];
	Complex w[30000];
	for(i=1;i<=30000;i++)
	{
		u[i].get_Real(rand() % 20 + 10);
		u[i].get_Imaginary(rand() % 20 + 10);
		u[i].get_modulus();
		;}    //show it
	
	for(i=1;i<=30000;i++)
	{
		u[i].get_modulus();
		
	}time(&t1);
	for(i=1;i<=30000;i++)
	{
		if(u[i].m_modulus<u[i+1].m_modulus)
		{
		
			p=u[i].m_imag;
			u[i].m_imag=u[i+1].m_imag;
			u[i+1].m_imag=p;
			p=u[i].m_real;
			u[i].m_real=u[i+1].m_real;
			u[i+1].m_real=p;
			
		}
	}
	time(&t2);
	s=difftime(t2,t1);
	std::cout<<"冒泡排序的时间为"<<s<<endl;
	for(i=1;i<=30000;i++)
	{
		u[i].get_Real(rand() % 20 + 10);
		u[i].get_Imaginary(rand() % 20 + 10);
		u[i].get_modulus();
		;}    //show it
	time(&t1);
	for(i=1;i<15000;i++)
	{
		if(u[i].m_modulus<u[i+1].m_modulus)
		{
			
			p=u[i].m_imag;
			u[i].m_imag=u[i+1].m_imag;
			u[i+1].m_imag=p;
			p=u[i].m_real;
			u[i].m_real=u[i+1].m_real;
			u[i+1].m_real=p;
			
		}
	}
	for(i=15000;i<30000;i++)
	{
		if(u[i].m_modulus<u[i+1].m_modulus)
		{
			
			p=u[i].m_imag;
			u[i].m_imag=u[i+1].m_imag;
			u[i+1].m_imag=p;
			p=u[i].m_real;
			u[i].m_real=u[i+1].m_real;
			u[i+1].m_real=p;
			
		}
	}
	int index1=1,index2=1,index3=1;
	for(i=1;i<30000;i++)
	{
	if(u[index1]>u[index2+14999])
	{
		w[index3].m_imag=u[index1].m_imag;
		w[index3].m_real=u[index1].m_imag;
		
	}
		else
		{
			w[index3].m_imag=u[index2+14999].m_imag;
			w[index3].m_real=u[index2+14999].m_imag;
		}
	
	}
	time(&t2);
	s=difftime(t2,t1);
	cout<<"归并排序的时间为"<<s<<endl;
	//向量的查找
	int sat;
	int end;
	cout<<"请输入要查找的模的范围区间（前闭区间）";
	cin>>sat;
	cout<<"后闭区间";
	cin>>end;
	for(i=1;i<=10;i++)
	{
		t[i].get_modulus();
	}
	cout<<"有以下向量满足要求";
	
	for(i=1;i<=10;i++)
	{
		if(t[i].m_modulus>=sat && t[i].m_modulus<=end){
			//TODO
		t[i].display();
			
		}
	}
	
	
	
	
	

	
}

