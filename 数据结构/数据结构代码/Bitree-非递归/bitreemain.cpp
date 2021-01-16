//二叉树的主函数，文件名为bitreemain.cpp
#include<iostream>
#include<string>
#include"bitree.cpp"
using namespace std;

//char PreOrderString[]="AB#D##C##";
char PreOrderString[]="ABD#G###CE##F##";

void main()
{	
         //按前序创建一棵树 p119 5-26 (AB#D##C##) 或 p116 5-25 (ABD#G###CE##F##)【第2版】
        //                  p144 5-24 (AB#D##C##) 或 p141 5-20 (ABD#G###CE##F##)【第三版】

	      
    BiTree<string> bt; //----改进--自动输入-----	
                         
	BiNode<string>* root = bt.Getroot( );  //获取指向根结点的指针 

	cout<<"------前序遍历------ "<<endl;
	bt.PreOrder(root);
    cout<<endl;
    cout<<"------非递归前序遍历------ "<<endl;
	bt.fdg_PreOrder(root);
	cout<<endl<<endl;


	cout<<"------中序遍历------ "<<endl;
	bt.InOrder(root);
	cout<<endl;
	cout<<"------非递归中序遍历------ "<<endl;
	bt.fdg_InOrder(root);
	cout<<endl<<endl;


	cout<<"------后序遍历------ "<<endl;
	bt.PostOrder(root);
	cout<<endl;
    cout<<"------非递归后序遍历------ "<<endl;
	bt.fdg_PostOrder(root);
	cout<<endl<<endl;

	cout<<"------层序遍历------ "<<endl;
	bt.LeverOrder(root);
	cout<<endl;
}