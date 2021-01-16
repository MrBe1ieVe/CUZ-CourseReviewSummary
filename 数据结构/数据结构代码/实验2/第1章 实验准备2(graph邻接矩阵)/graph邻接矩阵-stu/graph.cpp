#include<iostream>
#include <string>                  //�����׼���е�ͷ�ļ�
#include "graph.h"                //����ͷ�ļ�
using namespace std;


/*   
 *ǰ��������ͼ������
 *��    �룺�� 
 *��    �ܣ�ͼ�ĳ�ʼ��
 *��    ������
 *��������������һ���յ�ͼ
 */
template <class T>
MGraph<T>::MGraph(T a[], int n, int e) 
{
	 vertexNum=n;                 //������
	 arcNum=e;                    //����
	 int i,j,k;
	 for (i=0; i<vertexNum; i++) 
	  vertex[i]=a[i];
	 for (i=0; i<vertexNum; i++)    //��ʼ���ڽӾ���
		 for (j=0; j<vertexNum; j++)
			arc[i][j]=0;             
	 for (k=0; k<arcNum; k++)   //��������ÿһ���ߣ����޸��ڽӾ������ӦԪ��
		   {
			cin>>i>>j;                    //��������������������
			arc[i][j]=1;                  //���б߱�־
			arc[j][i]=1;    
		   }
}

/*   
 *ǰ��������ͼ�Ѵ���
 *��    �룺��
 *��    �ܣ����ͼ�����ж����������Ϣ
 *��    ����ͼ�����ж����������Ϣ
 *����������ͼ���ֲ���
 */
template <class T>
void MGraph<T>::PutVex( )           //ȡ���ж���            
{                                   //����Դ���ǵ�0�����㣬�����������0
	int i=0;
    for(i=0;i<vertexNum;i++)
	   {                            //���ͼ�����еĶ���
          cout<<vertex[i]<<"\n";
	   }
}
/*   
 *ǰ��������ͼ�Ѵ���
 *���룺����i
 *���ܣ����ͼ�ж���i��������Ϣ
 *�����ͼ�ж���i��������Ϣ
 *����������ͼ���ֲ���
 */
template <class T>
void MGraph<T>::GetVex(int i,T v[MaxSize])      //ȡ����i             
{                                               //����Դ���ǵ�0�����㣬�����������0
	v[i]=vertex[i];
    if (i>vertexNum) throw "λ��";              //����i���������׳��쳣
	else
		cout<<v[i]<<"\n";                       //���ض���i	
}

/*  
 *ǰ��������ͼ�Ѵ���
 *��    �룺����name,λ��num
 *��    �ܣ���ͼ��numλ�ò���һ������name 
 *��    ����������벻�ɹ����׳��쳣
 *�����������������ɹ���ͼ��������һ������
 */
template <class T> 
void MGraph<T>::InsertVex(int num,T name)        //��ͼ�б��Ϊnum ǰ ����һ�����㣬ֵΪname
{                                                //����Դ���ǵ�0�����㣬�����������0
 if ( num<0|| num>=vertexNum) throw "λ��";       //���num���벻��ȷ�׳��쳣
 int row;                                        //��
 int col;                                        //��
 int numv;                                       //���һ���������ڵ�λ��
	 numv = vertexNum-1;
	if(num>-1)                                      //num����
	  vertexNum++;                                   //��������1
	for(int i=numv+1;i>num;i--)                      //i�����һ���������һ��λ�ÿ�ʼѭ��
		vertex[i]=vertex[i-1];                       //�Ѵ�numλ�õĶ��㵽���һ������������һλ
	vertex[num]=name;                            //��Ҫ����Ķ����ֵ����numλ����
	for(row=numv;row>=0;row--)                      //�Ѵ�num�е����һ�е�Ԫ�ؾ�������һ��
	  {
		for(col=numv;col>=num;col--)
			  arc[row][col+1]=arc[row][col];
		 arc[row][num]=0;
	  }
	for(row=numv;row>=num;row--)                   //�Ѵ�num�е����һ�е�Ԫ�ؾ�������һ��
		  for(col=0;col<=numv+1;col++)
			  arc[row+1][col]=arc[row][col];		
	for(col=0;col<vertexNum;col++)
			  arc[num][col]=0;                   //��numλ�����ڵ��С��е�ֵ����Ϊ�����
  
 }
