package com.company;
import java.util.Scanner;
class Fraction
{
    int a,b;
    public Fraction(int n,int m){
        a=n;
        b=m;
    }
    public Fraction(){ }
    static int gys(int a,int b)
    {
        if(b==0)
            return a;
        return(gys(b,a%b));
    }
    public void print()
    {
        int c=gys(a,b);
        a=a/c;
        b=b/c;
        if(b==1)
            System.out.println(a);
        else
            System.out.println(a+"/"+b);
    }
    public Fraction plus(Fraction another)
    {
        Fraction c=new Fraction();
        c.b=this.b*another.b;
        c.a=this.a*another.b+this.b*another.a;
        return c  ;
    }
    public Fraction multiply(Fraction another)
    {
        Fraction c=new Fraction();
        c.a=this.a*another.a;
        c.b=this.b*another.b;
        return c  ;
    }
    public double toDouble()
    {
        return (double)(a/b);
    }
}
public class string_pta_3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Fraction a = new Fraction(in.nextInt(), in.nextInt());
        Fraction b = new Fraction(in.nextInt(), in.nextInt());
        a.print();
        b.print();
        a.plus(b).print();
        a.multiply(b).plus(new Fraction(5, 6)).print();
        a.print();
        b.print();
        in.close();
    }
}
