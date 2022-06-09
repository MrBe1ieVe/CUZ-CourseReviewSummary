package com.company;
import java.util.Scanner;
public class Number_zoom3
{
    public static void main(String[] args)
    {
        float[][] number_list = new float[9][18];
        Scanner input = new Scanner(System.in);
        float[][] ave = new float[9][9];
        float[][] last = new float[9][9];
        int[] m = {4,2,0,6,3,9,8,1,5};
        int[] n = {10,12,15,16,14,13,17,7,11};
        for (int i=0;i<9;i++)
        {
            for (int j=0;j<18;j++)
            {
                float a = input.nextFloat();
                number_list[i][j] = a;
            }
        }
        for (int i=0;i<9;i++)
        {
            for (int j=0;j<9;j++)
            {
                ave[j][i] = (number_list[j][m[i]]+number_list[j][n[i]])/2;
            }
        }
        for (int i=0;i<9;i++)
        {
            for (int j=0;j<i+1;j++)
            {
                last[i][j] = (ave[i][j]+ave[j][i])/2;
                System.out.print(String.format("%.4f",last[i][j]));
                if (j!=i)
                {
                    System.out.print(" ");
                }
            }
            System.out.println("");
        }
    }
}
