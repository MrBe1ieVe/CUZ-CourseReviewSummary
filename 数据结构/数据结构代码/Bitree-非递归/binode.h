#ifndef BINODE_H
#define BINODE_H
/*
template<class T> //Ϊ��BiNode�����Ա�������
class BiTree;

template<class T>
class BiNode
{
	T data;
	BiNode<T>* lchild;
	BiNode<T>* rchild;
public:
	BiNode(T ch){data=ch;lchild=NULL;rchild=NULL;} //�вι��캯��
	~BiNode(){}                                    //��������
	void insert_value(const T& val)
	{
		if(val==data)
		{
			//root=NULL;
			return;
		}
	    if(val<data)
		{
			if(!lchild)
			{
				lchild=new BiNode<T>(val);
			}
			else
			{
				lchild->insert_value(val);
			}
		}
		else
		{
			if(!rchild)
			{
				rchild=new BiNode<T>(val);
			}
			else
			{
				rchild->insert_value(val);
			}
		}
		
	}
	friend class BiTree<T>;                        //��BiTree����Ϊ��Ԫ��   
};
*/
#endif