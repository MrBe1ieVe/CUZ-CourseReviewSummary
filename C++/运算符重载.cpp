#include<iostream>
#include<math.h>
using namespace std;
class CMyPoint
{     
private:
int x, y; 
public:
CMyPoint(int i=0, int j=0){ x=i; y=j; }
operator double(){return pow(x*x+y*y,0.5);}												//(double)P=x*x+y*y
friend ostream & operator<<(ostream &out, CMyPoint &A){out<<A.x<<" "<<A.y;return out;}  //重载<<运算符方便输出CMyPoint类 

CMyPoint operator++(){++x;++y;return *this;}    										//++P
CMyPoint operator++(int){CMyPoint Tmp(*this);++x;++y;return Tmp;}   					//P++

CMyPoint operator+(CMyPoint &p){CMyPoint a;a.x=x+p.x;a.y=y+p.y;return a;}				//P+q	
//friend CMyPoint operator+(CMyPoint &p,CMyPoint &q){return CMyPoint(p.x+q.x,p.y+q.y);}	//P+q		
		
friend CMyPoint operator+(int t,CMyPoint &p){CMyPoint a;a.x=t+p.x;a.y=p.y;return a;}	//(常数)x+P	
//friend CMyPoint operator+(int x,CMyPoint &p){return CMyPoint(p.x+x,p.y);}				//(常数)x+P	

CMyPoint operator+(int t){return CMyPoint(x+t,y);}										//P+(常数)x	
//friend CMyPoint operator+(CMyPoint &p,int x){return CMyPoint(p.x+x,p.y);}				//P+(常数)x	
//friend CMyPoint operator+(CMyPoint &p,int t){CMyPoint a;a.x=t+p.x;a.y=p.y;return a;}	//P+(常数)x		
~CMyPoint(){}; 
};


class CArray
{
private:
    int nSizeOfInt;  //整形数组的大小
    int nNumOfInt;  //整形数组中实际存放的元素个数
    int nSizeOfFloat;  //浮点数组的大小
    int nNumOfFloat;  //浮点数组中实际存放的元素个数
    int *pInt;    //指向整形数组，动态分配内存空间
    float *pFloat;   //指向浮点数组，动态分配内存空间
public:
//数列表初始化构造函数

CArray(int nIntSize=100,int nFloatSize=200)
	{
	nSizeOfInt=nIntSize;
	nSizeOfFloat=nFloatSize;
	pInt=new int[nSizeOfInt];
	pFloat=new float[nSizeOfFloat];
	nNumOfFloat=0;
	nNumOfInt=0;
	}  
/*或 CArray(int nIntSize=100,int nFloatSize=200):nSizeOfInt(nIntSize),nSizeOfFloat(nFloatSize){pInt=new int[nSizeOfInt];
pFloat=new float[nSizeOfFloat];nNumOfFloat=0;nNumOfInt=0;};*/

//构造函数，进行初始化

void put(int n){pInt[nNumOfInt]=n;nNumOfInt++;}   
//将n加入到整形数组中

void put(float x){pFloat[nNumOfFloat]=x;nNumOfFloat++;}   
//将x加入到浮点数组中

int getInt(int index){return pInt[index];}  
//取整形数组中第index个元素，index从0开始

float getFloat(int index){return pFloat[index];} 
//取浮点数组中第index个元素，index从0开始

~CArray(){delete [] pInt;delete [] pFloat;}    
//析构函数，释放动态分配的内存空间

void print()
	{
	int I=nNumOfInt,F=nNumOfFloat,i=0,f=0;
	while(I--)cout<<pInt[i++]<<" ";
	cout<<"\n";
	while(F--)cout<<pFloat[f++]<<" ";
//	cout<<nSizeOfInt<<" "<<nSizeOfFloat;
	}   
//分别输出整形数组和浮点数组中的所有元素

};
int main()
{
    CMyPoint P(3,4),q;
    cout<<(double)P<<endl;
    q=P++;
    cout<<q<<endl;
    q=P+q;
    cout<<q<<endl;
    q=q+1;
    cout<<q<<endl;
    q=1+q;
    cout<<q<<endl;
int n=10;
float a=0.5;
CArray A;
A.put(n);
A.put(a);
A.put(n+1);
A.put(a+1);
A.print();
}


