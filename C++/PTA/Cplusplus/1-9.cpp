#include <iostream>
using namespace std;
void sort2(int &a,int &b)
{
    int temp=0;
    if (a<b) {temp=a;a=b;b=temp;}
}
int main(){
  int a,b;
  cin>>a>>b;
  sort2(a,b);
  cout<<a<<endl<<b<<endl;
  return 0;
}