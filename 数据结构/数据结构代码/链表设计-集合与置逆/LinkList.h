//LinkList.h  声明类LinkList
#ifndef LinkList_H
#define LinkList_H
template <class T>
struct Node
{
  T data;
  Node<T> *next;  //此处<T>也可以省略
};

template <class T>
class LinkList
{
  public:
    LinkList( );  //建立只有头结点的空链表
    LinkList(T a[ ], int n);  //建立有n个元素的单链表
    ~LinkList();             //析构函数
    int Length();          //求单链表的长度
    T Get(int i);           //取单链表中第i个结点的元素值
    int Locate(T x);       //求单链表中值为x的元素序号
    void Insert(int i, T x);   //在单链表中第i个位置插入元素值为x的结点
    T Delete(int i);        //在单链表中删除第i个结点
    void PrintList( );           //遍历单链表，按序号依次输出各元素
	void Empty();
  public:
   Node<T> *first;  //单链表的头指针
};

#endif
