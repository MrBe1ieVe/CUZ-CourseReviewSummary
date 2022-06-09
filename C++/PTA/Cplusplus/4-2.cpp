#include <iostream>
using namespace std;
class stu
{
    public:
        stu(string name, int number);
        stu();
        void display();
    private:
        string na;
        int num;
};
stu::stu(string name, int number):na(name),num(number){}
stu::stu(){na = "no name";num = 0;}
void stu::display()
{
    cout<<na<<" "<<num<<endl;
}
int main()
{
    stu s[50];
    stu s2("x",1);
    for(int i=0;i<5;i++)
        s[i].display();
    stu s1(s2);
    s2.display();
    s1.display();
    return 0;
}