#include <iostream>
using namespace std;
class Student
{
public:
    Student(int n=0, float s=0): num(n), score(s){}
    void input();
    void display();
private:
    int num;
    float score;
};
void Student::input()
{
    cin>>num>>score;
}
void Student::display()
{
    cout<<num<<' '<<score<<endl;
}
int main()
{
     Student stud[5];
     for(int i=0;i<5;i++)
         stud[i].input();
     Student *p=stud;
     for(int i=0;i<=2;p=p+2,i++)
         p->display();
     return 0;
 }