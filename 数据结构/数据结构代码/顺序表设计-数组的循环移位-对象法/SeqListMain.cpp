//SeQListMain.cpp
#include <iostream.h>       //��������������⺯����ͷ�ļ�
#include "SeqList.cpp"      //����˳�����SeqList

void main( )
{
  int n;
  int j;
  char A[100];


cout<<"�ַ���-����A��ѭ����λ������:(1) n, (2) j,  (3) a1~an"<<endl;
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
 


SeqList <char> b(A,n);     //�������鴴��˳���
cout<<"ѭ����λ"<<j<<"��Ľ��Ϊ��"<<endl;
b.Converse(j);
b.PrintList();            //���˳�������Ԫ��
 
}