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
	
	//ʹ��stu�� 
stu S;
string na;
int n;
CC(string m="B104",int h=0){na=m;n=h;};
void display(){cout<<"����="<<na<<" "<<"ѧ������="<<n<<endl;for(int i=1;i<=n;i++)S.display(i);};
	
	//�������캯��  ���� ϵͳ���Դ� 
CC(CC &p){S=p.S;na=p.na;n=p.n;};
	//�������� 		���� ϵͳ���Դ�  
~CC(){};	
};

//�����
class B:virtual public CC      //�˴�������̳�
{public:int j;};
class C:virtual public CC     //�˴�������̳�
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
