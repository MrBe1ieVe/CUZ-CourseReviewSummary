//SeqList.cpp  
#include "SeqList.h"
/*
*前置条件：顺序表不存在
*输    入：无
*功    能：构建一个顺序表
*输    出：无
*后置条件：构建一个顺序表
*/
template <class T> 
SeqList<T>:: SeqList( )
{
  length=0;
}
/*
*前置条件：顺序表不存在
*输    入：顺序表信息的数组形式a[],顺序表长度n
*功    能：将数组a[]中元素建为长度为n的顺序表
*输    出：无
*后置条件：构建一个顺序表
*/
template <class T> 
SeqList<T>:: SeqList(T a[], int n)
{
  if (n>MaxSize) throw "参数非法";
  for (int i=0; i<n; i++)  
    data[i]=a[i];
  length=n;
}
/*
*前置条件：无
*输    入：无
*功    能：无
*输    出：无
*后置条件：无
*/
template <class T> 
SeqList<T>:: ~SeqList( )
{
}
/*
*前置条件：顺序表存在
*输    入：插入元素x,插入位置i
*功    能：将元素x插入到顺序表中位置i处
*输    出：无
*后置条件：顺序表插入新元素
*/
template <class T> 
void SeqList<T>::Insert(int i, T x)
{ 
	int j;
  if (length>=MaxSize) throw "上溢";
    if (i<1 || i>length+1) throw "位置";
  for (j=length; j>=i; j--)
  data[j]=data[j-1];   //注意第j个元素存在数组下标为j-1处
  data[i-1]=x;
  length++;
}

/*
*前置条件：顺序表存在
*输    入：要删除元素位置i
*功    能：删除顺序表中位置为i的元素
*输    出：无
*后置条件：顺序表删除元素
*/
template <class T>
T SeqList<T>::Delete(int i)
{ 
	int x,j;
  if (length==0) throw "下溢";
  if (i<1 || i>length) throw "位置";
  x=data[i-1];
  for (j=i; j<length; j++)
    data[j-1]=data[j];   //注意此处j已经是元素所在的数组下标
  length--;
  return x;
}
/*
*前置条件：顺序表存在
*输    入：无
*功    能：输出顺序表长度
*输    出：顺序表长度
*后置条件：顺序表不变
*/
template <class T>
int SeqList<T>::Length()
{
	 return length;
}
/*
*前置条件：顺序表存在
*输    入：查询元素位置i
*功    能：按位查找位置为i的元素并输出值
*输    出：查询元素的值
*后置条件：顺序表不变
*/
template <class T> 
T SeqList<T>::Get(int i)
{
  if (i<1 && i>length) throw "查找位置非法";
    else return data[i-1];
}
/*
*前置条件：顺序表存在
*输    入：查询元素值x
*功    能：按值查找值的元素并输出位置
*输    出：查询元素的位置
*后置条件：顺序表不变
*/
template <class T>
int SeqList<T>::Locate(T x)
{     
	  for (int i=0; i<length; i++)
	   if (data[i]==x) 
	     return i+1 ;  //下标为i的元素等于x，返回其序号i+1
	  return 0;  //退出循环，说明查找失败
}
/*
*前置条件：顺序表存在
*输    入：无
*功    能：顺序表遍历
*输    出：输出所有元素
*后置条件：顺序表不变
*/
template <class T>
void SeqList<T>::PrintList()
{
	for(int i=0;i<length;i++)
	cout<<data[i]<<endl;
}

template <class T>
void SeqList<T>::Converse( int i)
 {
   Reverse( 0, i-1);   //前i个元素逆置
   Reverse( i, length-1);   //后n-i个元素逆置
   Reverse( 0, length-1);   //整个数组逆置
 }

template <class T>
void SeqList<T>::Reverse( int from, int to)

                           //将数组A中元素从from到to逆置
{  T temp;
   for (int i=0; i<(to-from+1)/2; i++)
   {
        temp=data[from+i];   // 交换元素
		data[from+i]=data[to-i];
		data[to-i]=temp;
   }       
                 
}
