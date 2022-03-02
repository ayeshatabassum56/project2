#pragma once
#include<iostream>
#include<string>
using namespace std;
class Employees
{
protected:
	static int TotalEmployees;
	string EmployeeId;
	string name;
	string qualification;
	int salary;
	string type;
public:
	Employees();
	Employees(string, string, string,int,string);

	static int getTotalEmployees();
	string getEmployeeId();
	string getname();
	string getqualification();
	int getsalary();
	string gettype();

	static void setTotalEmployees(int);
	void setEmployeeId(string);
	void setname(string);
	void setqualification(string);
	void setsalary(int);
	void settype(string);
	~Employees();
};

