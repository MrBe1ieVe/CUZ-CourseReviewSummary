//声明类BiTree及定义结构BiNode,文件名为bitree.h
#ifndef BITREE_H
#define BITREE_H

template <class T>
struct BiNode   //二叉树的结点结构
{
  T data;       
  BiNode<T> *lchild, *rchild;
};

template <class T>
class BiTree
{
public:
    BiTree( );             //构造函数，初始化一棵二叉树，其前序序列由键盘输入
    ~BiTree(void);         //析构函数，释放二叉链表中各结点的存储空间
	BiNode<T>* Getroot();  //获得指向根结点的指针
    void PreOrder(BiNode<T> *root);     //前序遍历二叉树
    void InOrder(BiNode<T> *root);      //中序遍历二叉树
    void PostOrder(BiNode<T> *root);    //后序遍历二叉树
    void LeverOrder(BiNode<T> *root);   //层序遍历二叉树
	//---------FJJ ADD-----------
	void fdg_PreOrder(BiNode<T> *root);     //非递归前序遍历二叉树
    void fdg_InOrder(BiNode<T> *root);      //非递归中序遍历二叉树
    void fdg_PostOrder(BiNode<T> *root);    //非递归后序遍历二叉树
private:
    BiNode<T> *root;         //指向根结点的头指针
    BiNode<T> *Creat( );     //有参构造函数调用
    void Release(BiNode<T> *root);   //析构函数调用 
};
#endif