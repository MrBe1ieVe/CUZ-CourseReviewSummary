//SeqStackMain.cpp
#include <iostream>      //�������������
using namespace std;
#include "SeqStack.cpp"  //�����Ա�����ļ�

void main()
{    
    char myexp[100];
	cout<<"������һ�����ʽ��������'(',')' :";
	gets(myexp);
	cout<<"'"<<myexp<<"'"<< endl;
	
	SeqStack<char> S;      //����ģ�����ʵ��
    
    int i,flag;
	i=0;
	flag=1;
 
	while(myexp[i]!='\0')
	{
       if (myexp[i]=='(')
	   { S.Push(myexp[i]);}

	   if  (myexp[i]==')')
	   {
           if ( S.Empty() || S.GetTop()!='(')
		   {flag=0; break;}
		   S.Pop();
	   }

       i++;
	}

  	if (flag==1&& S.Empty())
		cout<<"����ƥ��ɹ���"<<endl;
	else
		cout<<"�����ڵ�"<<i+1<<"�����Ŵ�ƥ��ʧ�ܡ�"<<endl;




}

