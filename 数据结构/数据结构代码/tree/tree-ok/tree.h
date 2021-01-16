//声明树中的类以及结点结构，文件名为tree.h
#ifndef TREE_H
#define TREE_H

template <class T>//树中结点采用孩子兄弟表示法
struct TNode
{
  T data;
  TNode<T> *firstchild, *rightsib;
};

template <class T>
class Tree
{
public:
    Tree( );               //构造函数，初始化一棵树，其前序序列由键盘输入
    ~Tree(void);           //析构函数，释放树中各结点的存储空间
	TNode<T>* Getroot( );  //获得指向根结点的指针
    void PreOrder(TNode<T> *root);     //前序遍历树
    void PostOrder(TNode<T> *root);    //后序遍历树
    void LeverOrder(TNode<T> *root);   //层序遍历树
private:
    TNode<T> *root;         //指向根结点的头指针
    void Release(TNode<T> *root);   //析构函数调用 
};

  #endif