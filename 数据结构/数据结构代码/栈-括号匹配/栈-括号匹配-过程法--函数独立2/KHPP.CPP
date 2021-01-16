#include <iostream>      //引用输入输出流
#include <string>
using namespace std;

int mykhpp(char myexp[],int *pos);

void main()
{
    char myexp1[100];
	cout<<"请输入一个表达式包含括号'(',')' :";
	gets(myexp1);
	cout<<myexp1<< endl;
	
	int ppos=0;
   if (mykhpp(myexp1,&ppos)==1)
       cout<<"括号匹配成功！"<<endl;
    else
       cout<<"括号在第"<<ppos+1<<"个符号处匹配失败。"<<endl;

}


int mykhpp(char myexp[],int *pos) // 返回值：1 成功；0 失败 ，pos 失败位置

{
	int top,i,flag;
	top=-1;
	i=0;
	flag=1;
	char S[100];
 
	while(myexp[i]!='\0')
	{
       if (myexp[i]=='('|| myexp[i]=='[')
	   { top++; S[top]=myexp[i];}

	   if  (myexp[i]==')' || myexp[i]==']')
	   {
           if ( top==-1 )
			    {flag=0; break;}
		   if  (myexp[i]==')' && S[top]!='(')
		       {flag=0; break;}
		   if  (myexp[i]==']' && S[top]!='[')
		       {flag=0; break;}

		   top--;
	   }

       i++;
	}
    *pos=i;
  	if (flag==1&& top==-1)
		return 1;
	else
	    return 0;

}




