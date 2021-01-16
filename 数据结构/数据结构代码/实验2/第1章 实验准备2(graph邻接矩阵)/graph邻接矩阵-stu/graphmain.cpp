#include <iostream>
#include <string>                   //引入标准库中的头文件
#include "graph.cpp"                //引用graph.cpp文件
using namespace std;

int main(int argc, char* argv[])
{
	int i;
   	int choose=1;                      //控制
    int which;                         //功能选择变量	
	string name;                    	//插入顶点的值	
   
	string vname[4]={"V0","V1","V2","V3"};  //初始化各顶点
    int pos1;                           //顶点
	int pos2;                           //顶点
	int m;                                                   
	MGraph<string> g(vname,4,0);        //调用Graph程序
   while ( choose==1 )                  //控制
   {   cout <<"++++++++++++++++++++++++++++++"<<endl;
	  cout << "需要输出顶点信息请按0" << "\n";		   //输入所要进行的操作的序号
	  cout << "需要输出任意一个顶点信息请按1" << "\n";
      cout << "需要边的信息输出请按2" << "\n";
      cout << "需要删除请按3" << "\n";
      cout << "需要插入请按4" << "\n";	  
	  cout << "需要删除某条边请按5" << "\n";
	  cout << "需要插入某条边请按6" << "\n";
	  cout << "需要退出请按10" << "\n";
	  cout <<"++++++++++++++++++++++++++++++"<<endl;
      cin >> which;
      switch( which )                  //功能选择
	  {
         
	   case 0:                   //输出图的各顶点的值
		     g.PutVex();                                
			
		    break;      
	   
	   case 1:                   //输出图的任意顶点的值
		  try
		  {
			 int i;
			 cout<<"请输入顶点："<<"\n";
		     cin>>i;
			 g.GetVex(i,vname);				              
                        
		  }
		  catch(char*)
		  {
			 cout<<"输出不正确！"<<endl;
		  }
			
		    break;
	  
	   case 2:                       //输出图中的边	     
		     cout<<"所有的边的信息为:"<<"\n";
		  try
		  {
				g.putarc(0,1,13);   
	            g.putarc(1,2,15);
	            g.putarc(0,3,12);           
		  }
		  catch(char*)
		  {
			  cout<<"输出不正确！"<<endl;
		  }            
		    break;                          

       case 3:                        //删除hh顶点
  	       int hh ;
		   cout<<"请输入要删除的顶点"<<"\n";
	       cin>>hh;
	       try
		   {
			  g.DeleteVex(hh);                 
		   }
		   catch(char*)
		   {
		      cout<<"删除失败！"<<endl;
		   }
			break;

       case 4:                        //在nn位置插入值为name的顶点
	      int nn ;
		  cout<<"请输入要插入的顶点位置及名称"<<"\n";
	      cin>>nn>>name;			   
	      try
		  {
			  g.InsertVex(nn,name); 
		  }
		  catch(char*)
		  {
			  cout<<"插入失败！"<<endl;
		  }
			break;

       case 5:                      //删除两顶点之间的路径         
	      cout<<"请输入两顶点："<<"\n";
		  cin>>pos1>>pos2;
		  try
		  {
			 g.DeleteArc(pos1,pos2); 
		  }
		  catch(char*)
		  {
		     cout<<"插入失败！"<<endl;
		  }
          
	        break;

       case 6:                   //插入一条边         
	      cout<<"请输入两顶点："<<"\n";
		  cin>>pos1>>pos2;
		  cout<<"请输入路径："<<"\n";
		  cin>>m;
		  try
		  {
			 g.InsertArc(pos1,pos2,m);
		  }
		  catch(char*)
		  {
			 cout<<"插入失败！"<<endl;
		  }
          
	        break;

      
			
       case 10:              //退出
              choose=0;
            break;         
  }
 }		  
return 0;
 }
 