/* Write a program to create class employee(eid,ename,department,salry)
[1]Input 5 employee data using constructor as well as print it using constructor
[2]Implement searching employee records based on employee name */
#include<iostream.h>
#include<conio.h>
#include<string.h>
class employee
{
	private:
	   int eid;
	   char ename[10];
	   char department[15];
	   float salary;
	public:
	   //Constructor
	   employee(int id,char name[10],char dept[15],float sal)
	   {
		eid=id;
		strcpy(ename,name);
		strcpy(department,dept);
		salary=sal;
	   }
	   // To display employee data
	void display()
	{
		cout<<"Employee id:"<<eid<<endl;
		cout<<"Employee name:"<<ename<<endl;
		cout<<"Employee department:"<<department<<endl;
		cout<<"Employee salary:"<<salary<<endl;
	}
	//To get name of employee
	const char* getname()
	{
		return ename;
	}
};
int main()
{
	//To store 5 employee objects using Array
	clrscr();
	employee employees[5]={
		employee(1,"Roshani","IT",55000),
		employee(2,"Bhumika","MArketing",65000),
		employee(3,"Anjli","HR",70000),
		employee(4,"Roy","Sales",50000),
		employee(5,"Joy","Finance",60000)
	};
	//To display all records of employee
	int j;
	cout<<"Employee Records:"<<endl;
	for(j=0;j<5;j++)
	{
		cout<<"\n Employee"<<j+1<<":"<<endl;
		employees[j].display();
	}
	//Searching an employee by name
	char searchname[20];
	int i;
	cout<<"\n Enter the name of the employee to search:";
	cin>>searchname;
	bool found="false";
	for(i=0;i<5;i++)
	{
		if(strcmp(employees[i].getname(),searchname)==0)
		{
			cout<<"\n Employee found : "<<endl;
			employees[i].display();
			found="true";
			break;
		}
	}
	if(!found)
	{
		cout<<"\n Employee not found ! "<<endl;
	}
	getch();
	return 0;
}
