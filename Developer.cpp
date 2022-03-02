#include "Developer.h"

Developer::Developer()
{
	this->experience = 0;
	this->wtype = ' ';
	this->status = ' ';
}
Developer::Developer(string id, string n, string qua, int sal,string t, int ex, string tp, string st) :Employees(id,n,qua,sal,t)
{
	this->experience = ex;
	this->wtype = tp;
	this->status = st;
}
int Developer::getexperience()
{
	return experience;
}
string Developer::getype()
{
	return wtype;
}
string Developer::getstatus()
{
	return status;
}

void Developer::setexperience(int ex)
{
	this->experience = ex;
}
void Developer::setype(string tp)
{
	this->wtype=tp;
}
void Developer::setstatus(string st) 
{
	this->status = st;
}
Developer& Developer::operator=(const Developer &ob)
{
	this->name = ob.name;
	this->EmployeeId = ob.EmployeeId;
	this->qualification = ob.qualification;
	this->salary = ob.salary;
	this->type = ob.type;
	this->experience = ob.experience;
	this->wtype = ob.wtype;;
	this->status = ob.status;
	return*this;
}
Developer::~Developer()
{
}
