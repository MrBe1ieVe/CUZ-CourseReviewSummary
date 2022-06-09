package com.company;
import java.util.Scanner;
public class Number_zoom1
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int size = 9;
        double sum = 0;
        double a = 0;
        double result = 0;
        double[] mylist = new double[size];
        for (int i=0;i<size;i++)
        {
            double A = input.nextDouble();
            mylist[i] = A;
            sum = sum + A;
        }
        double mean = sum/size;
        for (int j=0;j<size;j++)
        {
            a=a+Math.pow(mylist[j]-mean,2);
        }
        result = Math.sqrt(a/(size-1));
        System.out.print(String.format("%.4f",mean));
        System.out.print(" ");
        System.out.print(String.format("%.4f",result));
    }
}
