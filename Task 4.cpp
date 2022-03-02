#include<iostream>
#include<fstream>
#include"Developer.h"
#include"Employees.h"
#include"Manager.h"
#include<string>
using namespace std;
void print(int total,int m_size,int d_size,Manager**ob,Developer**ob1)
{
	ofstream output;
	output.open("Data.txt");
	output << total <<"  "<<m_size<<"  "<<d_size<<"\n";
	for (int i = 0; i < m_size; i++)
	{
		output << ob[i][0].getEmployeeId() << "\t" << ob[i][0].getname() << "\t" << ob[i][0].getqualification() << "\t" << ob[i][0].getsalary() << "\t" << ob[i][0].gettype() << "\t" << ob[i][0].getrank() << "\t" << ob[i][0].getTotalGroupMembers() << "\t" << ob[i][0].getCompletedProjects() << "\t" << ob[i][0].getPendingProjects()<<"\n";
	}
	for (int i = 0; i < d_size; i++)
	{
		output << ob1[i][0].getEmployeeId() << "\t" << ob1[i][0].getname() << "\t" << ob1[i][0].getqualification() << "\t" << ob1[i][0].getsalary() << "\t" << ob1[i][0].gettype() << "\t" << ob1[i][0].getexperience() << "\t" << ob1[i][0].getype() << "\t" << ob1[i][0].getstatus() << "\n";
	}
	output.close();
}

