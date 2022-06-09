package com.company;
import java.util.Scanner;
public class ss {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        for (int i=1;i<=n;i++)
        {
            for (int j=n;j>i;j--)
            {
                System.out.print(" ");
            }
            for (int k=1;k<=i;k++)
            {
                if (k<=n) {
                    System.out.print(k);
                }
                }
            for (int m=i;m>1;m--)
            {
                System.out.print(m-1);
            }
            if (i!=n) {
                System.out.println("");
            }
            }
        System.out.println("");
        for (int i=2*n-1;i>n;i--)
        {
            for (int j=2*n-1;j>=i;j--)
            {
                System.out.print(" ");
            }
            for (int k=n+1;k<=i;k++)
            {
                System.out.print(k-n);
            }
            for (int m=n+2;m<=i;m++)
            {
                System.out.print(i-m+1);
            }
        System.out.println();
        }
    }
}