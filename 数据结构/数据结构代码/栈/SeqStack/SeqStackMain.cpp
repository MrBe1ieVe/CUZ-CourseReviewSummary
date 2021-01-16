//SeqStackMain.cpp
#include <iostream>      //引用输入输出流
using namespace std;
#include "SeqStack.cpp"  //引入成员函数文件

void main()
{    
    SeqStack<int> a;      //创建模板类的实例
    
    if (a.Empty( )){
	
		cout<<"栈空,执行入栈操作:"<<endl;

    	cout<<"对15和10执行入栈操作:"<<endl;
	    try
		{
			a.Push(15);
	        a.Push(10);   
		}
		catch(char* wrong)
		{
			cout<< wrong;
		}
		
		cout<<"栈顶元素为:"<<endl;   //取栈顶元素
		cout<<a.GetTop( )<<endl;
		    
	    cout<<"执行出栈操作:"<<endl;
	    cout<<a.Pop( )<<endl;          //执行出栈操作

        cout<<"栈顶元素为:"<<endl;
	    cout<<a.GetTop( )<<endl;	
	}
	else{
	
		cout<<"栈不空"<<endl;
	}

}

