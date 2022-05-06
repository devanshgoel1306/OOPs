//C++ allows more than one constructors to be defined in a single class.
//Defining more than one constructor in a single class provided they differ
//in either type or number of argument is called constructor overloading.

#include<iostream>
#include<string.h>
using namespace std;

class Student
{
private:
    //data members
    int rollno;
    char name[20];
    float marks;

public:
    //default constructor
    Student()
    {
        //assigning default values
        rollno= 0;
        marks= 0.0;
        strcpy(name, "");
    }

    //parametrized constructor
    Student(int roll, char* nam, float mar)
    {
        rollno= roll;
        strcpy(name,nam);
        marks= mar;
    }

    //parametrized constructor
    Student(int roll, char nam[20])
    {
        rollno= roll;
        strcpy(name,nam);
        marks= 90;
    }

    //copy constructor
    Student(Student& s)
    {
        rollno= s.rollno;
        strcpy(name,s.name);
        marks= s.marks;
    }

    void display()
    {
        cout<<"Name: "<<name<<"\nRoll No.: "<<rollno<<"\nMarks: "<<marks<<"\n";
    }
};

int main()
{
    Student s1;
    s1.display();

    Student s2(191333,"Devansh",80);
    s2.display();

    Student s3(191334,"Gavesh");
    s3.display();

    Student s4(s3);
    s4.display();

    return 0;
}
