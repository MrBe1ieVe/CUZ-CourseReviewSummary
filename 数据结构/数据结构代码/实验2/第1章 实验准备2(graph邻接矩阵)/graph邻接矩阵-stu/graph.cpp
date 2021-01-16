#include<iostream>
#include <string>                  //引入标准库中的头文件
#include "graph.h"                //引入头文件
using namespace std;


/*   
 *前置条件：图不存在
 *输    入：无 
 *功    能：图的初始化
 *输    出：无
 *后置条件：构造一个空的图
 */
template <class T>
MGraph<T>::MGraph(T a[], int n, int e) 
{
	 vertexNum=n;                 //顶点数
	 arcNum=e;                    //边数
	 int i,j,k;
	 for (i=0; i<vertexNum; i++) 
	  vertex[i]=a[i];
	 for (i=0; i<vertexNum; i++)    //初始化邻接矩阵
		 for (j=0; j<vertexNum; j++)
			arc[i][j]=0;             
	 for (k=0; k<arcNum; k++)   //依次输入每一条边，并修改邻接矩阵的相应元素
		   {
			cin>>i>>j;                    //边依附的两个顶点的序号
			arc[i][j]=1;                  //置有边标志
			arc[j][i]=1;    
		   }
}

/*   
 *前置条件：图已存在
 *输    入：无
 *功    能：输出图中所有顶点的数据信息
 *输    出：图中所有顶点的数据信息
 *后置条件：图保持不变
 */
template <class T>
void MGraph<T>::PutVex( )           //取所有顶点            
{                                   //假设源点是第0个顶点，即顶点序号是0
	int i=0;
    for(i=0;i<vertexNum;i++)
	   {                            //输出图中所有的顶点
          cout<<vertex[i]<<"\n";
	   }
}
/*   
 *前置条件：图已存在
 *输入：顶点i
 *功能：输出图中顶点i的数据信息
 *输出：图中顶点i的数据信息
 *后置条件：图保持不变
 */
template <class T>
void MGraph<T>::GetVex(int i,T v[MaxSize])      //取顶点i             
{                                               //假设源点是第0个顶点，即顶点序号是0
	v[i]=vertex[i];
    if (i>vertexNum) throw "位置";              //顶点i不存在则抛出异常
	else
		cout<<v[i]<<"\n";                       //返回顶点i	
}

/*  
 *前置条件：图已存在
 *输    入：顶点name,位置num
 *功    能：在图中num位置插入一个顶点name 
 *输    出：如果插入不成功，抛出异常
 *后置条件：如果插入成功，图中增加了一个顶点
 */
template <class T> 
void MGraph<T>::InsertVex(int num,T name)        //在图中编号为num 前 插入一个顶点，值为name
{                                                //假设源点是第0个顶点，即顶点序号是0
 if ( num<0|| num>=vertexNum) throw "位置";       //如果num输入不正确抛出异常
 int row;                                        //行
 int col;                                        //列
 int numv;                                       //最后一个顶点所在的位置
	 numv = vertexNum-1;
	if(num>-1)                                      //num存在
	  vertexNum++;                                   //顶点数加1
	for(int i=numv+1;i>num;i--)                      //i从最后一个顶点的下一个位置开始循环
		vertex[i]=vertex[i-1];                       //把从num位置的顶点到最后一个顶点均向后移一位
	vertex[num]=name;                            //把要插入的顶点的值放在num位置上
	for(row=numv;row>=0;row--)                      //把从num列到最后一列的元素均向下移一列
	  {
		for(col=numv;col>=num;col--)
			  arc[row][col+1]=arc[row][col];
		 arc[row][num]=0;
	  }
	for(row=numv;row>=num;row--)                   //把从num行到最后一行的元素均向下移一行
		  for(col=0;col<=numv+1;col++)
			  arc[row+1][col]=arc[row][col];		
	for(col=0;col<vertexNum;col++)
			  arc[num][col]=0;                   //把num位置所在的行、列的值均置为无穷大
  
 }
/*   
 *前置条件：图已存在
 *输    入：顶点pos 
 *功    能：在图中删除顶点pos 
 *输    出：如果删除不成功，抛出异常
 *后置条件：如果删除成功，图中减少了一个顶点,相应顶点所建立的边也消去
 */
template <class T>
void MGraph<T>::DeleteVex(int pos)              //删除第pos个顶点
{                                               //假设源点是第0个顶点，即顶点序号是0
 if ( pos<0||  pos>MaxSize) throw "位置";       //如果pos输入不正确抛出异常
 int row;                                       //行
 int col;                                       //列
 int numv=vertexNum;                            //numv等于顶点数
  if(pos>-1)
  {                                    //pos存在 
	   for(int i=pos;i<numv-1;i++)
	      vertex[i]=vertex[i+1];                       //把从pos到最后的每个点的位置依次向前移一位
	   vertexNum--;                                 //顶点数减1
	   for(row=0;row<numv;row++)
	   {
		 for(col=pos;col<numv-1;col++)
			  arc[row][col]=arc[row][col+1];        //把从pos列到最后一列的元素均向前移一列
		 arc[row][numv-1]=0;                    
	   }
	   for(row=pos;row<numv-1;row++) 
		  for(col=0;col<numv;col++)
			  arc[row][col]=arc[row+1][col];        //把从pos行到最后一行的元素均向上移一行
	   for(col=0;col<numv;col++)
			  arc[numv-1][col]=0;  
  } 
}
/*   
 *前置条件：图已存在
 *输    入：顶点n、w 
 *功    能：在图中删除顶点n、w 依附的边 
 *输    出：如果删除不成功，抛出异常
 *后置条件：如果删除成功，图中减少了一条边
 */
template <class T>
void MGraph<T>::DeleteArc(int n, int w)        //在图中删除一条边，其依附的两个顶点的编号为i和j
{
 if ( n>MaxSize||  w>MaxSize) throw "位置";    //如果输入不正确抛出异常
   
  arc[n][w]=0;
  arc[w][n]=0; 
 
}
/*   
 *前置条件：图已存在
 *输    入：顶点i、j
 *功    能：在图中插入顶点i、j及其所依附的边 
 *输    出：如果插入不成功，抛出异常
 *后置条件：如果插入成功，图中增加了一条边
 */
template <class T>
void MGraph<T>::InsertArc(int i, int j,int n)   //在图中插入一条边，其依附的两个顶点的编号为i和j
{
  if ( i>MaxSize||  j>MaxSize) throw "位置";   //如果输入不正确抛出异常	
  arc[i][j]=n;
  arc[j][i]=n;
  cout<<"从"<<vertex[i]<<"到"<<vertex[j]<<"的路径长度为："<<arc[i][j]<<"\n"; //输出插入的两顶点之间的路径
} 

template <class T>
void MGraph<T>::putarc()   //输出所有的边
{
  if ( i>MaxSize||  j>MaxSize) throw "位置";   //如果输入不正确抛出异常	
  arc[i][j]=n;
  arc[j][i]=n;
  cout<<"从"<<vertex[i]<<"到"<<vertex[j]<<"的路径长度为："<<arc[i][j]<<"\n"; //输出插入的两顶点之间的路径
} 
