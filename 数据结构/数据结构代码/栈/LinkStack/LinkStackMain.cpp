//LinkStackMain.cpp
#include <iostream>       //引用输入输出流
using namespace std;
#include "LinkStack.cpp"  //引入成员函数文件

void main( )
{ 
    LinkStack<int>a;             //创建模板类的实例
	if (a.Empty( )){                  //判断栈是否为空
	
		cout<<"栈空，执行操作"<<endl; 
		cout<<"对10进行压栈操作:"<<endl;    //入栈操作
        try
		{
			a.Push(10);
        }
		catch(char* wrong)
		{
			cout<<wrong;
		}
	    
		cout<<"读取栈顶元素:"<<endl;        //读栈顶元素
        cout<<a.GetTop( )<<endl;
    
	    cout<<"对15栈进行压栈操作:"<<endl;
        try
		{
			a.Push(15);
        }
		catch(char* wrong)
		{
			cout<<wrong;
        }
	    
		cout<<"读取栈顶元素:\n"; 
        cout<<a.GetTop( )<<endl;
 
	    cout<<"进行出栈操作:"<<endl;    //出栈操作   
	    a.Pop( );

	    cout<<"读取栈顶元素:"<<endl;
        cout<<a.GetTop( )<<endl;
	}
    else{
	
        cout<<"栈不空"<<endl; 
	}
	a.~LinkStack( );
}