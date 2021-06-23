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
friend ostream & operator<<(ostream &out, CMyPoint &A){out<<A.x<<" "<<A.y;return out;}  //����<<������������CMyPoint�� 

CMyPoint operator++(){++x;++y;return *this;}    										//++P
CMyPoint operator++(int){CMyPoint Tmp(*this);++x;++y;return Tmp;}   					//P++

CMyPoint operator+(CMyPoint &p){CMyPoint a;a.x=x+p.x;a.y=y+p.y;return a;}				//P+q	
//friend CMyPoint operator+(CMyPoint &p,CMyPoint &q){return CMyPoint(p.x+q.x,p.y+q.y);}	//P+q		
		
friend CMyPoint operator+(int t,CMyPoint &p){CMyPoint a;a.x=t+p.x;a.y=p.y;return a;}	//(����)x+P	
//friend CMyPoint operator+(int x,CMyPoint &p){return CMyPoint(p.x+x,p.y);}				//(����)x+P	

CMyPoint operator+(int t){return CMyPoint(x+t,y);}										//P+(����)x	
//friend CMyPoint operator+(CMyPoint &p,int x){return CMyPoint(p.x+x,p.y);}				//P+(����)x	
//friend CMyPoint operator+(CMyPoint &p,int t){CMyPoint a;a.x=t+p.x;a.y=p.y;return a;}	//P+(����)x		
~CMyPoint(){}; 
};


class CArray
{
private:
    int nSizeOfInt;  //��������Ĵ�С
    int nNumOfInt;  //����������ʵ�ʴ�ŵ�Ԫ�ظ���
    int nSizeOfFloat;  //��������Ĵ�С
    int nNumOfFloat;  //����������ʵ�ʴ�ŵ�Ԫ�ظ���
    int *pInt;    //ָ���������飬��̬�����ڴ�ռ�
    float *pFloat;   //ָ�򸡵����飬��̬�����ڴ�ռ�
public:
//���б��ʼ�����캯��

CArray(int nIntSize=100,int nFloatSize=200)
	{
	nSizeOfInt=nIntSize;
	nSizeOfFloat=nFloatSize;
	pInt=new int[nSizeOfInt];
	pFloat=new float[nSizeOfFloat];
	nNumOfFloat=0;
	nNumOfInt=0;
	}  
/*�� CArray(int nIntSize=100,int nFloatSize=200):nSizeOfInt(nIntSize),nSizeOfFloat(nFloatSize){pInt=new int[nSizeOfInt];
pFloat=new float[nSizeOfFloat];nNumOfFloat=0;nNumOfInt=0;};*/

//���캯�������г�ʼ��

void put(int n){pInt[nNumOfInt]=n;nNumOfInt++;}   
//��n���뵽����������

void put(float x){pFloat[nNumOfFloat]=x;nNumOfFloat++;}   
//��x���뵽����������

int getInt(int index){return pInt[index];}  
//ȡ���������е�index��Ԫ�أ�index��0��ʼ

float getFloat(int index){return pFloat[index];} 
//ȡ���������е�index��Ԫ�أ�index��0��ʼ

~CArray(){delete [] pInt;delete [] pFloat;}    
//�����������ͷŶ�̬������ڴ�ռ�

void print()
	{
	int I=nNumOfInt,F=nNumOfFloat,i=0,f=0;
	while(I--)cout<<pInt[i++]<<" ";
	cout<<"\n";
	while(F--)cout<<pFloat[f++]<<" ";
//	cout<<nSizeOfInt<<" "<<nSizeOfFloat;
	}   
//�ֱ������������͸��������е�����Ԫ��

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


