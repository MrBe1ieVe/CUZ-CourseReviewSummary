#include <iostream.h>


void Reverse(int A[ ], int from, int to);
void Converse(int A[ ], int n, int i);

void main( )
{ int n;
  int j,A[100];


cout<<"����A��ѭ����λ������:(1) n, (2) j,  (3) a1~an"<<endl;
cout<<"�����룺 n=";
cin>>n;
cout<<endl;
cout<<"�����룺 j=";
cin>>j;
cout<<endl;

cout<<"����������Ԫ��a0~an��"<<endl;
for (int i=0; i<n; i++)
	{
	 cout<<"   a["<<i<<"]=";
     cin>>A[i];
     //cout<<endl;
	}
 

cout<<"ѭ����λ"<<j<<"��Ľ��Ϊ��"<<endl;
Converse( A, n,j);
for ( i=0; i<n; i++)
	{
	 cout<<A[i]<<"   ";
     
	}
 

}

void Converse(int A[ ], int n, int i)
 {
   Reverse(A, 0, i-1);   //ǰi��Ԫ������
   Reverse(A, i, n-1);   //��n-i��Ԫ������
   Reverse(A, 0, n-1);   //������������
 }
void Reverse(int A[ ], int from, int to)
                           //������A��Ԫ�ش�from��to����
{  int temp;
   for (int i=0; i<(to-from+1)/2; i++)
   {
        temp=A[from+i];   // ����Ԫ��
		A[from+i]=A[to-i];
		A[to-i]=temp;
   }       
                 
}
