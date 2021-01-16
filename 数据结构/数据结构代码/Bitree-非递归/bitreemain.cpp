//�����������������ļ���Ϊbitreemain.cpp
#include<iostream>
#include<string>
#include"bitree.cpp"
using namespace std;

//char PreOrderString[]="AB#D##C##";
char PreOrderString[]="ABD#G###CE##F##";

void main()
{	
         //��ǰ�򴴽�һ���� p119 5-26 (AB#D##C##) �� p116 5-25 (ABD#G###CE##F##)����2�桿
        //                  p144 5-24 (AB#D##C##) �� p141 5-20 (ABD#G###CE##F##)�������桿

	      
    BiTree<string> bt; //----�Ľ�--�Զ�����-----	
                         
	BiNode<string>* root = bt.Getroot( );  //��ȡָ�������ָ�� 

	cout<<"------ǰ�����------ "<<endl;
	bt.PreOrder(root);
    cout<<endl;
    cout<<"------�ǵݹ�ǰ�����------ "<<endl;
	bt.fdg_PreOrder(root);
	cout<<endl<<endl;


	cout<<"------�������------ "<<endl;
	bt.InOrder(root);
	cout<<endl;
	cout<<"------�ǵݹ��������------ "<<endl;
	bt.fdg_InOrder(root);
	cout<<endl<<endl;


	cout<<"------�������------ "<<endl;
	bt.PostOrder(root);
	cout<<endl;
    cout<<"------�ǵݹ�������------ "<<endl;
	bt.fdg_PostOrder(root);
	cout<<endl<<endl;

	cout<<"------�������------ "<<endl;
	bt.LeverOrder(root);
	cout<<endl;
}