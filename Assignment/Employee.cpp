#include <iostream.h>
#include <conio.h>
#include <string.h>

class Employee
{
	private:
	int eid;
	char ename[20];
	char department[20];
	float salary;

	public:
	Employee(int id,char name[20],char dept[20],float sal)
	{
		eid = id;
		strcpy(ename,name);
		strcpy(department,dept);
		salary=sal;
	}

	void display()
	{
		cout<<"Employee id: " <<eid<<endl;
		cout<<"Employee name: " <<ename<<endl;
		cout<<"Employee designation: " <<department<<endl;
		cout<<"Employee salary: " <<salary<<endl;
	}

	const char* getname()
	{
		return ename;
	}
};

int main()
{
    clrscr();
    int i,t=0,id,n;
    char searchname[20],empname[20],dept[20];
    float esalary;

    cout<<"Enter number of employees: ";
    cin>>n;

    Employee** emp=new Employee*[n];

    for(i=0;i<5;i++)
    {
	cout<<"Enter employee id: ";
	cin>>id;
	cout<<"Enter employee name: ";
	cin>>empname;
	cout<<"Enter employee department: ";
	cin>>dept;
	cout<<"Enter employee salary: ";
	cin>>esalary;

	emp[i]=new Employee(id,empname,dept,esalary);
    }

    // Display employee details
    for(i=0;i<5;i++)
    {
	cout<<"Employee: " <<i+1<< endl;
	emp[i]->display();
    }

    // Search for an employee by name
    cout<<"Employee name to be searched: ";
    cin>>searchname;

    for(i=0;i<5;i++)
    {
	if(strcmp(emp[i]->getname(),searchname) == 0)
	{
	    cout<<"\tEmployee found: " <<endl;
	    emp[i]->display();
	    t++;
	}
    }

    if(t==0)
    {
	cout<<"Employee not found." <<endl;
    }

    // Clean up allocated memory
    for(i=0;i<5;i++)
    {
	delete emp[i];
    }
    delete[] emp;

    getch();
    return 0;
}
