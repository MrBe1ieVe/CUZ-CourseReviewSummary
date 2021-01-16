//LinkListMain.cpp
#include <iostream.h>  //引用输入输出流库函数的头文件
#include "LinkList.cpp"  //引用单链表的类

void SetInterestSort(LinkList <char> &a, LinkList <char> &b,LinkList <char> &r);
void SetInterest(LinkList <char> &a, LinkList <char> &b,LinkList <char> &r);
void SetAdd(LinkList <char> &a, LinkList <char> &b,LinkList <char> &r);
void SetSub(LinkList <char> &a, LinkList <char> &b,LinkList <char> &r);
int SubSetIs(LinkList <char> &a, LinkList <char> &b); // a 是 b的子集？

void Reverse(LinkList <char> &a, LinkList <char> &r); // 将链表a逆向复制到r, 再对链表r 逆转


void main( )
{

  int n;

  char A[100];

//-----------------------------------------------
cout<<"字符型-集合a的参数有:(1) n,   (2) a1~an"<<endl;
cout<<"请输入： n=";
cin>>n;
cout<<endl;

cout<<"请升序输入数组元素a0~an："<<endl;
for (int i=0; i<n; i++)
	{
	 cout<<"   a["<<i<<"]=";
     cin>>A[i];
     //cout<<endl;
	}

LinkList <char> a(A,n);
 cout<<"集合a 的元素为:"<<endl;
 a.PrintList();            //输出单链表所有元素
//-----------------------------------------------
cout<<"字符型-集合b的参数有:(1) n,   (2) b1~bn"<<endl;
cout<<"请输入： n=";
cin>>n;
cout<<endl;

cout<<"请升序输入数组元素b0~bn："<<endl;
for ( i=0; i<n; i++)
	{
	 cout<<"   b["<<i<<"]=";
     cin>>A[i];
     //cout<<endl;
	}

LinkList <char> b(A,n);
 cout<<"集合b 的元素为:"<<endl;
 b.PrintList();            //输出单链表所有元素
//-----------------------------------------------------------

LinkList <char> c;

//--------------------------------------------------------
 cout<<"集合a,b 的交集为:"<<endl;
SetInterest(a , b , c);
c.PrintList();


	/*cout<<"集合a+b 为:"<<endl;
	c.Empty();
	SetAdd(a , b , c);
	c.PrintList();



	cout<<"集合a-b 为:"<<endl;
	c.Empty();
	SetSub(a , b , c);
	c.PrintList();




	cout<<"集合a是b 的子集吗？"<<endl;
	if (SubSetIs(a,b)<1)
	   cout<<"No"<<endl;
	else
	   cout<<"Yes"<<endl;



	cout<<"链表逆转测试："<<endl;
	c.Empty();
	Reverse( a,  c);
	cout<<"链表逆转后："<<endl;
	c.PrintList();

	  */

}

//-------------------------------

//---------------------------------------

void SetInterestSort(LinkList <char> &a, LinkList <char> &b,LinkList <char> &r)
{    // 要求集合a,b是升序排列的
     Node<char>*p,*q;
	 p=(a.first)->next; q=(b.first)->next; 
     while (p && q)
     {
        if (p->data<q->data)   p=p->next;
        else if (p->data>q->data) q=q->next;
        else { 

				 r.Insert(1,p->data);
                 p=p->next;
                 q=q->next;
             }
     }
  }

void SetInterest(LinkList <char> &a, LinkList <char> &b,LinkList <char> &r)
{    // 集合a,b可以是无序的
     Node<char> *p;
	 p=(a.first)->next; 
     
     while (p)
	 {
         
		 if (b.Locate(p->data)!=0)
            r.Insert(1,p->data);
		 p=p->next;

	 } 
  }


void SetAdd(LinkList <char> &a, LinkList <char> &b,LinkList <char> &r)
  {  
    
	 
  }

void SetSub(LinkList <char> &a, LinkList <char> &b,LinkList <char> &r)
  {  
     
	 
  }


int SubSetIs(LinkList <char> &a, LinkList <char> &b) // a 是 b的子集？ 1:yes, 0:no
{
   
	
  return 1;
}


void Reverse(LinkList <char> &a, LinkList <char> &r) // 将链表a逆向复制到r, 再对链表r 逆转
{
     Node<char> *p;
	 //----------------------------------------------
	 p=(a.first)->next; 	
     while (p)
     {
        r.Insert(1,p->data);
		p=p->next;
	 }

     r.PrintList();
     //---------------以下代码用于逆转 r ------------------------------
     
      //学生在此继续填写代码

	 
     
}