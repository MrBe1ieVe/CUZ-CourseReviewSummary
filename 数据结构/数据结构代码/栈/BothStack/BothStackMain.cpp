//BothStackMain.cpp
#include <iostream>     //进入输入输出流
using namespace std;
#include "BothStack.cpp"  //引入成员函数文件

void main( )
{ 
    BothStack<int> a;             //创建模板类的实例
    
	if (!a.Empty(1)){                //判断栈是否为空
	
	    cout<<"栈1空,对栈1进行压栈操作:"<<endl;
        try
		{
		    a.Push(1,10);
		}
        catch(char* wrong)
		{
			cout<<wrong;
		}
		cout<<"栈1的栈顶元素为:\n";   //读取栈顶元素
		cout<<a.GetTop(1)<<endl;

		cout<<"对栈1进行压栈操作:\n";
		try
		{
			a.Push(1,12);
		}
		catch(char* wrong)
		{
			cout<<wrong;
		}
		cout<<"栈1的栈顶元素为:\n";
		cout<<a.GetTop(1)<<endl;
		
		cout<<"对栈1执行出栈操作:"<<endl; //出栈操作
		a.Pop(1);                     

        cout<<"此时栈1中的栈顶元素为:\n"; 
        cout<<a.GetTop(1)<<endl;
	}
    else{
	
		cout<<"栈1不空"<<endl;
	}
	if (!a.Empty(2)){
	
	    cout<<"栈2空,对栈2进行压栈操作:"<<endl;
    
		try
		{
			a.Push(2,5);
		}
		catch(char* wrong)
		{
			cout<<wrong;
		}
		
		cout<<"栈2的栈顶元素为:\n";
		cout<<a.GetTop(2)<<endl;

		cout<<"对栈2进行压栈操作:\n"; 
		try
		{
			a.Push(2,4);
		}
		catch(char* wrong)
		{
			cout<<wrong;
		}

		cout<<"栈2的栈顶元素为:\n";
		cout<<a.GetTop(2)<<endl;

        cout<<"对栈2进行出栈操作:\n";
        a.Pop(2);

        cout<<"此时栈2中的栈顶元素为:\n"; 
        cout<<a.GetTop(2)<<endl;
		}
   
    else{
	
		cout<<"栈2不空"<<endl;
	}
} 