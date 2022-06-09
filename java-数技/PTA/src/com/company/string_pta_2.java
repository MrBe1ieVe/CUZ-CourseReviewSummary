package com.company;
class Date{
    int _year;
    int _month;
    int _day;

    public Date(){};
    public Date(int year,int month,int day)
    {
        this._year=year;
        this._month=month;
        this._day=day;

    }
    public Date(int day)
    {
        this(0,0,day);
    }
    public Date(int month,int day)
    {
        this(0,month,day);
    }

    public Date(Date d)
    {
        this._year=d._year;
        this._month=d._month;
        this._day=d._day;
    }
    public void print()
    {
        System.out.println(this._year+"/"+this._month+"/"+this._day);
    }
}
public class string_pta_2
{

    public static void main(String[] args)
    {
        Date  d1       = new Date();
        Date  d2  = new Date(2014, 4, 1);

        Date d3     = new Date(10);
        Date d4     = new Date(4, 10);
        Date d5     = new Date(d2);

        d1.print();
        d2.print();
        d3.print();
        d4.print();
        d5.print();

    }

}


/* 请在这里填写答案 */
