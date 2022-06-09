package com.company;
import java.util.Scanner;

class Ball
{
    private double x;
    private double y;
    private double radius;
    public Ball(double x,double y,double radius)
    {
        this.x=x;
        this.y=y;
        this.radius=radius;
    }
    double dis()
    {
        double dist=Math.sqrt(this.x*this.x+this.y*this.y);
        return dist;
    }
    double square()
    {
        double squr=this.radius*this.radius*Math.PI;
        return squr;
    }

    void print()
    {
        System.out.printf("(%.1f,%.1f,%.1f) %.1f, %.1f\n",this.x,this.y,this.radius,this.dis(),this.square());
    }
}
public class ClassMethod {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        Ball[] balls = new Ball[n];
        for (int i = 0; i < n; i++) {
            double a, b, c;
            a = s.nextDouble();
            b = s.nextDouble();
            c = s.nextDouble();
            balls[i] = new Ball(a, b, c);
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (balls[j].dis() != balls[j + 1].dis()) {
                    if (balls[j].dis() > balls[j + 1].dis()) {
                        Ball b1 = null;
                        b1 = balls[j];
                        balls[j] = balls[j + 1];
                        balls[j + 1] = b1;
                    }
                } else if (balls[j].square() > balls[j + 1].square()) {
                    Ball b2 = null;
                    b2 = balls[j];
                    balls[j] = balls[j + 1];
                    balls[j + 1] = b2;
                }
            }
        }


        for (int i = 0; i < balls.length; i++) {
            balls[i].print();
        }

    }
}



