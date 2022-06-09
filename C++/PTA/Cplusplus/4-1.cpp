#include <iostream>
using namespace std;
class complex
{
    public:
        complex(int real, int image);
        complex();
        void display();
    private:
        int re;
        int im;    
};
complex::complex(int real, int image):re(real),im(image) {}
complex::complex(){re=0;im=0;}
void complex::display()
{
    cout<<"("<<re<<","<<im<<")"<<endl;
}
int main()
{
         complex A;
         complex B(2,3);
         complex C(B);
         A.display();
         B.display();
         C.display();
         return 0;
}