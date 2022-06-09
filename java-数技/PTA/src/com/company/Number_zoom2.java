package com.company;
import java.util.Scanner;
public class Number_zoom2
{
     public static void main(String[] args)
     {
         Scanner input = new Scanner(System.in);
         int n = input.nextInt();
         int[] number_list = new int[n+1];
         for (int i=0;i<n;i++)
         {
             int a = input.nextInt();
             number_list[i]=a;
         }
         for (int j=0;j<n;j++)
         {
             for (int k=1;k<n-j;k++)
             {
                 if(number_list[k-1] > number_list[k]) {
                     int temp;
                     temp = number_list[k - 1];
                     number_list[k - 1] = number_list[k];
                     number_list[k] = temp;
                 }
             }
         }
         for (int m=0;m<n;m++)
         {
             System.out.print(number_list[m]);
             if (m!=n-1)
             {
                 System.out.print(" ");
             }
         }
     }
}
