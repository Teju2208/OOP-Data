#include<fstream>
#include<iostream>
using namespace std;

class Employee
{
	char name[20];
	int ID;
	double salary;
	
	public:
		void accept()
		{
			cin>>name;
			cin>>ID;
			cin>>salary;
		}
		void display()
		{
			cout<<"\n Enter Name:"<<name<<endl;
			cout<<"\n Enter ID:"<<ID<<endl;
			cout<<"\n Enter salary:"<<salary<<endl;
		}				
};
int main()
{
	Employee o[5];
	fstream f;
	int i,n;
	f.open("b16.txt");
	cout<<"\n How many employee information do you need to store ";
	cin>>n;
	cout<<"\n Enter information of employee in this format(name/ID/salary)";
	for(i=0;i<n;i++)
	{
		cout<<"\n Enter information of :"<<i<<"\n Employee";
		o[i].accept();
		f.write((char*)&o[i],sizeof o[i]);
	}
	
	f.close();
	
	f.open("b16.txt",ios::in);
	cout<<"\n Information of employee is as follow:";
	for(i=0;i<n;i++)
	{
		f.write((char*)&o[i],sizeof o[i]);
		o[i].display();
		
	}
	f.close();
	
	return 0;
}
