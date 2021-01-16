//������BiTree������ṹBiNode,�ļ���Ϊbitree.h
#ifndef BITREE_H
#define BITREE_H

template <class T>
struct BiNode   //�������Ľ��ṹ
{
  T data;       
  BiNode<T> *lchild, *rchild;
};

template <class T>
class BiTree
{
public:
    BiTree( );             //���캯������ʼ��һ�ö���������ǰ�������ɼ�������
    ~BiTree(void);         //�����������ͷŶ��������и����Ĵ洢�ռ�
	BiNode<T>* Getroot();  //���ָ�������ָ��
    void PreOrder(BiNode<T> *root);     //ǰ�����������
    void InOrder(BiNode<T> *root);      //�������������
    void PostOrder(BiNode<T> *root);    //�������������
    void LeverOrder(BiNode<T> *root);   //�������������
	//---------FJJ ADD-----------
	void fdg_PreOrder(BiNode<T> *root);     //�ǵݹ�ǰ�����������
    void fdg_InOrder(BiNode<T> *root);      //�ǵݹ��������������
    void fdg_PostOrder(BiNode<T> *root);    //�ǵݹ�������������
private:
    BiNode<T> *root;         //ָ�������ͷָ��
    BiNode<T> *Creat( );     //�вι��캯������
    void Release(BiNode<T> *root);   //������������ 
};
#endif