//SeQListMain.cpp
#include <iostream.h>       //��������������⺯����ͷ�ļ�
#include "SeqList.cpp"      //����˳�����SeqList

void main( )
{
  
  SeqList<int>a;         //����һ���յ�˳���
  cout<<"ִ�в������:"<<endl;
  try
  {
  a.Insert(1,1);
  a.Insert(2,3);
  a.Insert(3,4);
  }
  catch(char* wrong)
  {
   cout << wrong;     //��ʧ����ʾʧ����Ϣ
  }
  cout<<"�Ѿ����롰1��3��4��"<<endl;
  cout<<endl;
  cout<<"˳���a�ĳ���Ϊ:";
  cout<<a.Length()<<endl;         //���ص�������
  cout<<endl;
  cout<<"��λ��ѯ�ڶ���Ԫ��:"<<endl;
  cout<<"�ڶ���Ԫ��Ϊ:";
  cout <<a.Get(2)<<endl;          //����˳����еڶ���Ԫ��
  cout<<endl;
  cout<<"��ֵ��ѯ3:"<<endl;
  cout<<"ֵΪ3��Ԫ��λ��Ϊ:";
  cout<<a.Locate(3)<<endl;        //����Ԫ��3���������ڵ�������λ��
  cout<<endl;
  try
  {
   if(a.Length()){
	  cout<<"ִ��ɾ����һ��Ԫ�ز���:"<<endl;
	  cout<<endl;
	  a.Delete(1);                //ɾ��Ԫ��1
      cout<<"��ɾ���ɹ���˳���a�ĳ���Ϊ:";    
      cout<<a.Length()<<endl;
   }

   else{
	  cout<<"˳���a����Ϊ0"<<endl;
   }
  }
  catch(char* wrong)
  {
   cout << wrong;     //��ʧ����ʾʧ����Ϣ
  }
  cout<<endl;
  cout<<"˳���a�е�Ԫ����:"<<endl;
  a.PrintList();              //�������Ԫ��
  
  int r[]={1,2,3,4,5};
  SeqList <int> b(r,5);     //�������鴴��˳���
  cout<<"ִ�в������ǰ˳���bΪ:"<<endl;
  b.PrintList();            //���˳�������Ԫ��
  cout<<"����ǰ˳���b�ĳ���Ϊ:";    
  cout<<b.Length()<<endl;
  try
  {
   b.Insert(3,8);
  }
  catch(char* wrong)
  {
   cout << wrong;     //��ʧ����ʾʧ����Ϣ
  }
  cout<<"ִ�в��������˳���bΪ:"<<endl;
  b.PrintList();            //���˳���b����Ԫ��
  cout<<"�����˳���b�ĳ���Ϊ:";    
  cout<<b.Length()<<endl;
  cout<<endl;
  try
  {
   if(a.Length()){
	  cout<<"ִ��ɾ����һ��Ԫ�ز���:"<<endl;
	  cout<<endl;
	  b.Delete(1);                //ɾ��b�е�һ��Ԫ��
      cout<<"��ɾ���ɹ���˳���b�ĳ���Ϊ:";    
      cout<<b.Length()<<endl;
   }

   else{
	  cout<<"˳���b����Ϊ0"<<endl;
   }
  }
  catch(char* wrong)
  {
   cout << wrong;     //��ʧ����ʾʧ����Ϣ
  }
  cout<<"ִ�в��������˳���bΪ:"<<endl;
  b.PrintList();            //���˳�������Ԫ��

  //===========================================================
  int rr[]={11,2,33,104,15};
  SeqList <int> c(rr,5); 
  // ѧ��������¹���,����ʵ�����Ա����c�ṩ�ĳ�Ա�������ܣ�
   //(1) �ڵ�����33ǰ���� -10��(2) ������Ա�����ֵ����Сֵ


  //===========================================================


}