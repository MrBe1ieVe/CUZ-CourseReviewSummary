//�������еĳ�Ա�������ļ���Ϊtree.cpp
#include<iostream>
#include<string>
#include"tree.h"
using namespace std;
/*
 *ǰ����������������
 *��    �룺��
 *��    �ܣ�����һ����
 *��    ������
 *��������������һ���� 
 */

template<class T>
Tree<T>::Tree( )
{
	const int MaxSize = 100;
    int end = 0;
	int front = 0;
	int frontTemp=0;
	int rear  = 0;  //����˳����У����ٶ����ᷢ������
	int j = 0;	
	TNode<T>* queue[MaxSize]; //����һ������ 
	TNode<T>* tempNode;              //����ָ�������͵�ָ��  
	TNode<T>* brotherNode;   //����ָ��
    TNode<T>* q;
	T ch;
    cout<<"�����봴��һ�����ĸ��������"<<endl;
	cin>>ch;
    root = new TNode<T>;
	root->data = ch;
	root->firstchild = NULL;
	root->rightsib = NULL;
    queue[rear++] = root;  
    while (!end)    //������������
	{ 
		T ch1,ch2;
		cout<<"�����븸������ݺͺ��ӽ�����ݶ�:"<<endl;
		cin>>ch1>>ch2;
	
		//tempNode = queue[front];//ͷ�����ӣ�ͬʱ��ͷԪ�صı�ʶ������ 
		frontTemp=front; //fjj add
		tempNode = queue[frontTemp++];//fjj add ,ȡ��ͷ��㣬���ǳ���
		while((ch1 != tempNode->data) && (frontTemp<rear) ) 		
		{	//tempNode = queue[front++];
		    tempNode = queue[frontTemp++]; //fjj add
		}
        
		if (ch1 != tempNode->data) // ɨ����У�û�ҵ����׽ڵ�
		{
            cout<<"��ǰ����������Ϊ"<<ch1<<"�ĸ��׽ڵ㡣��������ڵ�ԣ���"<<endl;
			continue;
		}

        TNode<T>* p = new TNode<T>;       //����һ�����
		p->data = ch2;
		p->firstchild = NULL;    
		p->rightsib = NULL; 
        queue[rear++] = p;


        //---------���´��뽨�����ӹ�ϵ------------------
		if(tempNode->firstchild == NULL)
			tempNode->firstchild = p;
		else{
			brotherNode = tempNode->firstchild;  //����ָ��ָ����ĵ�һ������
			while (brotherNode != NULL)          //����һ���������ֵܽ�㣬ѭ���������һ���ֵܽڵ���
			{
				q = brotherNode;
				brotherNode = brotherNode->rightsib;//����ָ��ָ����һ�����ֵ�
			}            
			q->rightsib=p;
		}
      

		cout<<"��������? ��������밴1�����밴0 "<<endl;
		cin>>end;
	}
}
/*
 *ǰ�����������Ѵ���
 *��    �룺��
 *��    �ܣ��ͷ����и����Ĵ洢�ռ�
 *��    ������
 *������������������ 
 */
template<class T>
Tree<T>::~Tree(void)
{
	Release(root);
}
/*
 *ǰ�����������Ѵ���
 *��    �룺��
 *��    �ܣ���ȡָ����������ָ��
 *��    ����ָ����������ָ��
 *���������������� 
 */
template<class T>
TNode<T>* Tree<T>::Getroot( )
{
	return root;
}
/*
 *ǰ�����������Ѵ���
 *��    �룺��
 *��    �ܣ�ǰ�������
 *��    �������н���һ����������
 *���������������� 
 */
template<class T>
void Tree<T>::PreOrder(TNode<T> *root)      //ǰ�������
{
	if (root == NULL)  return;     //�ݹ���õĽ�������
	else{		
		cout<<root->data;          //��ӡ���ڵ�
		PreOrder(root->firstchild);    //ǰ��ݹ����root�ĵ�һ������
		PreOrder(root->rightsib);    //ǰ��ݹ����root�����ֵ�  
	}
}
/*
 *ǰ�����������Ѵ���
 *��    �룺��
 *��    �ܣ����������
 *��    �������н���һ����������
 *���������������� 
 */
template<class T>
void Tree<T>::PostOrder(TNode<T> *root)
{ 
	if (root == NULL)  return;     //�ݹ���õĽ�������
	else{		
		PostOrder(root->firstchild);    //����ݹ����root�ĵ�һ������
        cout<<root->data;               //��ӡ��root���
		PostOrder(root->rightsib);      //����ݹ����root�����ֵ�        
	}
} 
/*
 *ǰ�����������Ѵ���
 *��    �룺��
 *��    �ܣ����������
 *��    �������н���һ����������
 *����������������
 */
template<class T>
void Tree<T>::LeverOrder(TNode<T> *root)   
{		
	const int MAX_QUEUE_SIZE = 100;
	int front = 0;
	int rear  = 0;  //����˳����У����ٶ����ᷢ������		
	TNode<T>* queue[MAX_QUEUE_SIZE]; //����һ������ 
	TNode<T>* tempNode;      //����ָ�������͵�ָ��  
	TNode<T>* brotherNode;   //����ָ��

	if (root == NULL) return;//ѭ����������
	queue[rear++] = root;    //���������
	while (front != rear)    //���������н��
	{
		tempNode = queue[front++];//ͷ�����ӣ�ͬʱ��ͷԪ�صı�ʶ������
		cout<<tempNode->data;     //��ӡ��ͷ���    
		brotherNode = tempNode->firstchild;  //����ָ��ָ����ĵ�һ������
		while (brotherNode != NULL)          //����һ���������ֵܽ��
		{
			queue[rear++] = brotherNode;     //�ֵܽ�����
			brotherNode = brotherNode->rightsib;//����ָ��ָ����һ�����ֵ�
		}
	}
}
/*
 *ǰ�����������Ѿ�����
 *��    �룺��
 *��    �ܣ��ͷ����Ĵ洢�ռ䣬������������
 *��    ������
 *������������������
 */
template <class T>
void Tree<T>::Release(TNode<T>* root)
{
	if (root != NULL){ 	
		Release (root->firstchild);   //�ͷŵ�һ������
		Release (root->rightsib);   //�ͷ����ֵ�
        delete root;
	}
}
