//SeqStackMain.cpp
#include <iostream>      //�������������
using namespace std;
#include "SeqStack.cpp"  //�����Ա�����ļ�

void main()
{    
    SeqStack<int> a;      //����ģ�����ʵ��
    
    if (a.Empty( )){
	
		cout<<"ջ��,ִ����ջ����:"<<endl;

    	cout<<"��15��10ִ����ջ����:"<<endl;
	    try
		{
			a.Push(15);
	        a.Push(10);   
		}
		catch(char* wrong)
		{
			cout<< wrong;
		}
		
		cout<<"ջ��Ԫ��Ϊ:"<<endl;   //ȡջ��Ԫ��
		cout<<a.GetTop( )<<endl;
		    
	    cout<<"ִ�г�ջ����:"<<endl;
	    cout<<a.Pop( )<<endl;          //ִ�г�ջ����

        cout<<"ջ��Ԫ��Ϊ:"<<endl;
	    cout<<a.GetTop( )<<endl;	
	}
	else{
	
		cout<<"ջ����"<<endl;
	}

}

