#include <iostream>
#include <string>
using namespace std;
class CPerson
{
public:
	string m_szName;
	CPerson(string m="no name"){m_szName=m;};
	void printName(){cout<<m_szName<<endl;}; 
	~CPerson(){};
};
//CStudent继承CPerson的m_szName与printName()并且加入了新的变量n与printInfo()
class CStudent : public CPerson
{	
public:
long int n;
CStudent(long int h=0){n=h;};
void printInfo(){cout<<m_szName<<n<<endl;};	
~CStudent(){};	
};
int main()

{

CPerson c1("xiaoming");

CStudent c2(190807728);

c1.printName();
c2.printName();
c2.printInfo();
 

         return 0;

}