int main()
{

	int TE = 0;//Total-Employees.
	int TM = 0;//Total-Manager.
	int TD = 0;//Total-Developer.
	int is = 0;
	char cs = ' ';
	string ss = {};
	ifstream input;
	input.open("Data.txt");
	if (!input)
	{
		cout << "File not Found." << endl;
	}
	else
	{
		input >> TE>>TM>>TD;
		
	}
	Employees::setTotalEmployees(TE);
	
	///////////Read Data From File/////////////

	Manager**Man = new Manager*[TM];
	for (int x = 0; x < TM; x++)
	{
		Man[x] = new Manager();
		input >> ss;
		Man[x][0].setEmployeeId(ss);
		input >> ss;
		Man[x][0].setname(ss);
		input >> ss;
		Man[x][0].setqualification(ss);
		input >> is;
		Man[x][0].setsalary(is);
		input >> ss;
		Man[x][0].settype(ss);
		input >> cs;
		Man[x][0].setrank(cs);
		input >> is;
		Man[x][0].setTotalGroupMembers(is);
		input >> is;
		Man[x][0].setCompletedProjects(is);
		input >> is;
		Man[x][0].setPendingProjects(is);
	}
	
	Developer**Dev = new Developer*[TD];
	for (int x = 0; x < TD; x++)
	{
		Dev[x] = new Developer();
		input >> ss;
		Dev[x][0].setEmployeeId(ss);
		input >> ss;
		Dev[x][0].setname(ss);
		input >> ss;
		Dev[x][0].setqualification(ss);
		input >> is;
		Dev[x][0].setsalary(is);
		input >> ss;
		Dev[x][0].settype(ss);
		input >> is;
		Dev[x][0].setexperience(is);
		input >> ss;
		Dev[x][0].setype(ss);
		input >> ss;
		Dev[x][0].setstatus(ss);
	}
	input.close();

	/////Main/////
	
	int select = 0;
	char tt =' ';
	while (select != 7)
	{
		cout << "Press 1 for Add Record." << endl;
		cout << "Press 2 for Delete Record." << endl;
		cout << "Press 3 for Update Record(Existing Employee)." << endl;
		cout << "Press 4 for Display the Total Number of Employee." << endl;
		cout << "Press 5 for Display Developer Data." << endl;
		cout << "Press 6 for Display Manager Name who Completed highest Projects." << endl;
		cout << "Press 7 for Exit." << endl;
		cin >> select;
		if (select == 1)/// Add
		{
			cout << "Press M for Manager." << endl;
			cout << "Press D for Developer." << endl;
			cin >> tt;
			if (tt == 'M' ||tt=='m')
			{
				Manager**temp = new Manager*[TM + 1];
				for (int x = 0; x < TM; x++)
				{
					temp[x] = new Manager();
					temp[x][0] = Man[x][0];
				}
				TM += 1;
				TE += 1;
				Employees::setTotalEmployees(TE);
				delete[]Man;
				Man = nullptr;
				Man = temp;

				Man[TM-1] = new Manager();
				string sss;
				char css;
				int iss;
				cout << "Enter Employees ID: " << endl;
				cin >> sss;
				Man[TM - 1][0].setEmployeeId(sss);
				cout << "Enter new name: " << endl;
				cin >> sss;
				Man[TM-1][0].setname(sss);
				cout << "New Qualification: " << endl;
				cin >> sss;
				Man[TM-1][0].setqualification(sss);
				cout << "New Salary: " << endl;
				cin >> iss;
				Man[TM-1][0].setsalary(iss);
				sss = "Manager";
				Man[TM-1 ][0].settype(sss);
				cout << "New Rank: " << endl;
				cin >> css;
				if (css == 'a' || css == 'b' || css == 'c')
				{
					css -= 32;
				}
				Man[TM-1 ][0].setrank(css);
				cout << "New Total-Group-Members: " << endl;
				cin >> iss;
				Man[TM-1 ][0].setTotalGroupMembers(iss);
				cout << "Completed-Projects: " << endl;
				cin >> iss;
				Man[TM -1][0].setCompletedProjects(iss);
				cout << "Pending Projects: " << endl;
				cin >> iss;
				Man[TM-1 ][0].setPendingProjects(iss);
				print(TE, TM, TD, Man, Dev);
		
			}
			else if (tt == 'D'||tt=='d')
			{
				Developer**temp = new Developer*[TD + 1];
				for (int x = 0; x < TD; x++)
				{
					temp[x] = new Developer();
					temp[x][0] = Dev[x][0];
				}
				TD += 1;
				TE += 1;
				Employees::setTotalEmployees(TE);
				delete[]Dev;
				Dev = nullptr;
				Dev = temp;

				Dev[TD - 1] = new Developer();
				string sss;
				char css;
				int iss;
				cout << "Enter Employees ID: " << endl;
				cin >> sss;
				Dev[TD - 1][0].setEmployeeId(sss);
				cout << "Enter new name: " << endl;
				cin >> sss;
				Dev[TD - 1][0].setname(sss);
				cout << "New Qualification: " << endl;
				cin >> sss;
				Dev[TD - 1][0].setqualification(sss);
				cout << "New Salary: " << endl;
				cin >> iss;
				Dev[TD - 1][0].setsalary(iss);
				sss = "Developer";
				Dev[TD - 1][0].settype(sss);
				cout << "Experince: " << endl;
				cin >> iss;
				Dev[TD - 1][0].setexperience(iss);
				cout << "New Work-Type: " << endl;
				cin >> sss;
				Dev[TD - 1][0].setype(sss);
				cout << "Status: " << endl;
				cin >> sss;
				Dev[TD - 1][0].setstatus(sss);
				print(TE, TM, TD, Man, Dev);
			}
			else
			{
				cout << "Invalid Input." << endl;
			}
		}
		else if (select == 2)//Delete
		{
			string check;
			cout << "Press M for Manager." << endl;
			cout << "Press D for Developer." << endl;
			cin >> tt;
			if (tt == 'M'|| tt=='m')
			{
				int y = 1;
				cout << "Employees ID: " << endl;
				cin >> check;
				for (int x = 0; x < TM; x++)
				{
					if (check == Man[x][0].getEmployeeId())
					{
						y = 0;
						break;
					}
				}
				if (y == 0)
				{
					for (int x = 0; x < TM; x++)
					{
						if (check == Man[x][0].getEmployeeId())
						{
							for (int y = x; y < TM-1; y++)
							{
								Man[x][0].setEmployeeId(Man[x + 1][0].getEmployeeId());
								Man[x][0].setname(Man[x + 1][0].getname());
								Man[x][0].setqualification(Man[x + 1][0].getqualification());
								Man[x][0].setsalary(Man[x + 1][0].getsalary());
								Man[x][0].settype(Man[x + 1][0].gettype());
								Man[x][0].setrank(Man[x + 1][0].getrank());
								Man[x][0].setTotalGroupMembers(Man[x + 1][0].getTotalGroupMembers());
								Man[x][0].setCompletedProjects(Man[x + 1][0].getCompletedProjects());
								Man[x][0].setPendingProjects(Man[x + 1][0].getPendingProjects());
							}
							///shrink////
							Manager**temp = new Manager*[TM - 1];
							for (int x = 0; x < TM - 1; x++)
							{
								temp[x] = new Manager();
								temp[x][0] = Man[x][0];
							}
							TM -= 1;
							TE -= 1;
							Employees::setTotalEmployees(TE);
							delete[]Man;
							Man = nullptr;
							Man = temp;
							print(TE, TM, TD, Man, Dev);
						}
					}
				}
				else
				{
					cout << "Invalid ID."<<endl;
				}
				
			}
			else if (tt == 'D' ||tt=='d')
			{
				int y = 1;
				cout << "Employees ID: " << endl;
				cin >> check;
				for (int x = 0; x < TD; x++)
				{
					if (check == Dev[x][0].getEmployeeId())
					{
						y = 0;
						break;
					}
				}
				if (y == 0)
				{
					for (int x = 0; x < TD; x++)
					{
						if (check == Dev[x][0].getEmployeeId())
						{
							for (int y = x; y < TD - 1; y++)
							{
								Dev[x][0].setEmployeeId(Dev[x + 1][0].getEmployeeId());
								Dev[x][0].setname(Dev[x + 1][0].getname());
								Dev[x][0].setqualification(Dev[x + 1][0].getqualification());
								Dev[x][0].setsalary(Dev[x + 1][0].getsalary());
								Dev[x][0].settype(Dev[x + 1][0].gettype());
								Dev[x][0].setexperience(Dev[x + 1][0].getexperience());
								Dev[x][0].setype(Dev[x + 1][0].getype());
								Dev[x][0].setstatus(Dev[x + 1][0].getstatus());
								
							}
							///shrink////
							Developer**temp = new Developer*[TD - 1];
							for (int x = 0; x < TD - 1; x++)
							{
								temp[x] = new Developer();
								temp[x][0] = Dev[x][0];
							}
							TD -= 1;
							TE -= 1;
							Employees::setTotalEmployees(TE);
							cout << TE;
							delete[]Dev;
							Dev = nullptr;
							Dev = temp;
							print(TE, TM, TD, Man, Dev);
						}
					}
				}
				else
				{
					cout << "Invalid ID." << endl;
				}

			}
			else
			{
				cout << "Invalid Input." << endl;
			}
		}
		else if (select == 3)//Update
		{
			string check;
			char tt=' ';
			
			cout << "Press M for Manager." << endl;
			cout << "Press D for Developer." << endl;
			cin >> tt;
			if (tt == 'M' || tt == 'm')
			{
				int y = 1;
				cout << "Employees ID: " << endl;
				cin >> check;
				for (int x = 0; x < TM; x++)
				{
					if (check == Man[x][0].getEmployeeId())
					{
						y = 0;
						break;
					}
				}
				if (y == 0)
				{
					for (int x = 0; x < TM; x++)
					{
						if (check == Man[x][0].getEmployeeId())
						{
							string sss;
							char css;
							int iss;
							cout << "Enter new name: " << endl;
							cin >> sss;
							Man[x][0].setname(sss);
							cout << "New Qualification: " << endl;
							cin >> sss;
							Man[x][0].setqualification(sss);
							cout << "New Salary: " << endl;
							cin >> iss;
							Man[x][0].setsalary(iss);
							sss = "Manager";
							Man[x][0].settype(sss);
							cout << "New Rank: " << endl;
							cin >> css;
							if (css == 'a' || css == 'b' || css == 'c')
							{
								css -= 32;
							}
							Man[x][0].setrank(css);
							cout << "New Total-Group-Members: " << endl;
							cin >> iss;
							Man[x][0].setTotalGroupMembers(iss);
							cout << "Completed-Projects: " << endl;
							cin >> iss;
							Man[x][0].setCompletedProjects(iss);
							cout << "Pending Projects: " << endl;
							cin >> iss;
							Man[x][0].setPendingProjects(iss);
							print(TE, TM, TD, Man, Dev);
						}
					}
				}
				else
				{
					cout << "Invalid ID." << endl;
				}
			}
			else if (tt == 'D' || tt == 'd')
			{
				int y = 1;
				cout << "Employees ID: " << endl;
				cin >> check;
				for (int x = 0; x < TD; x++)
				{
					if (check == Dev[x][0].getEmployeeId())
					{
						y = 0;
						break;
					}
				}

				if (y == 1)
				{

					for (int x = 0; x < TD; x++)
					{
						if (check == Dev[x][0].getEmployeeId())
						{
							int iss;
							string sss;
							cout << "Enter new name: " << endl;
							cin >> sss;
							Dev[x][0].setname(sss);
							cout << "New Qualification: " << endl;
							cin >> sss;
							Dev[x][0].setqualification(sss);
							cout << "New Salary: " << endl;
							cin >> iss;
							Dev[x][0].setsalary(iss);
							sss = "Developer";
							Dev[x][0].settype(sss);
							cout << "Experience: " << endl;
							cin >> iss;
							Dev[x][0].setexperience(iss);
							cout << "Type(Web,Game,Android): " << endl;
							cin >> sss;
							Dev[x][0].setype(sss);
							cout << "Status(Normal,Good,Excellent): " << endl;
							cin >> sss;
							Dev[x][0].setstatus(sss);
							print(TE, TM, TD, Man, Dev);
						}
					}
				}
				else
				{
					cout << "Invalid ID." << endl;
				}
			}
			
		}
		else if (select == 4)
		{
			cout << "Total-Number of Employees: " << Employees::getTotalEmployees()<<endl;
		}
		else if (select == 5)
		{
			int temp = 0;
			int* arr = new int[TD];
			for (int x = 0; x < TD; x++)
			{
				arr[x] = Dev[x][0].getexperience();
			}
			for (int i = 0; i < TD; ++i)   // sorting the Experience in new arr
			{
				for (int j = i + 1; j < TD; ++j)
				{
					if (arr[i] < arr[j])
					{
						temp = arr[i];
						arr[i] = arr[j];
						arr[j] = temp;
					}
				}
			}
			//printing
			string check;
			for (int x = 0; x < TD; x++)
			{
				for (int y = 0; y < TD; y++)
				{
					if (arr[x] == Dev[y][0].getexperience() && check != Dev[y][0].getEmployeeId())
					{
						check = Dev[y][0].getEmployeeId();
						cout << Dev[y][0].getEmployeeId() << " " << Dev[y][0].getname() << "\t" << Dev[y][0].getqualification() << " " << Dev[y][0].getsalary() << " " << Dev[y][0].gettype() << " " << Dev[y][0].getexperience() << " " << Dev[y][0].getype() << "\t" << Dev[y][0].getstatus() << endl;
						break;
					}
				}

			}
			delete[]arr;
		}
		else if (select == 6)
		{
			int max = 0;
			max = Man[0][0].getCompletedProjects();
			for (int x = 0; x < TM; x++)
			{
				if (Man[x][0].getCompletedProjects()>max)
				{
					max = Man[x][0].getCompletedProjects();
				}
			}
			for (int x = 0; x < TM; x++)
			{
				if (Man[x][0].getCompletedProjects() == max)
				{
					cout << "Manager-Name is: " << Man[x][0].getname() << endl;
				}
			}
		}
		else if (select == 7)
		{
			break;
		}
		else
		{
			cout << "Invalid Input."<<endl;
		}
	}

	delete[]Man;
	Man = nullptr;
	delete[]Dev;
	Dev = nullptr;
	return 0;
}