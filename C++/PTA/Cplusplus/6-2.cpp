#include <iostream>
#include <string>
using namespace std;
class Teacher
{
 public:
  Teacher(int n,string na,string s):num(n),name(na),sex(s){};
  void display(){
   cout<<"num:"<<num<<endl;
   cout<<"name:"<<name<<endl;
   cout<<"sex:"<<sex<<endl;  
  }
 protected:
  int num;
  string name;
  string sex;
 }; 
 class BirthDate
 {
  public:
   BirthDate(int y,int m,int d):year(y),month(m),day(d){ };
   void show(){
    cout<<"birthday:"<<month<<"/"<<day<<"/"<<year<<endl; 
   }
   void show1(int y,int m,int d){
    year=y;
    month=m;
    day=d;
   }
 protected: 
 int year;
 int month;
 int day;
  
 };
 class Professor:public Teacher
 {
  public:
  BirthDate birthday;
  float area;
   Professor(int n,string na,string s,int m,int d,int y,float a):Teacher(n,na,s),birthday(y,m,d){area=a; }
   void fun(){
    Teacher::display();
     birthday.show();
     cout<<"area:"<<area<<endl; 
   }
   void change(int y,int m,int d){
    Teacher::display();
    birthday.show1(y,m,d);
    birthday.show(); 
    cout<<"area:"<<area<<endl; 
   }
  } ;
  int main(){
   int n,y,m,d,y1,m1,d1;
   string na,s;
   float ar;
   cin>>n>>na>>s>>y>>m>>d>>ar;
   cin>>m1>>d1>>y1;
   Professor p1(n,na,s,m,d,y,ar);
   cout<<"original data:"<<endl;
   p1.fun();
   cout<<"new data:"<<endl;
   p1.change(m1,d1,y1);
   return 0; 
   
  }