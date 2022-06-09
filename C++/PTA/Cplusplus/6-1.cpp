#include <iostream>
#include <string>
using namespace std;

class Teacher{
protected:
    string name;
    int age;
    char sex; 
    string address;
    string number;  
    string title;
public:
    Teacher( string n,int a,char s,string t,string ad,string num);  
    void display();

};
Teacher::Teacher( string n,int a,char s,string t,string ad,string num):name(n),age(a),sex(s),title(t),address(ad),number(num){}  
void Teacher::display(){
        cout<<"name:"<<name<<endl;  
        cout<<"age:"<<age<<endl;
        cout<<"sex:"<<sex<<endl;
        cout<<"title:"<<title<<endl;
        cout<<"address:"<<address<<endl;
        cout<<"tel:"<<number<<endl;
}
class Cadre{  
protected:
    string name;
    int age;
    char sex;  
    string address;
    string number;  
    string post;

public:
 
    Cadre(string p);  

};
Cadre::Cadre(string p):post(p){} 

class Teacher_Cadre:public Teacher,public Cadre
{
protected:
    float wages;
public:
  Teacher_Cadre (string n,int a,char s,string t,string ad,string num,string p,float w);  
  void show();
};
Teacher_Cadre::Teacher_Cadre (string n,int a,char s,string t,string ad,string num,string p,float w):Teacher(n,a,s,t,ad,num),Cadre(p),wages(w){} 
 
void Teacher_Cadre::show(){
        Teacher::display();
        cout<<"post:"<<Cadre::post<<endl;  
        cout<<"wages:"<<wages<<endl;
}


int main(){ 
    string name;
    int age;
    char sex;
    string address;
    string number;
    string title;
    string post;
    float wages;
    cin>>name;
    cin>>age;
    cin>>sex;
    cin>>title; 
    cin>>post;
    cin.ignore();
    getline(cin,address);
    cin>>number;
    cin>>wages;
    Teacher_Cadre obj(name,age,sex,title,address,number,post,wages);
    obj.show();
    return 0;
}