/*   
 *ǰ��������ͼ�Ѵ���
 *��    �룺����pos 
 *��    �ܣ���ͼ��ɾ������pos 
 *��    �������ɾ�����ɹ����׳��쳣
 *�������������ɾ���ɹ���ͼ�м�����һ������,��Ӧ�����������ı�Ҳ��ȥ
 */
template <class T>
void MGraph<T>::DeleteVex(int pos)              //ɾ����pos������
{                                               //����Դ���ǵ�0�����㣬�����������0
 if ( pos<0||  pos>MaxSize) throw "λ��";       //���pos���벻��ȷ�׳��쳣
 int row;                                       //��
 int col;                                       //��
 int numv=vertexNum;                            //numv���ڶ�����
  if(pos>-1)
  {                                    //pos���� 
	   for(int i=pos;i<numv-1;i++)
	      vertex[i]=vertex[i+1];                       //�Ѵ�pos������ÿ�����λ��������ǰ��һλ
	   vertexNum--;                                 //��������1
	   for(row=0;row<numv;row++)
	   {
		 for(col=pos;col<numv-1;col++)
			  arc[row][col]=arc[row][col+1];        //�Ѵ�pos�е����һ�е�Ԫ�ؾ���ǰ��һ��
		 arc[row][numv-1]=0;                    
	   }
	   for(row=pos;row<numv-1;row++) 
		  for(col=0;col<numv;col++)
			  arc[row][col]=arc[row+1][col];        //�Ѵ�pos�е����һ�е�Ԫ�ؾ�������һ��
	   for(col=0;col<numv;col++)
			  arc[numv-1][col]=0;  
  } 
}
/*   
 *ǰ��������ͼ�Ѵ���
 *��    �룺����n��w 
 *��    �ܣ���ͼ��ɾ������n��w �����ı� 
 *��    �������ɾ�����ɹ����׳��쳣
 *�������������ɾ���ɹ���ͼ�м�����һ����
 */
template <class T>
void MGraph<T>::DeleteArc(int n, int w)        //��ͼ��ɾ��һ���ߣ�����������������ı��Ϊi��j
{
 if ( n>MaxSize||  w>MaxSize) throw "λ��";    //������벻��ȷ�׳��쳣
   
  arc[n][w]=0;
  arc[w][n]=0; 
 
}
/*   
 *ǰ��������ͼ�Ѵ���
 *��    �룺����i��j
 *��    �ܣ���ͼ�в��붥��i��j�����������ı� 
 *��    ����������벻�ɹ����׳��쳣
 *�����������������ɹ���ͼ��������һ����
 */
template <class T>
void MGraph<T>::InsertArc(int i, int j,int n)   //��ͼ�в���һ���ߣ�����������������ı��Ϊi��j
{
  if ( i>MaxSize||  j>MaxSize) throw "λ��";   //������벻��ȷ�׳��쳣	
  arc[i][j]=n;
  arc[j][i]=n;
  cout<<"��"<<vertex[i]<<"��"<<vertex[j]<<"��·������Ϊ��"<<arc[i][j]<<"\n"; //��������������֮���·��
} 

template <class T>
void MGraph<T>::putarc()   //������еı�
{
  if ( i>MaxSize||  j>MaxSize) throw "λ��";   //������벻��ȷ�׳��쳣	
  arc[i][j]=n;
  arc[j][i]=n;
  cout<<"��"<<vertex[i]<<"��"<<vertex[j]<<"��·������Ϊ��"<<arc[i][j]<<"\n"; //��������������֮���·��
} 
