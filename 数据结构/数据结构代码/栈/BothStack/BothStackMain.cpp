//BothStackMain.cpp
#include <iostream>     //�������������
using namespace std;
#include "BothStack.cpp"  //�����Ա�����ļ�

void main( )
{ 
    BothStack<int> a;             //����ģ�����ʵ��
    
	if (!a.Empty(1)){                //�ж�ջ�Ƿ�Ϊ��
	
	    cout<<"ջ1��,��ջ1����ѹջ����:"<<endl;
        try
		{
		    a.Push(1,10);
		}
        catch(char* wrong)
		{
			cout<<wrong;
		}
		cout<<"ջ1��ջ��Ԫ��Ϊ:\n";   //��ȡջ��Ԫ��
		cout<<a.GetTop(1)<<endl;

		cout<<"��ջ1����ѹջ����:\n";
		try
		{
			a.Push(1,12);
		}
		catch(char* wrong)
		{
			cout<<wrong;
		}
		cout<<"ջ1��ջ��Ԫ��Ϊ:\n";
		cout<<a.GetTop(1)<<endl;
		
		cout<<"��ջ1ִ�г�ջ����:"<<endl; //��ջ����
		a.Pop(1);                     

        cout<<"��ʱջ1�е�ջ��Ԫ��Ϊ:\n"; 
        cout<<a.GetTop(1)<<endl;
	}
    else{
	
		cout<<"ջ1����"<<endl;
	}
	if (!a.Empty(2)){
	
	    cout<<"ջ2��,��ջ2����ѹջ����:"<<endl;
    
		try
		{
			a.Push(2,5);
		}
		catch(char* wrong)
		{
			cout<<wrong;
		}
		
		cout<<"ջ2��ջ��Ԫ��Ϊ:\n";
		cout<<a.GetTop(2)<<endl;

		cout<<"��ջ2����ѹջ����:\n"; 
		try
		{
			a.Push(2,4);
		}
		catch(char* wrong)
		{
			cout<<wrong;
		}

		cout<<"ջ2��ջ��Ԫ��Ϊ:\n";
		cout<<a.GetTop(2)<<endl;

        cout<<"��ջ2���г�ջ����:\n";
        a.Pop(2);

        cout<<"��ʱջ2�е�ջ��Ԫ��Ϊ:\n"; 
        cout<<a.GetTop(2)<<endl;
		}
   
    else{
	
		cout<<"ջ2����"<<endl;
	}
} 