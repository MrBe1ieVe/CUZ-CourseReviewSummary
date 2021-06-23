#include<iostream>
#include<sstream>
using namespace std;
int main() 
{
string t0="255.255.255.192";
int x=0;
string t1,t2,t3,t4;
int i1,i2,i3,i4;
int z0=0,z1=0,z2=0,z3=0;
string::size_type pos;
pos= t0.find('.');t1.assign(t0,0,pos);t0.assign(t0,pos+1,t0.length()-pos);
pos= t0.find('.');t2.assign(t0,0,pos);t0.assign(t0,pos+1,t0.length()-pos);
pos= t0.find('.');t3.assign(t0,0,pos);t0.assign(t0,pos+1,t0.length()-pos);
pos= t0.find('.');t4.assign(t0,0,pos);t0.assign(t0,pos+1,t0.length()-pos);
stringstream ss1;ss1 << t1;ss1 >> i1;
stringstream ss2;ss2 << t2;ss2 >> i2;
stringstream ss3;ss3 << t3;ss3 >> i3;
stringstream ss4;ss4 << t4;ss4 >> i4;
int a3=(255-i4)+1;while(a3/=2)z3++;
int a2=(255-i3)+1;while(a2/=2)z2++;
int a1=(255-i2)+1;while(a1/=2)z1++;
int a0=(255-i1)+1;while(a0/=2)z0++;
if(i4==255){x=32;}
else if(i3==255){x=32-z3;}
else if(i2==255){x=24-z2;}
else if(i1==255){x=16-z1;}
else x=8-z0;
cout<<x<<endl;
}
