#include <iostream>      //引用输入输出流
#include <string>
using namespace std;
int khpp1(char myexp[], int *pos);


void main()
{
    char myexp1[100];
	cout<<"请输入一个表达式包含括号'(',')' :";
	gets(myexp1);
	cout<<myexp1<< endl;
	int mypos;
   if (khpp1(myexp1,&mypos)==1)
        cout<<"ok!";
   else
        cout<<"括号在位置"<<mypos<<"处匹配失败！"<<endl;

	   


}

int khpp1(char myexp[] ,int *pos) //pos 出错位置
{
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
    *pos=i;
    if (flag==1&& top==-1) return 1;
	else return 0;

}

