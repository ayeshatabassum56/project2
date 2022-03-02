#include "Employees.h"
Employees::Employees()
{
	this->EmployeeId = ' ';
	this->name =' ' ;
	this->qualification = ' ';
	this->salary = 0;
	this->type = ' ';
}
Employees::Employees(string id, string n, string q, int s,string t)
{
	this->EmployeeId = id;
	this->name = n;
	this->qualification = q;
	this->salary = s;
	this->type = t;
}
int Employees::getTotalEmployees()
{
	return TotalEmployees;
}
string Employees::getEmployeeId()
{
	return EmployeeId;
}
string Employees::getname()
{
	return name;
}
string Employees::getqualification()
{
	return qualification;
}
int Employees::getsalary()
{
	return salary;
}
string Employees::gettype()
{
	return type;
}


void Employees::setEmployeeId(string id )
{
	this->EmployeeId = id;
}
void Employees::setname(string n)
{
	this->name = n;
}
void Employees::setqualification(string qua)
{
	this->qualification = qua;
}
void Employees::setsalary(int sal)
{
	this->salary = sal;
}
void Employees::setTotalEmployees(int i)
{
	TotalEmployees = i;
}
void Employees::settype(string t)
{
	this->type = t;
}



Employees::~Employees()
{
}
int Employees::TotalEmployees = 0;