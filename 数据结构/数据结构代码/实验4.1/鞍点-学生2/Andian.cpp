#include <iostream>      //�������������
#include <stdio.h>
#include <math.h>
#include <time.h>

using namespace std;
int Andian(int A[100][100],int row,int col);  
void GenMatrix(int A[100][100],int row,int col,int max);

void main()
{ int B[100][100];
  int m,n;
  int max=20;
  int counter=0;
  cout<<"---------������Գ���----------------"<<endl;
  cout<<"����������������";
  cin>>m;
  cout<<"����������������";
  cin>>n;
  srand((unsigned)(time(0))); //����ʱ���޸��������
  while(1)
  {
     counter++;
     GenMatrix(B,m,n,max);
     if (Andian(B,m,n)==0)
	    cout<<"�����ڰ���!"<<endl;
	 else
	 {   cout<<"ִ����"<<counter<< "�Σ�"<<endl;
		 break;
	 }

  }
}

void GenMatrix(int A[100][100],int row,int col,int max) //����һ��������max ������������󣬲����
{  int i,j;
   
   for (i=0;i<row;i++)
   {
	   for (j=0;j<col;j++)
	   {A[i][j]=rand()%max;
        printf("%4d",A[i][j]);   
          //cout<<A[i][j]<<" ";
	   }
       cout<<endl;
   }

}

int Andian(int A[100][100],int row,int col) //�����ڰ��� ����0
{   int flag=0;
    //ѧ�����    




	return flag;
}

