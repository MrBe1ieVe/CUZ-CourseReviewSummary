package com.company;
import java.util.ArrayList;
import java.util.Scanner;

class Student {
    int id;
    String name;
    int score;
    public void addScore(int n)
    {
        score = score + n;
        if (score >= 100)
        {
            score = 100;
        }
        else
        {
            score = score;
        }
    }
    public void print()
    {
        System.out.println(id+" "+name+" "+score);
    }

}
public class string_pta_1 {


    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();

        ArrayList<Student> al = new ArrayList<Student>();
        //
        for (int i = 0; i < n; i++) {
            Student s = new Student();
            s.id = scan.nextInt();
            s.name = scan.next();
            s.score = scan.nextInt();

            al.add(s);
        }

        //
        for (int i = 0; i < al.size(); i++) {
            Student s = al.get(i);
            s.addScore(10);
        }

        //
        for (int i = 0; i < al.size(); i++) {
            Student s = al.get(i);

            s.print();
        }

    }

}