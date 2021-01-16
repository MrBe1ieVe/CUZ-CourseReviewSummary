//LinkList.cpp
#include "LinkList.h"
/*
*前置条件：单链表不存在
*输    入：无
*功    能：构建一个单链表
*输    出：无
*后置条件：构建一个单链表
*/
template <class T>
LinkList<T>:: LinkList( )
{
 first=new Node<T>; first->next=NULL;
}
/*
*前置条件：单链表不存在
*输    入：顺序表信息的数组形式a[],单链表长度n
*功    能：将数组a[]中元素建为长度为n的单链表
*输    出：无
*后置条件：构建一个单链表
*/
template <class T>  
LinkList<T>:: LinkList(T a[ ], int n)
 {
    first=new Node<T>;   //生成头结点
	Node<T> *r,*s;
     r=first;          //尾指针初始化
    for (int i=0; i<n; i++)
	{ 
      s=new Node<T>; s->data=a[i];  //为每个数组元素建立一个结点
      r->next=s; r=s;      //插入到终端结点之后
	}
    r->next=NULL;    //单链表建立完毕，将终端结点的指针域置空
 }
/*
*前置条件：无
*输    入：无
*功    能：无
*输    出：无
*后置条件：无
*/
template <class T>
LinkList<T>:: ~LinkList()
{
    Node<T> *p;
	while (first!=NULL)
	{  
      p=first;
	  first=first->next;
	  delete p;
	}

}

template <class T>
void LinkList<T>::Empty()
{
    Node<T> *p;
	while (first!=NULL)
	{  
      p=first;
	  first=first->next;
	  delete p;
	}
   first=new Node<T>; first->next=NULL;
}





/*
*前置条件：单链表存在
*输    入：查询元素位置i
*功    能：按位查找位置为i的元素并输出值
*输    出：查询元素的值
*后置条件：单链表不变
*/
template <class T>
T LinkList<T>::Get(int i) 
{   
  Node<T> *p; int j;
  p=first->next;  j=1;  //或p=first;  j=0;
  while (p && j<i)    
  {
    p=p->next;       //工作指针p后移
    j++;
  }
  if (!p) throw "位置";
  else return p->data;
}

/*
*前置条件：单链表存在
*输    入：查询元素值x
*功    能：按值查找值的元素并输出位置
*输    出：查询元素的位置
*后置条件：单链表不变
*/
template <class T> 
int LinkList<T>::Locate(T x)  //fjj modify
{
	Node<T> *p; int j;
	p=first->next; j=1;
	
	  while(p)
	  {
		  if (p->data==x)
			 break;
		  p=p->next;
	     j++;
	  }
	  if (p)
		  return j;
	  else 
		  return 0;
	
}

/*
*前置条件：单链表存在
*输    入：插入元素x,插入位置i
*功    能：将元素x插入到单链表中位置i处
*输    出：无
*后置条件：单链表插入新元素
*/
template <class T>  
void LinkList<T>::Insert(int i, T x)
{  
   Node<T> *p; int j;
   p=first ; j=0;    //工作指针p初始化
   while (p && j<i-1)
   {
     p=p->next;   //工作指针p后移
     j++;
   }
   if (!p) throw "位置";
    else { 
	  Node<T> *s;
      s=new Node<T>; 
	  s->data=x;  //向内存申请一个结点s，其数据域为x
      s->next=p->next;       //将结点s插入到结点p之后
      p->next=s;
	}
}

/*
*前置条件：单链表存在
*输    入：无
*功    能：输出单链表长度
*输    出：单链表长度
*后置条件：单链表不变
*/
template <class T> 
int LinkList<T>::Length( )
{
  Node <T> *p = first->next;
  int i = 0;
  while(p)
  {
    p = p->next;
    i++;
  }
  return i;
}
/*
*前置条件：单链表存在
*输    入：要删除元素位置i
*功    能：删除单链表中位置为i的元素
*输    出：无
*后置条件：单链表删除元素
*/
template <class T>  
T LinkList<T>::Delete(int i)
{ 
  Node<T> *p; int j;
  p=first ; j=0;  //工作指针p初始化
  while (p && j<i-1)  //查找第i-1个结点
  {
    p=p->next;
    j++;
  }
  if (!p || !p->next) throw "位置";  //结点p不存在或结点p的后继结点不存在
    else {
		  Node<T> *q; int x;
          q=p->next; x=q->data;  //暂存被删结点
          p->next=q->next;  //摘链
          delete q; 
          return x;
	}
}
/*
*前置条件：单链表存在
*输    入：无
*功    能：单链表遍历
*输    出：输出所有元素
*后置条件：单链表不变
*/
template <class T> 
void LinkList<T>::PrintList( )
{
	Node<T> *p;
	p=first->next;
	while (p)
	{
	  cout<<p->data<<" ";
	  p=p->next;
	}
	cout<<endl;
	
}

