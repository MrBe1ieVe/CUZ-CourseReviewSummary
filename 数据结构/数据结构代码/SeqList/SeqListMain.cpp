//SeQListMain.cpp
#include <iostream.h>       //引用输入输出流库函数的头文件
#include "SeqList.cpp"      //引用顺序表类SeqList

void main( )
{
  
  SeqList<int>a;         //创建一个空的顺序表
  cout<<"执行插入操作:"<<endl;
  try
  {
  a.Insert(1,1);
  a.Insert(2,3);
  a.Insert(3,4);
  }
  catch(char* wrong)
  {
   cout << wrong;     //如失败提示失败信息
  }
  cout<<"已经插入“1，3，4”"<<endl;
  cout<<endl;
  cout<<"顺序表a的长度为:";
  cout<<a.Length()<<endl;         //返回单链表长度
  cout<<endl;
  cout<<"按位查询第二个元素:"<<endl;
  cout<<"第二个元素为:";
  cout <<a.Get(2)<<endl;          //查找顺序表中第二个元素
  cout<<endl;
  cout<<"按值查询3:"<<endl;
  cout<<"值为3的元素位置为:";
  cout<<a.Locate(3)<<endl;        //查找元素3，并返回在单链表中位置
  cout<<endl;
  try
  {
   if(a.Length()){
	  cout<<"执行删除第一个元素操作:"<<endl;
	  cout<<endl;
	  a.Delete(1);                //删除元素1
      cout<<"已删除成功，顺序表a的长度为:";    
      cout<<a.Length()<<endl;
   }

   else{
	  cout<<"顺序表a长度为0"<<endl;
   }
  }
  catch(char* wrong)
  {
   cout << wrong;     //如失败提示失败信息
  }
  cout<<endl;
  cout<<"顺序表a中的元素有:"<<endl;
  a.PrintList();              //输出所有元素
  
  int r[]={1,2,3,4,5};
  SeqList <int> b(r,5);     //根据数组创建顺序表
  cout<<"执行插入操作前顺序表b为:"<<endl;
  b.PrintList();            //输出顺序表所有元素
  cout<<"插入前顺序表b的长度为:";    
  cout<<b.Length()<<endl;
  try
  {
   b.Insert(3,8);
  }
  catch(char* wrong)
  {
   cout << wrong;     //如失败提示失败信息
  }
  cout<<"执行插入操作后顺序表b为:"<<endl;
  b.PrintList();            //输出顺序表b所有元素
  cout<<"插入后顺序表b的长度为:";    
  cout<<b.Length()<<endl;
  cout<<endl;
  try
  {
   if(a.Length()){
	  cout<<"执行删除第一个元素操作:"<<endl;
	  cout<<endl;
	  b.Delete(1);                //删除b中第一个元素
      cout<<"已删除成功，顺序表b的长度为:";    
      cout<<b.Length()<<endl;
   }

   else{
	  cout<<"顺序表b长度为0"<<endl;
   }
  }
  catch(char* wrong)
  {
   cout << wrong;     //如失败提示失败信息
  }
  cout<<"执行插入操作后顺序表b为:"<<endl;
  b.PrintList();            //输出顺序表所有元素

  //===========================================================
  int rr[]={11,2,33,104,15};
  SeqList <int> c(rr,5); 
  // 学生完成以下功能,利用实例线性表对象c提供的成员函数功能，
   //(1) 在第三数33前插入 -10；(2) 输出线性表的最大值与最小值


  //===========================================================


}