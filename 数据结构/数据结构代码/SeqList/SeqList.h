//SeqList.h 声明类SeqList,文件名为SeqList.h
#ifndef SeqList_H
#define SeqList_H
const int MaxSize=100;  //100只是示例性的数据，可以根据实际问题具体定义
template <class T>      //定义模板类SeqList
class SeqList
{
public:
   SeqList( );       //无参构造函数
   SeqList(T a[], int n);       //有参构造函数
   ~SeqList();             //析构函数为空
   int Length();           //求线性表的长度
   T Get(int i);         //按位查找，取线性表的第i个元素
   int Locate(T x);       //按值查找，求线性表中值为x的元素序号
   void Insert(int i, T x);  //在线性表中第i个位置插入值为x的元素
   T Delete(int i);        //删除线性表的第i个元素
   void PrintList();       //遍历线性表，按序号依次输出各元素
private:
   T data[MaxSize];      //存放数据元素的数组
   int length;            //线性表的长度
};
#endif