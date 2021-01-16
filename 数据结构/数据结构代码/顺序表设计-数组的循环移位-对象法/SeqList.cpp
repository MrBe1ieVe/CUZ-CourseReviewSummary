//SeqList.cpp  
#include "SeqList.h"
/*
*ǰ��������˳�������
*��    �룺��
*��    �ܣ�����һ��˳���
*��    ������
*��������������һ��˳���
*/
template <class T> 
SeqList<T>:: SeqList( )
{
  length=0;
}
/*
*ǰ��������˳�������
*��    �룺˳�����Ϣ��������ʽa[],˳�����n
*��    �ܣ�������a[]��Ԫ�ؽ�Ϊ����Ϊn��˳���
*��    ������
*��������������һ��˳���
*/
template <class T> 
SeqList<T>:: SeqList(T a[], int n)
{
  if (n>MaxSize) throw "�����Ƿ�";
  for (int i=0; i<n; i++)  
    data[i]=a[i];
  length=n;
}
/*
*ǰ����������
*��    �룺��
*��    �ܣ���
*��    ������
*������������
*/
template <class T> 
SeqList<T>:: ~SeqList( )
{
}
/*
*ǰ��������˳������
*��    �룺����Ԫ��x,����λ��i
*��    �ܣ���Ԫ��x���뵽˳�����λ��i��
*��    ������
*����������˳��������Ԫ��
*/
template <class T> 
void SeqList<T>::Insert(int i, T x)
{ 
	int j;
  if (length>=MaxSize) throw "����";
    if (i<1 || i>length+1) throw "λ��";
  for (j=length; j>=i; j--)
  data[j]=data[j-1];   //ע���j��Ԫ�ش��������±�Ϊj-1��
  data[i-1]=x;
  length++;
}

/*
*ǰ��������˳������
*��    �룺Ҫɾ��Ԫ��λ��i
*��    �ܣ�ɾ��˳�����λ��Ϊi��Ԫ��
*��    ������
*����������˳���ɾ��Ԫ��
*/
template <class T>
T SeqList<T>::Delete(int i)
{ 
	int x,j;
  if (length==0) throw "����";
  if (i<1 || i>length) throw "λ��";
  x=data[i-1];
  for (j=i; j<length; j++)
    data[j-1]=data[j];   //ע��˴�j�Ѿ���Ԫ�����ڵ������±�
  length--;
  return x;
}
/*
*ǰ��������˳������
*��    �룺��
*��    �ܣ����˳�����
*��    ����˳�����
*����������˳�����
*/
template <class T>
int SeqList<T>::Length()
{
	 return length;
}
/*
*ǰ��������˳������
*��    �룺��ѯԪ��λ��i
*��    �ܣ���λ����λ��Ϊi��Ԫ�ز����ֵ
*��    ������ѯԪ�ص�ֵ
*����������˳�����
*/
template <class T> 
T SeqList<T>::Get(int i)
{
  if (i<1 && i>length) throw "����λ�÷Ƿ�";
    else return data[i-1];
}
/*
*ǰ��������˳������
*��    �룺��ѯԪ��ֵx
*��    �ܣ���ֵ����ֵ��Ԫ�ز����λ��
*��    ������ѯԪ�ص�λ��
*����������˳�����
*/
template <class T>
int SeqList<T>::Locate(T x)
{     
	  for (int i=0; i<length; i++)
	   if (data[i]==x) 
	     return i+1 ;  //�±�Ϊi��Ԫ�ص���x�����������i+1
	  return 0;  //�˳�ѭ����˵������ʧ��
}
/*
*ǰ��������˳������
*��    �룺��
*��    �ܣ�˳������
*��    �����������Ԫ��
*����������˳�����
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
   Reverse( 0, i-1);   //ǰi��Ԫ������
   Reverse( i, length-1);   //��n-i��Ԫ������
   Reverse( 0, length-1);   //������������
 }

template <class T>
void SeqList<T>::Reverse( int from, int to)

                           //������A��Ԫ�ش�from��to����
{  T temp;
   for (int i=0; i<(to-from+1)/2; i++)
   {
        temp=data[from+i];   // ����Ԫ��
		data[from+i]=data[to-i];
		data[to-i]=temp;
   }       
                 
}
