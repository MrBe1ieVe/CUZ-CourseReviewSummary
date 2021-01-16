#include <iostream>      //引用输入输出流
#include <string>
using namespace std;



void main()
{
    char myexp[100];
	cout<<"请输入一个表达式包含括号'(',')' :";
	gets(myexp);
	cout<<myexp<< endl;
	char S[100];
	int top,i,flag;
	top=-1;
	i=0;
	flag=1;
 
	while(myexp[i]!='\0')
	{
       if (myexp[i]=='(')
	   { top++; S[top]=myexp[i];}

	   if  (myexp[i]==')')
	   {
           if ( top==-1 || S[top]!='(')
		   {flag=0; break;}
		   top--;
	   }

       i++;
	}

  	if (flag==1&& top==-1)
		cout<<"括号匹配成功！"<<endl;
	else
		cout<<"括号在第"<<i+1<<"个符号处匹配失败。"<<endl;


}

