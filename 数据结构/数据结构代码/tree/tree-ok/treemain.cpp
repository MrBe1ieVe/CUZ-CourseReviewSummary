//�й�����ʵ�ֵ����������ļ���Ϊtreemain.cpp
#include <iostream>
#include <string>
#include"tree.cpp"
using namespace std;

void main() 
{
    Tree<string> t; //����һ����
     /*
       ����Խ̲�P107 ͼ5-10 �ɰ����·�ʽ���롾P134 ͼ5-9 �����桿��
	   A
	   A B
	   C E   //�����������
	   
	   B D
	   B E
	   B F

       C G   //�����������
	   
	   A C
	   C G
	   C H
	   E I
      */

	TNode<string>* p = t.Getroot( );  //��ȡָ�������ָ�� 
	cout<<"------ǰ�����------ "<<endl;
	t.PreOrder(p);
	cout<<endl;
	cout<<"------�������------ "<<endl;
	t.PostOrder(p);
	cout<<endl;
	cout<<"------�������------ "<<endl;
	t.LeverOrder(p);
	cout<<endl;
}