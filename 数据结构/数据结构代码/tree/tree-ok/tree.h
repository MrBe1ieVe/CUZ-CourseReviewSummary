//�������е����Լ����ṹ���ļ���Ϊtree.h
#ifndef TREE_H
#define TREE_H

template <class T>//���н����ú����ֵܱ�ʾ��
struct TNode
{
  T data;
  TNode<T> *firstchild, *rightsib;
};

template <class T>
class Tree
{
public:
    Tree( );               //���캯������ʼ��һ��������ǰ�������ɼ�������
    ~Tree(void);           //�����������ͷ����и����Ĵ洢�ռ�
	TNode<T>* Getroot( );  //���ָ�������ָ��
    void PreOrder(TNode<T> *root);     //ǰ�������
    void PostOrder(TNode<T> *root);    //���������
    void LeverOrder(TNode<T> *root);   //���������
private:
    TNode<T> *root;         //ָ�������ͷָ��
    void Release(TNode<T> *root);   //������������ 
};

  #endif