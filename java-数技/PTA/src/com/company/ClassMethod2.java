package com.company;
import java.util.ArrayList;
import java.util.Scanner;
class Student
{
    int id;
    int scores;
    public Student(){}
    public Student(int id)
    {
        this.id = id;
    }
    public Student()
}
class Course
{

}
class Date
{
    int year = 2021;
    int month = 11;
    int day = 1;
    public Date(int year,int month,int day)
    {
        this.year = year;
        this.month = month;
        this.day = day;
    }
}
//
public class ClassMethod2
{

    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        Student ss[] = new Student[n];
        for(int i = 0; i < ss.length; i++)
        {
            ss[i] = new Student( scan.nextInt(), scan.next() );
            for(int j = 0; j < 3; j++)
            {
                ss[i].vCourses.add( new Course( scan.next(), scan.nextInt()) );
            }
        }


        for(int i = 0; i < ss.length; i++)
        {
            for(int j = i + 1; j < ss.length; j++)
            {
                if( ss[i].getMeanScore() < ss[j].getMeanScore() )
                {
                    Student s = ss[i];
                    ss[i] = ss[j];
                    ss[j] = s;
                }
            }
        }

        //
        for(int i = 0; i < ss.length; i++)
        {
            ss[i].print();
        }

    }


}

