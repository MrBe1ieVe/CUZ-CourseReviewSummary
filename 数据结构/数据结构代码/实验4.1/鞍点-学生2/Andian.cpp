#include <iostream>      //引用输入输出流
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
  cout<<"---------鞍点测试程序----------------"<<endl;
  cout<<"请输入矩阵的行数：";
  cin>>m;
  cout<<"请输入矩阵的列数：";
  cin>>n;
  srand((unsigned)(time(0))); //根据时间修改随机种子
  while(1)
  {
     counter++;
     GenMatrix(B,m,n,max);
     if (Andian(B,m,n)==0)
	    cout<<"不存在鞍点!"<<endl;
	 else
	 {   cout<<"执行了"<<counter<< "次！"<<endl;
		 break;
	 }

  }
}

void GenMatrix(int A[100][100],int row,int col,int max) //产生一个不大于max 的随机整数矩阵，并输出
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

int Andian(int A[100][100],int row,int col) //不存在鞍点 返回0
{   int flag=0;
    //学生完成    




	return flag;
}

