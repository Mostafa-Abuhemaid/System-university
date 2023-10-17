#include <iostream>
#include<fstream>
#include<vector>
using namespace std;
class person
{
public:
    string name;
    int age ;
    int id;
    void  virtual role()=0;

};


class employee:public person
{
public :
    int salary;
    void role()
    {
        cout<<"a person who has agreed to be employed to work for some form of payment under a contract of employment."<<endl;
        cout<<"His salary is :"<<salary<<endl;
    }
    employee();
    employee(string n,int a,int d,int s)
    {
        name=n;
        age =a;
        id=d;
        salary=s;
    }

};


class student:public person
{
public:
    float GPA;
    void role();
    student();
    student(string name,int age,int id,float gpa);
};
void student::role()
{
    cout<<"A person enrolled in a school or other educational institution."<<endl;
}
student::student(string n,int a,int d,float gpa)
{
    name=n;
    age=a;
    id=d;
    GPA=gpa;
}
student::student() {}
class instructor:public person
{

public:
    void role()
    {
        cout<<"Instructor is the title for an individual responsible for teaching students in a particular subject area"<<endl;
    }
    instructor();
    instructor(string n,int a,int d)
    {
        name=n;
        age=a;
        id=d;
    }

};

class manager: public person
{
private:
    static manager* instance;
    int salary;
    manager() {}
public:
    static manager* getInstance()
    {
        if (instance == NULL)
        {
            instance = new manager();
        }
        return instance;
    }
    double getSalary()
    {
        return salary;
    }
    void setSalary(int n)
    {
        salary = n;
    }
    void role()
    {
        cout<<"A manager is a professional who takes a leadership role in an organisation and manages a team of employees."<<endl;
    }


};
manager*manager::instance = NULL;

class course
{
public:
    string title;
    int id;

    course();
    course(string s,int n)
    {
        title=s;
        id=n;
    }
    void details()
    {
        cout<<"the title is : "<<title<<"the id of course is : "<<id;
    }
};
class department
{
public:
    string title;
    vector<course>vdepartmenT;
    void addcourse()
    {
        string title;
        cout<<"enter the title of the course :"<<endl;
        cin>>title;
        int num;
        cout<<"enter the id of the course :"<<endl;
        cin>>num;
        course newcourse(title,num);
        vdepartmenT.push_back(newcourse);
        ofstream outFile("courses.txt", ios::app);
        outFile << "Course Name: " << title << "            "
                << "Coures ID: " << num << endl;
        outFile.close();
        cout << "Course Name added and data written to file." << endl;

    }
    department();
    department(string t)
    {
        title=t;
    }
    void details()
    {
        cout<<"the title is : "<<title<<endl;
    }

};
class faculty
{

public:
    string title ;
    vector<student>vstudent;
    vector<instructor>vinstuctor;
    vector<employee>vemployee;
    vector<department>vdepartment;
    faculty();

    faculty(string t);
    void addStudent();
    void  addInstructor();
    void  addEmployee();
    void  addDepartment();
};
faculty::faculty(string t)
{
    title=t;
}
faculty::faculty() {}
void  faculty::addStudent()
{

    string title;
    int id;
    int age;
    float gpa;
    cout << "Enter student name: ";
    cin >> title;
    cout << "Enter student ID: ";
    cin >> id;
    cout << "Enter student age: ";
    cin >> age;
    cout << "Enter student gpa: ";
    cin >> gpa;

    student newstuden(title, age,id,gpa);


    vstudent.push_back(newstuden);


    ofstream outFile("student.txt", ios::app);

    outFile << "student Name: " << title << "            "
            << "student ID: " << id << "student age: " << age << "            "
            << "student GPA: " << gpa << "            "<< endl;
    outFile.close();
    cout << "data written to file." << endl;


}
void  faculty::addInstructor()
{
    string title;
    int id;
    int age;

    cout << "Enter Instructor name: ";
    cin >> title;
    cout << "Enter Instructor ID: ";
    cin >> id;
    cout << "Enter Instructor age: ";
    cin >> age;


    instructor newinstructor(title, age,id);


    vinstuctor.push_back(newinstructor);


    ofstream outFile(" instructor.txt", ios::app);
    outFile << " instructor Name: " << title << "            "
            << " instructor ID: " << id << " instructor age: " << age << "            "<<endl;

    outFile.close();
    cout << "data written to file." << endl;

}
void  faculty::addEmployee()
{
    string title;
    int id;
    int age;
    int salary;
    cout << "Enter employee name: ";
    cin >> title;
    cout << "Enter employee ID: ";
    cin >> id;
    cout << "Enter employee age: ";
    cin >> age;
    cout << "Enter employee salary: ";
    cin >> salary;

    employee newemployee(title, age,id,salary);


    vemployee.push_back(newemployee);


    ofstream outFile("student.txt", ios::app);

    outFile << "employee Name: " << title << "            "
            << "employee ID: " << id << "student age: " << age << "            "
            << "employee salary: " << salary << "            "<< endl;
    outFile.close();
    cout << "data written to file." << endl;


}
void  faculty::addDepartment()
{
    string title;
    cout<<"enter department name : "<<endl;
    cin>>title;
    department newDepatment(title);
    vdepartment.push_back(title);

    ofstream outFile("department.txt", ios::app);
    outFile << "department Name: " << title<<endl;
    outFile.close();
    cout << "data written to file." << endl;
}

class university
{
public:
    string name ;

    vector<faculty>vfaculty;
    void addfaculty()
    {
        string name ;
        cout<<"enter the faculty name :"<<endl;
        cin>>name;
        faculty newFaculty(name);
        vfaculty.push_back(newFaculty);

        ofstream outFile("faculty.txt", ios::app);
        outFile << "faculty Name: " << name<<endl;
        outFile.close();
        cout << "data written to file." << endl;

    }


};
int main()
{
    cout<<"<------------- Welcome to our university system --------------->"<<endl<<endl;
    cout<<"if you want to add Faculty enter 1"<<endl<<endl;
    cout<<"if you want to add Course enter 2"<<endl<<endl;
    cout<<"if you want to add Instructor enter 3"<<endl<<endl;
    cout<<"if you want to add Employee enter 4"<<endl<<endl;
    cout<<"if you want to add Student enter 5"<<endl<<endl;
    int number;
    cin>>number;
    university v;
    faculty f;

    if(number==1)
    {
        v.addfaculty();
    }
     if(number==2)
    {
        f.addDepartment();
    }
     if(number==3)
    {
   f.addInstructor();
    }
     if(number==4)
    {
        f.addEmployee();

    }
     if(number==5)
    {
f.addStudent();
    }

    return 0;
}
