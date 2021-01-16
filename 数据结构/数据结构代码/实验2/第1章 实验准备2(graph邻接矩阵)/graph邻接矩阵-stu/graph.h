#ifndef GRAPH_H                           //����ͷ�ļ�
#define GRAPH_H
#include<string>                          //�����׼���е�ͷ�ļ�
using namespace std;

const int MaxSize=12;                     //ͼ����ඥ�����


template <class T>
class MGraph
{
public:
    MGraph(T a[],int n,int e);             //���캯������ʼ������n�������ͼ
    void PutVex();                         //ȡ����               
    void GetVex(int i,T v[MaxSize] );      //ȡͼ�е�i������������Ϣ
    void DeleteVex(int i);                 //ɾ��ͼ�е�i������
    void InsertVex(int num,T value);       //��ͼ�в���һ�����㣬����Ϊi��ֵΪvalue
	void DeleteArc(int i, int j);          //��ͼ��ɾ��һ���ߣ�����������������ı��Ϊi��j
    void InsertArc(int i, int j,int n);    //��ͼ�в���һ���ߣ�����������������ı��Ϊi��j
	void putarc(T a[],int n);//������еı�
   
public:
    T  vertex[MaxSize];                    //���ͼ�ж��������
    int arc[MaxSize][MaxSize];             //���ͼ�бߵ�����
    int vertexNum,arcNum;                  //ͼ�Ķ������ͱ���
 };

#endif