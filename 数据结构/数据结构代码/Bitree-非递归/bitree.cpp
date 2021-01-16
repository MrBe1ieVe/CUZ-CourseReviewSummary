//�������еĳ�Ա�������ļ���Ϊbitree.cpp
#include<iostream>
#include<string>
#include"bitree.h"
using namespace std;

/*
 *ǰ��������������������
 *��    �룺��
 *��    �ܣ�����һ�ö�����
 *��    ������
 *��������������һ�ö����� 
 */
template<class T>
BiTree<T>::BiTree( )
{
	this->root = Creat( );
}
/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ��ͷŶ��������и����Ĵ洢�ռ�
 *��    ������
 *���������������������� 
 */
template<class T>
BiTree<T>::~BiTree(void)
{
	Release(root);
}
/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ���ȡָ�������������ָ��
 *��    ����ָ�������������ָ��
 *�������������������� 
 */
template<class T>
BiNode<T>* BiTree<T>::Getroot( )
{
	return root;
}
/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ�ǰ�����������
 *��    �����������н���һ����������
 *�������������������� 
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
	BiNode<T>* S[MaxSize]; // ����˳��ջ
    BiNode<T>* q;
	int top=-1;
	if (root!=NULL)
    	S[++top]=root;
	while(top!=-1)
	{
        q=S[top--];  //��ջ
        cout<<q->data<<" "; 
		if(q->rchild != NULL) S[++top]=q->rchild;  //ע�����Һ���ѹջ˳��
        if(q->lchild != NULL) S[++top]=q->lchild;
	}

}
//------------------------------------------------
/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ��������������
 *��    �����������н���һ����������
 *�������������������� 
 */
template <class T>
void BiTree<T>::InOrder (BiNode<T> *root)
{
    if (root==NULL)  return;      //�ݹ���õĽ�������	          
    else{	
        InOrder(root->lchild);    //����ݹ����root��������
        cout<<root->data<<" ";    //���ʸ�����������
        InOrder(root->rchild);    //����ݹ����root��������
	}
}

//---------------------FJJ ADD---------------------------
template<class T>           
void BiTree<T>::fdg_InOrder(BiNode<T> *root)  
{
   	const int MaxSize = 100;
	struct StackElement
	{  BiNode<T>*ptr;
	   int flag;      //�����ǣ�0 �������1 ���
	};

	StackElement S[MaxSize]; // ����˳��ջ
    StackElement q;
	int top=-1;
	if (root!=NULL)
	{	top++;
    	S[top].ptr=root;
		S[top].flag=0;
	}

	while(top!=-1)
	{	
		q=S[top--];  //��ջ
		if (q.flag==1) //�������ѱ����������ǰ�����ĸ��ڵ�
		{   cout<<q.ptr->data<<" "; }
		
		else // ������δ������������������������������ѹջ
		{
			if (q.ptr->rchild != NULL) { top++; S[top].ptr=q.ptr->rchild;S[top].flag=0;  }
			
			top++;	S[top]=q; S[top].flag=1 ; // ��ǰ��ջ�ڵ��ٴ�ѹջ���޸������ǣ��´γ�ѹջʱ�������

	        if (q.ptr->lchild != NULL) { top++; S[top].ptr=q.ptr->lchild;S[top].flag=0;  }

		}
	}

}
/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ��������������
 *��    �����������н���һ����������
 *�������������������� 
 */
template <class T>
void BiTree<T>::PostOrder(BiNode<T> *root)
{ 
    if (root==NULL)   return;       //�ݹ���õĽ�������
    else{	
        PostOrder(root->lchild);    //����ݹ����root��������
        PostOrder(root->rchild);    //����ݹ����root��������
        cout<<root->data<<" ";      //���ʸ�����������
	}
}

//---------------------FJJ ADD---------------------------
template<class T>           
void BiTree<T>::fdg_PostOrder(BiNode<T> *root)  
{
   	const int MaxSize = 100;
	struct StackElement
	{  BiNode<T>*ptr;
	   int flag;      //�����ǣ�0 �������1 ���
	};

	StackElement S[MaxSize]; // ����˳��ջ
    StackElement q;
	int top=-1;
	if (root!=NULL)
	{	top++;
    	S[top].ptr=root;
		S[top].flag=0;
	}

	while(top!=-1)
	{	
		q=S[top--];  //��ջ
		if (q.flag==1) //���������ѱ����������ǰ�����ĸ��ڵ�
		{   cout<<q.ptr->data<<" "; }
		
		else // ������δ�������� ����������������������ѹջ
		{
			top++;	S[top]=q; S[top].flag=1 ; // ��ǰ��ջ�ڵ��ٴ�ѹջ���޸������ǣ��´γ�ѹջʱ�������

			if (q.ptr->rchild != NULL) { top++; S[top].ptr=q.ptr->rchild;S[top].flag=0;  }

	        if (q.ptr->lchild != NULL) { top++; S[top].ptr=q.ptr->lchild;S[top].flag=0;  }

		}
	}

}
/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ��������������
 *��    �����������н���һ����������
 *��������������������
 */
template <class T>
void BiTree<T>::LeverOrder(BiNode<T> *root)
{
	const int MaxSize = 100;

	int front = 0;
	int rear = 0;  //����˳����У����ٶ����ᷢ������

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
 *ǰ���������ն�����
 *��    �룺����ch;
 *��    �ܣ���ʼ��һ�ö�����,���캯������
 *��    ������
 *��������������һ�ö�����
 */
//-------------�Ľ�����--------------------------------
template <class T>
BiNode<T>* BiTree<T>::Creat( )
{
	BiNode<T>* bt;
	T ch;

	static int i=0;
	ch=PreOrderString[i]; //PreOrderString ȫ�ֱ���
	i++;

    if (ch=="#") bt = NULL;
    else{ 
	     bt = new BiNode<T>;       //����һ�����
         bt->data=ch;
         bt->lchild = Creat( );    //�ݹ齨��������
         bt->rchild = Creat( );    //�ݹ齨��������
    } 
    return bt;
}

/*
 *ǰ���������������Ѿ�����
 *��    �룺��
 *��    �ܣ��ͷŶ������Ĵ洢�ռ䣬������������
 *��    ������
 *����������������������
 */
template<class T>
void BiTree<T>::Release(BiNode<T>* root)
{
  if (root != NULL){                  
	  Release(root->lchild);   //�ͷ�������
      Release(root->rchild);   //�ͷ�������
      delete root;
  }  
}
