//SeqStackMain.cpp
#include <iostream>      //引用输入输出流
using namespace std;
#include "SeqStack.cpp"  //引入成员函数文件

void main()
{    
    char myexp[100];
	cout<<"请输入一个表达式包含括号'(',')' :";
	gets(myexp);
	cout<<"'"<<myexp<<"'"<< endl;
	
	SeqStack<char> S;      //创建模板类的实例
    
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
		cout<<"括号匹配成功！"<<endl;
	else
		cout<<"括号在第"<<i+1<<"个符号处匹配失败。"<<endl;




}

