//BothStack.cpp
#include "BothStack.h"

/*
 * ǰ��������ջ������
 * ��    �룺��
 * ��    �ܣ�ջ�ĳ�ʼ��
 * ��    ������
 * ��������������һ����ջ
 */

template <class T>
BothStack<T>::BothStack( )
{
	top1= -1;  
	top2=StackSize;
} 

/*
 * ǰ������������ռ��Ѵ���
 * ��    �룺��
 * ��    �ܣ�������ջ���������ռ�
 * ��    ������
 * ��������������ջ���������ռ��ͷ�
 */

template <class T>
BothStack<T>::~BothStack( ) 
{

}

/* 
 * ǰ������������ռ��Ѵ���
 * ��    �룺ջ��i��Ԫ��ֵx
 * ��    �ܣ���ջi������һ��Ԫ��x
 * ��    ���������벻�ɹ������׳������쳣
 * ����������������ɹ�����ջi��������һ��ջ��Ԫ��
 */

template <class T> 
void BothStack<T>::Push(int i, T x )
{
    if (top1==top2-1) 
		throw "����";
    if (i==1) 
		data[++top1]=x;
    if (i==2) 
		data[--top2]=x;
}

/*
 * ǰ������������ռ��Ѵ���
 * ��    �룺ջ��i
 * ��    �ܣ���ջi��ɾ��ջ��Ԫ��
 * ��    ������ɾ�����ɹ������׳�ɾ���쳣
 * ������������ɾ���ɹ�����ջi��ɾ����ջ��Ԫ��
 */

template <class T>
T BothStack<T>::Pop(int i)
{
    if (i==1) //��ջ1��ջ��Ԫ�س�ջ
	{   
        if (top1== -1) 
			throw "����";
        return data[top1--];
	}
    if (i==2)  //��ջ2��ջ��Ԫ�س�ջ
	{                           
        if (top2==StackSize) 
			throw "����";
        return data[top2++]; 
	}
}

/*
 * ǰ������������ռ��Ѵ���
 * ��    �룺ջ��i
 * ��    �ܣ���ȡջi��ǰ��ջ��Ԫ��
 * ��    ������ջi���գ�����ջi��ǰ��ջ��Ԫ��ֵ
 * ������������ջ������
 */

template <class T> 
T BothStack<T>::GetTop(int i)
{
    if(i==1)
	{
        if (top1!=-1) 
			return data[top1];
	}
    if(i==2)
	{
	    if(top2!=StackSize)
			return data[top2];
   } 
}

/*
 * ǰ������������ռ��Ѵ���
 * ��    �룺ջ��i
 * ��    �ܣ��ж�ջi�Ƿ�Ϊ��ջ
 * ��    ������ջiΪ��ջ������1�����򷵻�0
 * ������������ջ������
 */

template <class T> 
bool BothStack<T>::Empty(int i)
{  
    if(i==1)
	{
	    if(top1==-1) 
			return 0;
	    else 
			return 1;
	}
    if(i==2)
	{
	    if(top2==StackSize)
			return 0;
	    else 
			return 1;
	}
}

