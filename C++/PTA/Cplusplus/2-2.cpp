#include <iostream>
using namespace std;
class Box
{
    public:
        void get_value();
        double volume();
        void display();
    private:
        double length;
        double width;
        double height;
};
void Box::get_value()
{
    cin>>length>>width>>height;
}

double Box::volume()
{
    return (length*width*height);
}

void Box::display()
{
    cout<<volume()<<endl;
}

int main()
{
    Box box1,box2,box3;
    box1.get_value();
    box1.volume();
    cout<<"volmue of box1 is ";
    box1.display();
    box2.get_value();
    box2.volume();
    cout<<"volmue of box2 is ";
    box2.display();
    box3.get_value();
    box3.volume();
    cout<<"volmue of box3 is ";
    box3.display();
 return 0;
}