//LinkStack.h
#ifndef LINKSTACK_H
#define LINKSTACK_H

template <class T>
struct Node
{
    T data;
    Node<T> *next;  //�˴�<T>Ҳ����ʡ��
};

template <class T>
class LinkStack
{
public:
    LinkStack( );              //���캯�����ÿ���ջ
    ~LinkStack( );             //�����������ͷ���ջ�и����Ĵ洢�ռ�
    void Push(T x);           //��Ԫ��x��ջ
    T Pop( );                  //��ջ��Ԫ�س�ջ
    T GetTop( );               //ȡջ��Ԫ�أ�����ɾ����
    bool Empty( );             //�ж���ջ�Ƿ�Ϊ��ջ
private:
    Node<T> *top;             //ջ��ָ�뼴��ջ��ͷָ��
};

#endif