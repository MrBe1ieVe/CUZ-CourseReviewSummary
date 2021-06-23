#include <iostream>
#include <string>
using namespace std;
class stu
{
public:
	int xh;
	string xm;
	stu(string m="no name",int h=0){xh=h;xm=m;};
	void display(int x){cout<<xm<<" "<<x<<endl;}; 
	stu(stu &p){xh=p.xh;xm=p.xm;};
	~stu(){};
};
class CC
{	
public:
	
	//使用stu类 
stu S;
string na;
int n;
CC(string m="B104",int h=0){na=m;n=h;};
void display(){cout<<"教室="<<na<<" "<<"学生人数="<<n<<endl;for(int i=1;i<=n;i++)S.display(i);};
	
	//拷贝构造函数  若无 系统会自带 
CC(CC &p){S=p.S;na=p.na;n=p.n;};
	//析构函数 		若无 系统会自带  
~CC(){};	
};

//虚基类
class B:virtual public CC      //此处采用虚继承
{public:int j;};
class C:virtual public CC     //此处采用虚继承
{public:int k;};
class D:public B,public CC
{public:int m;};

int main()

{

         CC c1("A01",5);

    CC c2;
         c1.display();
         c2.display();

 

         return 0;

}
