#include <iostream>
#include <string>                   //�����׼���е�ͷ�ļ�
#include "graph.cpp"                //����graph.cpp�ļ�
using namespace std;

int main(int argc, char* argv[])
{
	int i;
   	int choose=1;                      //����
    int which;                         //����ѡ�����	
	string name;                    	//���붥���ֵ	
   
	string vname[4]={"V0","V1","V2","V3"};  //��ʼ��������
    int pos1;                           //����
	int pos2;                           //����
	int m;                                                   
	MGraph<string> g(vname,4,0);        //����Graph����
   while ( choose==1 )                  //����
   {   cout <<"++++++++++++++++++++++++++++++"<<endl;
	  cout << "��Ҫ���������Ϣ�밴0" << "\n";		   //������Ҫ���еĲ��������
	  cout << "��Ҫ�������һ��������Ϣ�밴1" << "\n";
      cout << "��Ҫ�ߵ���Ϣ����밴2" << "\n";
      cout << "��Ҫɾ���밴3" << "\n";
      cout << "��Ҫ�����밴4" << "\n";	  
	  cout << "��Ҫɾ��ĳ�����밴5" << "\n";
	  cout << "��Ҫ����ĳ�����밴6" << "\n";
	  cout << "��Ҫ�˳��밴10" << "\n";
	  cout <<"++++++++++++++++++++++++++++++"<<endl;
      cin >> which;
      switch( which )                  //����ѡ��
	  {
         
	   case 0:                   //���ͼ�ĸ������ֵ
		     g.PutVex();                                
			
		    break;      
	   
	   case 1:                   //���ͼ�����ⶥ���ֵ
		  try
		  {
			 int i;
			 cout<<"�����붥�㣺"<<"\n";
		     cin>>i;
			 g.GetVex(i,vname);				              
                        
		  }
		  catch(char*)
		  {
			 cout<<"�������ȷ��"<<endl;
		  }
			
		    break;
	  
	   case 2:                       //���ͼ�еı�	     
		     cout<<"���еıߵ���ϢΪ:"<<"\n";
		  try
		  {
				g.putarc(0,1,13);   
	            g.putarc(1,2,15);
	            g.putarc(0,3,12);           
		  }
		  catch(char*)
		  {
			  cout<<"�������ȷ��"<<endl;
		  }            
		    break;                          

       case 3:                        //ɾ��hh����
  	       int hh ;
		   cout<<"������Ҫɾ���Ķ���"<<"\n";
	       cin>>hh;
	       try
		   {
			  g.DeleteVex(hh);                 
		   }
		   catch(char*)
		   {
		      cout<<"ɾ��ʧ�ܣ�"<<endl;
		   }
			break;

       case 4:                        //��nnλ�ò���ֵΪname�Ķ���
	      int nn ;
		  cout<<"������Ҫ����Ķ���λ�ü�����"<<"\n";
	      cin>>nn>>name;			   
	      try
		  {
			  g.InsertVex(nn,name); 
		  }
		  catch(char*)
		  {
			  cout<<"����ʧ�ܣ�"<<endl;
		  }
			break;

       case 5:                      //ɾ��������֮���·��         
	      cout<<"�����������㣺"<<"\n";
		  cin>>pos1>>pos2;
		  try
		  {
			 g.DeleteArc(pos1,pos2); 
		  }
		  catch(char*)
		  {
		     cout<<"����ʧ�ܣ�"<<endl;
		  }
          
	        break;

       case 6:                   //����һ����         
	      cout<<"�����������㣺"<<"\n";
		  cin>>pos1>>pos2;
		  cout<<"������·����"<<"\n";
		  cin>>m;
		  try
		  {
			 g.InsertArc(pos1,pos2,m);
		  }
		  catch(char*)
		  {
			 cout<<"����ʧ�ܣ�"<<endl;
		  }
          
	        break;

      
			
       case 10:              //�˳�
              choose=0;
            break;         
  }
 }		  
return 0;
 }
 