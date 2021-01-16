//定义类中的成员函数，文件名为bitree.cpp
#include<iostream>
#include<string>
#include"bitree.h"
using namespace std;

/*
 *前置条件：二叉树不存在
 *输    入：无
 *功    能：构造一棵二叉树
 *输    出：无
 *后置条件：产生一棵二叉树 
 */
template<class T>
BiTree<T>::BiTree( )
{
	this->root = Creat( );
}
/*
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：释放二叉链表中各结点的存储空间
 *输    出：无
 *后置条件：二叉树不存在 
 */
template<class T>
BiTree<T>::~BiTree(void)
{
	Release(root);
}
/*
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：获取指向二叉树根结点的指针
 *输    出：指向二叉树根结点的指针
 *后置条件：二叉树不变 
 */
template<class T>
BiNode<T>* BiTree<T>::Getroot( )
{
	return root;
}
/*
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：前序遍历二叉树
 *输    出：二叉树中结点的一个线性排列
 *后置条件：二叉树不变 
 */
template<class T>
void BiTree<T>::PreOrder(BiNode<T> *root)
{
	if(root==NULL)  return;
	else{		
		cout<<root->data<<" ";
        PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}

//---------------------FJJ ADD---------------------------
template<class T>           
void BiTree<T>::fdg_PreOrder(BiNode<T> *root)  
{
   	const int MaxSize = 100;
	BiNode<T>* S[MaxSize]; // 采用顺序栈
    BiNode<T>* q;
	int top=-1;
	if (root!=NULL)
    	S[++top]=root;
	while(top!=-1)
	{
        q=S[top--];  //出栈
        cout<<q->data<<" "; 
		if(q->rchild != NULL) S[++top]=q->rchild;  //注意左右孩子压栈顺序
        if(q->lchild != NULL) S[++top]=q->lchild;
	}

}
//------------------------------------------------
/*
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：中序遍历二叉树
 *输    出：二叉树中结点的一个线性排列
 *后置条件：二叉树不变 
 */
template <class T>
void BiTree<T>::InOrder (BiNode<T> *root)
{
    if (root==NULL)  return;      //递归调用的结束条件	          
    else{	
        InOrder(root->lchild);    //中序递归遍历root的左子树
        cout<<root->data<<" ";    //访问根结点的数据域
        InOrder(root->rchild);    //中序递归遍历root的右子树
	}
}

//---------------------FJJ ADD---------------------------
template<class T>           
void BiTree<T>::fdg_InOrder(BiNode<T> *root)  
{
   	const int MaxSize = 100;
	struct StackElement
	{  BiNode<T>*ptr;
	   int flag;      //输出标记，0 不输出，1 输出
	};

	StackElement S[MaxSize]; // 采用顺序栈
    StackElement q;
	int top=-1;
	if (root!=NULL)
	{	top++;
    	S[top].ptr=root;
		S[top].flag=0;
	}

	while(top!=-1)
	{	
		q=S[top--];  //出栈
		if (q.flag==1) //左子树已遍历，输出当前子树的根节点
		{   cout<<q.ptr->data<<" "; }
		
		else // 左子树未遍历，把右子树，根，左子树依次压栈
		{
			if (q.ptr->rchild != NULL) { top++; S[top].ptr=q.ptr->rchild;S[top].flag=0;  }
			
			top++;	S[top]=q; S[top].flag=1 ; // 当前出栈节点再次压栈，修改输出标记，下次出压栈时立即输出

	        if (q.ptr->lchild != NULL) { top++; S[top].ptr=q.ptr->lchild;S[top].flag=0;  }

		}
	}

}
/*
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：后序遍历二叉树
 *输    出：二叉树中结点的一个线性排列
 *后置条件：二叉树不变 
 */
template <class T>
void BiTree<T>::PostOrder(BiNode<T> *root)
{ 
    if (root==NULL)   return;       //递归调用的结束条件
    else{	
        PostOrder(root->lchild);    //后序递归遍历root的左子树
        PostOrder(root->rchild);    //后序递归遍历root的右子树
        cout<<root->data<<" ";      //访问根结点的数据域
	}
}

//---------------------FJJ ADD---------------------------
template<class T>           
void BiTree<T>::fdg_PostOrder(BiNode<T> *root)  
{
   	const int MaxSize = 100;
	struct StackElement
	{  BiNode<T>*ptr;
	   int flag;      //输出标记，0 不输出，1 输出
	};

	StackElement S[MaxSize]; // 采用顺序栈
    StackElement q;
	int top=-1;
	if (root!=NULL)
	{	top++;
    	S[top].ptr=root;
		S[top].flag=0;
	}

	while(top!=-1)
	{	
		q=S[top--];  //出栈
		if (q.flag==1) //左右子树已遍历，输出当前子树的根节点
		{   cout<<q.ptr->data<<" "; }
		
		else // 左子树未遍历，把 根、右子树、左子树依次压栈
		{
			top++;	S[top]=q; S[top].flag=1 ; // 当前出栈节点再次压栈，修改输出标记，下次出压栈时立即输出

			if (q.ptr->rchild != NULL) { top++; S[top].ptr=q.ptr->rchild;S[top].flag=0;  }

	        if (q.ptr->lchild != NULL) { top++; S[top].ptr=q.ptr->lchild;S[top].flag=0;  }

		}
	}

}
/*
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：层序遍历二叉树
 *输    出：二叉树中结点的一个线性排列
 *后置条件：二叉树不变
 */
template <class T>
void BiTree<T>::LeverOrder(BiNode<T> *root)
{
	const int MaxSize = 100;

	int front = 0;
	int rear = 0;  //采用顺序队列，并假定不会发生上溢

	BiNode<T>* Q[MaxSize];
    BiNode<T>* q;

	if (root==NULL) return;
	else{
		Q[rear++] = root;
		while (front != rear)
		{
			q = Q[front++];
     		cout<<q->data<<" "; 		
    		if (q->lchild != NULL)    Q[rear++] = q->lchild;		
			if (q->rchild != NULL)    Q[rear++] = q->rchild;
		}
	}
}

/*
 *前置条件：空二叉树
 *输    入：数据ch;
 *功    能：初始化一棵二叉树,构造函数调用
 *输    出：无
 *后置条件：产生一棵二叉树
 */
//-------------改进输入--------------------------------
template <class T>
BiNode<T>* BiTree<T>::Creat( )
{
	BiNode<T>* bt;
	T ch;

	static int i=0;
	ch=PreOrderString[i]; //PreOrderString 全局变量
	i++;

    if (ch=="#") bt = NULL;
    else{ 
	     bt = new BiNode<T>;       //生成一个结点
         bt->data=ch;
         bt->lchild = Creat( );    //递归建立左子树
         bt->rchild = Creat( );    //递归建立右子树
    } 
    return bt;
}

/*
 *前置条件：二叉树已经存在
 *输    入：无
 *功    能：释放二叉树的存储空间，析构函数调用
 *输    出：无
 *后置条件：二叉树不存在
 */
template<class T>
void BiTree<T>::Release(BiNode<T>* root)
{
  if (root != NULL){                  
	  Release(root->lchild);   //释放左子树
      Release(root->rchild);   //释放右子树
      delete root;
  }  
}
