#include <iostream>
using namespace std;
void sort(int x,int y, int z) 
{
    int temp=0;
    if (x>y) {temp=x;x=y;y=temp;}
    if (z<x) cout<<z<<","<<x<<","<<y<<endl;
        else if (z<y) cout<<x<<","<<z<<","<<y<<endl;
            else cout<<x<<","<<y<<","<<z<<endl;
}
int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    void sort(int x,int y,int z);
    sort(x,y,z);
    return 0;
}