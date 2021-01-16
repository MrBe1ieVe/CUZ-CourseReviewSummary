//LinkListMain.cpp
#include <iostream.h>  //��������������⺯����ͷ�ļ�
#include "LinkList.cpp"  //���õ��������

void SetInterestSort(LinkList <char> &a, LinkList <char> &b,LinkList <char> &r);
void SetInterest(LinkList <char> &a, LinkList <char> &b,LinkList <char> &r);
void SetAdd(LinkList <char> &a, LinkList <char> &b,LinkList <char> &r);
void SetSub(LinkList <char> &a, LinkList <char> &b,LinkList <char> &r);
int SubSetIs(LinkList <char> &a, LinkList <char> &b); // a �� b���Ӽ���

void Reverse(LinkList <char> &a, LinkList <char> &r); // ������a�����Ƶ�r, �ٶ�����r ��ת


void main( )
{

  int n;

  char A[100];

//-----------------------------------------------
cout<<"�ַ���-����a�Ĳ�����:(1) n,   (2) a1~an"<<endl;
cout<<"�����룺 n=";
cin>>n;
cout<<endl;

cout<<"��������������Ԫ��a0~an��"<<endl;
for (int i=0; i<n; i++)
	{
	 cout<<"   a["<<i<<"]=";
     cin>>A[i];
     //cout<<endl;
	}

LinkList <char> a(A,n);
 cout<<"����a ��Ԫ��Ϊ:"<<endl;
 a.PrintList();            //�������������Ԫ��
//-----------------------------------------------
cout<<"�ַ���-����b�Ĳ�����:(1) n,   (2) b1~bn"<<endl;
cout<<"�����룺 n=";
cin>>n;
cout<<endl;

cout<<"��������������Ԫ��b0~bn��"<<endl;
for ( i=0; i<n; i++)
	{
	 cout<<"   b["<<i<<"]=";
     cin>>A[i];
     //cout<<endl;
	}

LinkList <char> b(A,n);
 cout<<"����b ��Ԫ��Ϊ:"<<endl;
 b.PrintList();            //�������������Ԫ��
//-----------------------------------------------------------

LinkList <char> c;

//--------------------------------------------------------
 cout<<"����a,b �Ľ���Ϊ:"<<endl;
SetInterest(a , b , c);
c.PrintList();


	/*cout<<"����a+b Ϊ:"<<endl;
	c.Empty();
	SetAdd(a , b , c);
	c.PrintList();



	cout<<"����a-b Ϊ:"<<endl;
	c.Empty();
	SetSub(a , b , c);
	c.PrintList();




	cout<<"����a��b ���Ӽ���"<<endl;
	if (SubSetIs(a,b)<1)
	   cout<<"No"<<endl;
	else
	   cout<<"Yes"<<endl;



	cout<<"������ת���ԣ�"<<endl;
	c.Empty();
	Reverse( a,  c);
	cout<<"������ת��"<<endl;
	c.PrintList();

	  */

}

//-------------------------------

//---------------------------------------

void SetInterestSort(LinkList <char> &a, LinkList <char> &b,LinkList <char> &r)
{    // Ҫ�󼯺�a,b���������е�
     Node<char>*p,*q;
	 p=(a.first)->next; q=(b.first)->next; 
     while (p && q)
     {
        if (p->data<q->data)   p=p->next;
        else if (p->data>q->data) q=q->next;
        else { 

				 r.Insert(1,p->data);
                 p=p->next;
                 q=q->next;
             }
     }
  }

void SetInterest(LinkList <char> &a, LinkList <char> &b,LinkList <char> &r)
{    // ����a,b�����������
     Node<char> *p;
	 p=(a.first)->next; 
     
     while (p)
	 {
         
		 if (b.Locate(p->data)!=0)
            r.Insert(1,p->data);
		 p=p->next;

	 } 
  }


void SetAdd(LinkList <char> &a, LinkList <char> &b,LinkList <char> &r)
  {  
    
	 
  }

void SetSub(LinkList <char> &a, LinkList <char> &b,LinkList <char> &r)
  {  
     
	 
  }


int SubSetIs(LinkList <char> &a, LinkList <char> &b) // a �� b���Ӽ��� 1:yes, 0:no
{
   
	
  return 1;
}


void Reverse(LinkList <char> &a, LinkList <char> &r) // ������a�����Ƶ�r, �ٶ�����r ��ת
{
     Node<char> *p;
	 //----------------------------------------------
	 p=(a.first)->next; 	
     while (p)
     {
        r.Insert(1,p->data);
		p=p->next;
	 }

     r.PrintList();
     //---------------���´���������ת r ------------------------------
     
      //ѧ���ڴ˼�����д����

	 
     
}