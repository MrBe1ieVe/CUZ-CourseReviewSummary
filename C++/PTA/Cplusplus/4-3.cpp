#include <iostream>
using namespace std;
class stu{
    private:
    int id=0;
    string name="no name";
    public :
    stu(){}
    stu(string _name,int _id)
    {
        name=_name;
        id=_id;
    }
    ~stu(){}
    stu(const stu&s)
    {
        name=s.name;
        id=s.id;
    }
    void display()
    {
        cout<<name<<" "<<id<<endl;
    }
};

class  CC{
    private :
    string className="B104";
    int num=0;
    stu s[100];
    public :
    CC(){};
    CC(string _className,int _num){
        className=_className;
        num=_num;
        stu s[num];
    }
    CC(const CC&c)
    {
        className=c.className;
        num=c.num;
    }
    ~CC(){}
    void display()
    {   
        cout<<"教师="<<className<<" 学生人数="<<num<<endl;
        for(int i=0;i<num;i++)
        {   
            stu ss("no name",i+1);
            s[i]=ss;
            
            s[i].display();
        }
    }
};


int main()

{

         CC c1("A01",5);

    CC c2;

         c1.display();

         c2.display();

 

         return 0;

}