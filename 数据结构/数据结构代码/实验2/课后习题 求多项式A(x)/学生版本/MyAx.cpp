#include <iostream.h>
#include <stdlib.h>

float Ax1(float A[],int n, float x);
float Ax2(float A[],int n, float x);
float Ax3(float A[],int n, float x);

void main( )
{  int n1;
  float x1,B[100];


cout<<"多项式A(x)中的参数有:(1) n, (2) x,  (3) a1~an"<<endl;
cout<<"请输入： n=";
cin>>n1;
cout<<endl;
cout<<"请输入： x=";
cin>>x1;
cout<<endl;

cout<<"请输入系数an~a0："<<endl;
for (int i=n1; i>=0; i--)
	{
	 cout<<"   a["<<i<<"]=";
     cin>>B[i];
     cout<<endl;
	}

 cout<<"  A1(x)="<<Ax1(B,n1,x1)<<endl; 
  cout<<"  A2(x)="<<Ax2(B,n1,x1)<<endl; 
  cout<<"  A3(x)="<<Ax3(B,n1,x1)<<endl; 

  system("pause");


}

float Ax2(float A[],int n, float x)
{
	float t=1,sum=A[0];
	for(int i=1;i<=n;i++)
	{ 
		t=t*x;
	   sum+=A[i]*t;
	}
	return sum;
}
float Ax1(float A[],int n, float x)
{   

	float t,sum=A[0];
	int j;
	
	for(j=n;j>=1;j--)
	{t=1;
	for(int i=1;i<=j;i++)
	  
	t=t*x;
	  sum+=A[j]*t;
	}

	
return sum;

}
float Ax3(float A[],int n, float x)
{   

float sum=A[n];


for(int i=n;i>=1;i--)
sum=sum*x+A[i-1];


return sum;
}

