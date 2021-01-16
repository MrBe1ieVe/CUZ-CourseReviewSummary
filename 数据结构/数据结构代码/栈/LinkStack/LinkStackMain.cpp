//LinkStackMain.cpp
#include <iostream>       //�������������
using namespace std;
#include "LinkStack.cpp"  //�����Ա�����ļ�

void main( )
{ 
    LinkStack<int>a;             //����ģ�����ʵ��
	if (a.Empty( )){                  //�ж�ջ�Ƿ�Ϊ��
	
		cout<<"ջ�գ�ִ�в���"<<endl; 
		cout<<"��10����ѹջ����:"<<endl;    //��ջ����
        try
		{
			a.Push(10);
        }
		catch(char* wrong)
		{
			cout<<wrong;
		}
	    
		cout<<"��ȡջ��Ԫ��:"<<endl;        //��ջ��Ԫ��
        cout<<a.GetTop( )<<endl;
    
	    cout<<"��15ջ����ѹջ����:"<<endl;
        try
		{
			a.Push(15);
        }
		catch(char* wrong)
		{
			cout<<wrong;
        }
	    
		cout<<"��ȡջ��Ԫ��:\n"; 
        cout<<a.GetTop( )<<endl;
 
	    cout<<"���г�ջ����:"<<endl;    //��ջ����   
	    a.Pop( );

	    cout<<"��ȡջ��Ԫ��:"<<endl;
        cout<<a.GetTop( )<<endl;
	}
    else{
	
        cout<<"ջ����"<<endl; 
	}
	a.~LinkStack( );
}