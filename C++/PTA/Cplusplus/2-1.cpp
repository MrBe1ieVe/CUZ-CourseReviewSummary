#include <iostream>
using namespace std;
class Time
{
    public:
        int hour,minute,sec;
        void set_time();
        void show_time();
};
Time t;
void set_time()
{
    int hour,minute,sec;
    cin>>hour>>minute>>sec;
    t.hour = hour;
    t.minute = minute;
    t.sec = sec;
}
void show_time()
{
    cout<<t.hour<<":"<<t.minute<<":"<<t.sec<<endl;
}
int main()
{
    set_time();
    show_time();
}
