//SeqStack.cpp
#include "SeqStack.h"

/*
 * 前置条件：栈不存在
 * 输    入：无
 * 功    能：栈的初始化
 * 输    出：无
 * 后置条件：构造一个空栈
 */

template <class T>
SeqStack<T>::SeqStack( )
{
	top=-1;
}

/*
 * 前置条件：栈已存在
 * 输    入：无
 * 功    能：销毁栈
 * 输    出：无
 * 后置条件：释放栈所占用的存储空间
 */

template <class T>
SeqStack<T>::~SeqStack( )
{

} 

/*
 * 前置条件：栈已存在
 * 输    入：元素值x
 * 功    能：在栈顶插入一个元素x
 * 输    出：如果插入不成功，抛出异常
 * 后置条件：如果插入成功，栈顶增加了一个元素
 */

template <class T> 
void SeqStack<T>::Push(T x)
{
    if (top== StackSize-1) throw "上溢";
    top++;
    data[top]=x;
}

/*
 * 前置条件：栈已存在
 * 输    入：无
 * 功    能：删除栈顶元素
 * 输    出：如果删除成功，返回被删元素值，否则，抛出异常
 * 后置条件：如果删除成功，栈顶减少了一个元素
 */     

template <class T>
T SeqStack<T>::Pop( )
{ 
    T x;
    if (top==-1) throw "下溢";
    x=data[top--];
    return x;
}

/*
 * 前置条件：栈已存在
 * 输    入：无
 * 功    能：读取当前的栈顶元素
 * 输    出：若栈不空，返回当前的栈顶元素值
 * 后置条件：栈不变
 */

template <class T> 
T SeqStack<T>::GetTop( )
{
	if (top!=-1)  
    return data[top];
}

/*
 * 前置条件：栈已存在
 * 输    入：无
 * 功    能：判断栈是否为空
 * 输    出：如果栈为空，返回1，否则，返回0
 * 后置条件：栈不变
 */

template <class T> 
bool SeqStack<T>::Empty( )
{
	if(top==-1) return 1;
	else return 0;
} 