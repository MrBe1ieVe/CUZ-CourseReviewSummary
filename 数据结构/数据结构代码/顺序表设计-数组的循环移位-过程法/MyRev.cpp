#include <iostream.h>


void Reverse(int A[ ], int from, int to);
void Converse(int A[ ], int n, int i);

void main( )
{ int n;
  int j,A[100];


cout<<"数组A的循环移位参数有:(1) n, (2) j,  (3) a1~an"<<endl;
cout<<"请输入： n=";
cin>>n;
cout<<endl;
cout<<"请输入： j=";
cin>>j;
cout<<endl;

cout<<"请输入数组元素a0~an："<<endl;
for (int i=0; i<n; i++)
	{
	 cout<<"   a["<<i<<"]=";
     cin>>A[i];
     //cout<<endl;
	}
 

cout<<"循环移位"<<j<<"后的结果为："<<endl;
Converse( A, n,j);
for ( i=0; i<n; i++)
	{
	 cout<<A[i]<<"   ";
     
	}
 

}

void Converse(int A[ ], int n, int i)
 {
   Reverse(A, 0, i-1);   //前i个元素逆置
   Reverse(A, i, n-1);   //后n-i个元素逆置
   Reverse(A, 0, n-1);   //整个数组逆置
 }
void Reverse(int A[ ], int from, int to)
                           //将数组A中元素从from到to逆置
{  int temp;
   for (int i=0; i<(to-from+1)/2; i++)
   {
        temp=A[from+i];   // 交换元素
		A[from+i]=A[to-i];
		A[to-i]=temp;
   }       
                 
}
