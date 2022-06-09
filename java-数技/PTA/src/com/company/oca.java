import java.util.ArrayList;
import java.util.Scanner;

public class oca
{

    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);

        Teacher t = new Teacher();

        while(true)
        {
            String name = scan.next();
            if( name.compareTo("end") == 0 )
            {
                break;
            }
            else if(name.compareTo("print") == 0)
            {
                t.printStudents();
            }
            else if(name.compareTo("sort") == 0)
            {
                t.sortAverage();
            }
            else if(name.compareTo("assist") == 0)
            {
                t.assistStudents();
            }
            else
            {
                Student s = new Student( name );

                String info = scan.nextLine();
                String message[] = info.split(" ");
                for(int i = 1; i < message.length; i+=2)
                {
                    String courseName = message[i];
                    String courseScore = message[i+1];

                    s.addCourse(courseName, Integer.parseInt(courseScore) );
                }

                t.addStudent(s);

            }

        }


    }

}


class Teacher
{

    ArrayList<Student> sList=new ArrayList<Student>();
    public void printStudents()
    {
        System.out.println("\nAll students:");
        for(int i=0;i<sList.size();i++)
        {
            sList.get(i).countmean();
        }
        for(int i=0;i<sList.size();i++)
        {
            if(sList.get(i).cList.size()==0)
            {
                System.out.printf("%s: 0",sList.get(i).name);
            }
            else
            {
                System.out.printf("%s: %d,",sList.get(i).name,sList.get(i).mean);
                sList.get(i).cList.forEach((a)->{System.out.printf(" %s %d",a.courseName,a.courseScore);});
            }
            System.out.printf("\n");

        }

    }

    public void sortAverage()
    {
        for(int i=0;i<sList.size();i++)
        {
            sList.get(i).countmean();
        }
        for(int i=0;i<sList.size();i++)
        {
            for(int j=0;j<sList.size()-i-1;j++)
            {
                if(sList.get(j).mean!=sList.get(j+1).mean)
                {
                    if(sList.get(j).mean<sList.get(j+1).mean)
                    {
                        Student temp=null;
                        temp=sList.get(j);
                        sList.set(j,sList.get(j+1));
                        sList.set(j+1,temp);
                    }
                }
                else if(sList.get(j).name.charAt(0)>sList.get(j+1).name.charAt(0))
                {
                    Student temp=null;
                    temp=sList.get(j);
                    sList.set(j,sList.get(j+1));
                    sList.set(j+1,temp);
                }
            }
        }

    }

    public void assistStudents()
    {
        for(Student s:sList)
        {

            for(Course c:s.cList )
            {
                if(c.courseScore<60)
                {
                    s.sum-=c.courseScore;
                    c.courseScore=c.courseScore+Integer.parseInt(String.format("%.0f",((float)c.courseScore*0.1)));
                    s.sum+=c.courseScore;
                }
            }
        }
    }

    public void addStudent(Student s)
    {
        sList.add(s);
    }
}

class Student extends Teacher
{
    String name;
    int sum;
    int mean;
    ArrayList<Course> cList=new ArrayList<Course>();
    public Student(String _name)
    {
        this.name=_name;
        this.sum=0;
        this.mean=0;
    }
    public Student(){}
    public void addCourse(String cname,int cscore)
    {
        Course c=new Course(cname,cscore);
        cList.add(c);
        sum+=cscore;
    }
    public void countmean()
    {
        if(this.cList.size()!=0)
        {
            this.mean=Integer.parseInt(String.format("%.0f",((float)sum/cList.size())));
        }
        else
            this.mean=0;
    }

}

class Course extends Student
{
    String courseName;
    int courseScore;
    public Course(String _courseName,int _courseScore)
    {
        courseName=_courseName;
        courseScore=_courseScore;
    }
}