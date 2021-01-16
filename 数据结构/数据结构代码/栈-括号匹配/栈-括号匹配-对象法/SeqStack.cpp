//SeqStack.cpp
#include "SeqStack.h"

/*
 * ǰ��������ջ������
 * ��    �룺��
 * ��    �ܣ�ջ�ĳ�ʼ��
 * ��    ������
 * ��������������һ����ջ
 */

template <class T>
SeqStack<T>::SeqStack( )
{
	top=-1;
}

/*
 * ǰ��������ջ�Ѵ���
 * ��    �룺��
 * ��    �ܣ�����ջ
 * ��    ������
 * �����������ͷ�ջ��ռ�õĴ洢�ռ�
 */

template <class T>
SeqStack<T>::~SeqStack( )
{

} 

/*
 * ǰ��������ջ�Ѵ���
 * ��    �룺Ԫ��ֵx
 * ��    �ܣ���ջ������һ��Ԫ��x
 * ��    ����������벻�ɹ����׳��쳣
 * �����������������ɹ���ջ��������һ��Ԫ��
 */

template <class T> 
void SeqStack<T>::Push(T x)
{
    if (top== StackSize-1) throw "����";
    top++;
    data[top]=x;
}

/*
 * ǰ��������ջ�Ѵ���
 * ��    �룺��
 * ��    �ܣ�ɾ��ջ��Ԫ��
 * ��    �������ɾ���ɹ������ر�ɾԪ��ֵ�������׳��쳣
 * �������������ɾ���ɹ���ջ��������һ��Ԫ��
 */     

template <class T>
T SeqStack<T>::Pop( )
{ 
    T x;
    if (top==-1) throw "����";
    x=data[top--];
    return x;
}

/*
 * ǰ��������ջ�Ѵ���
 * ��    �룺��
 * ��    �ܣ���ȡ��ǰ��ջ��Ԫ��
 * ��    ������ջ���գ����ص�ǰ��ջ��Ԫ��ֵ
 * ����������ջ����
 */

template <class T> 
T SeqStack<T>::GetTop( )
{
	if (top!=-1)  
    return data[top];
}

/*
 * ǰ��������ջ�Ѵ���
 * ��    �룺��
 * ��    �ܣ��ж�ջ�Ƿ�Ϊ��
 * ��    �������ջΪ�գ�����1�����򣬷���0
 * ����������ջ����
 */

template <class T> 
bool SeqStack<T>::Empty( )
{
	if(top==-1) return 1;
	else return 0;
} 