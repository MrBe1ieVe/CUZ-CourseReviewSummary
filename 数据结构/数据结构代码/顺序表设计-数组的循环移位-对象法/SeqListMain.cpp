//SeQListMain.cpp
#include <iostream.h>       //引用输入输出流库函数的头文件
#include "SeqList.cpp"      //引用顺序表类SeqList

void main( )
{
  int n;
  int j;
  char A[100];


cout<<"字符型-数组A的循环移位参数有:(1) n, (2) j,  (3) a1~an"<<endl;
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
 


SeqList <char> b(A,n);     //根据数组创建顺序表
cout<<"循环移位"<<j<<"后的结果为："<<endl;
b.Converse(j);
b.PrintList();            //输出顺序表所有元素
 
}