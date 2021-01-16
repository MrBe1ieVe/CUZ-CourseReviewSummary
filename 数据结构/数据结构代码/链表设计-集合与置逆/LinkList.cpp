//LinkList.cpp
#include "LinkList.h"
/*
*ǰ������������������
*��    �룺��
*��    �ܣ�����һ��������
*��    ������
*��������������һ��������
*/
template <class T>
LinkList<T>:: LinkList( )
{
 first=new Node<T>; first->next=NULL;
}
/*
*ǰ������������������
*��    �룺˳�����Ϣ��������ʽa[],��������n
*��    �ܣ�������a[]��Ԫ�ؽ�Ϊ����Ϊn�ĵ�����
*��    ������
*��������������һ��������
*/
template <class T>  
LinkList<T>:: LinkList(T a[ ], int n)
 {
    first=new Node<T>;   //����ͷ���
	Node<T> *r,*s;
     r=first;          //βָ���ʼ��
    for (int i=0; i<n; i++)
	{ 
      s=new Node<T>; s->data=a[i];  //Ϊÿ������Ԫ�ؽ���һ�����
      r->next=s; r=s;      //���뵽�ն˽��֮��
	}
    r->next=NULL;    //����������ϣ����ն˽���ָ�����ÿ�
 }
/*
*ǰ����������
*��    �룺��
*��    �ܣ���
*��    ������
*������������
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
*ǰ�����������������
*��    �룺��ѯԪ��λ��i
*��    �ܣ���λ����λ��Ϊi��Ԫ�ز����ֵ
*��    ������ѯԪ�ص�ֵ
*������������������
*/
template <class T>
T LinkList<T>::Get(int i) 
{   
  Node<T> *p; int j;
  p=first->next;  j=1;  //��p=first;  j=0;
  while (p && j<i)    
  {
    p=p->next;       //����ָ��p����
    j++;
  }
  if (!p) throw "λ��";
  else return p->data;
}

/*
*ǰ�����������������
*��    �룺��ѯԪ��ֵx
*��    �ܣ���ֵ����ֵ��Ԫ�ز����λ��
*��    ������ѯԪ�ص�λ��
*������������������
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
*ǰ�����������������
*��    �룺����Ԫ��x,����λ��i
*��    �ܣ���Ԫ��x���뵽��������λ��i��
*��    ������
*���������������������Ԫ��
*/
template <class T>  
void LinkList<T>::Insert(int i, T x)
{  
   Node<T> *p; int j;
   p=first ; j=0;    //����ָ��p��ʼ��
   while (p && j<i-1)
   {
     p=p->next;   //����ָ��p����
     j++;
   }
   if (!p) throw "λ��";
    else { 
	  Node<T> *s;
      s=new Node<T>; 
	  s->data=x;  //���ڴ�����һ�����s����������Ϊx
      s->next=p->next;       //�����s���뵽���p֮��
      p->next=s;
	}
}

/*
*ǰ�����������������
*��    �룺��
*��    �ܣ������������
*��    ������������
*������������������
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
*ǰ�����������������
*��    �룺Ҫɾ��Ԫ��λ��i
*��    �ܣ�ɾ����������λ��Ϊi��Ԫ��
*��    ������
*����������������ɾ��Ԫ��
*/
template <class T>  
T LinkList<T>::Delete(int i)
{ 
  Node<T> *p; int j;
  p=first ; j=0;  //����ָ��p��ʼ��
  while (p && j<i-1)  //���ҵ�i-1�����
  {
    p=p->next;
    j++;
  }
  if (!p || !p->next) throw "λ��";  //���p�����ڻ���p�ĺ�̽�㲻����
    else {
		  Node<T> *q; int x;
          q=p->next; x=q->data;  //�ݴ汻ɾ���
          p->next=q->next;  //ժ��
          delete q; 
          return x;
	}
}
/*
*ǰ�����������������
*��    �룺��
*��    �ܣ����������
*��    �����������Ԫ��
*������������������
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

