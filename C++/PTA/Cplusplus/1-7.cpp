#include <iostream>
using namespace std;
int add(int a,int b)
{
    int z;
    z=a+b;
    return (z);
}
int main()
{
    int a,b;
    int c;
    cin>>a>>b;
    c=add(a,b);
    cout<<"a+b="<<c<<endl;
    return 0;
}
