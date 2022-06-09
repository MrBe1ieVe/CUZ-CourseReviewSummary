package com.company;
import java.util.Scanner;
public class Main
{
    public static void main(String[] args)
    {
        int A;
        Scanner input = new Scanner(System.in);
        A = input.nextInt();
        int j=0;
        int k=0;
            for (j=1;j<=A;j++)
            {
                for (k=1;k<=j;k++)
                {
                    int m= j*k;
                    System.out.print(k+"*"+j+"="+m);
                    if (k!=j) {
                        System.out.print(" ");
                    }
                    }
                System.out.println("");
            }
        }

}
