#include "Manager.h"
Manager::Manager()
{
	this->rank = ' ';
	this->TotalGroupMembers = 0;
	this->CompletedProjects = 0;
	this->PendingProjects = 0;
}
Manager::Manager(string id, string n, string qua, int sal,string t, char rak, int tg, int cp, int pp):Employees(id,n,qua,sal,t)
{
	this->rank = rak;
	this->TotalGroupMembers = tg;
	this->CompletedProjects = cp;
	this->PendingProjects = pp;
}
char Manager::getrank()
{
	return rank;
}
int Manager::getTotalGroupMembers()
{
	return TotalGroupMembers;
}
int Manager::getCompletedProjects()
{
	return CompletedProjects;
}
int Manager::getPendingProjects()
{
	return PendingProjects;
}

void Manager::setrank(char r)
{
	this->rank = r;
}
void Manager::setTotalGroupMembers(int t)
{
	this->TotalGroupMembers = t;
}
void Manager::setCompletedProjects(int c)
{
	this->CompletedProjects = c;
}
void Manager::setPendingProjects(int p)
{
	this->PendingProjects = p;
}
Manager& Manager::operator=(const Manager &ob)
{
	this->name = ob.name;
	this->EmployeeId = ob.EmployeeId;
	this->qualification = ob.qualification;
	this->salary = ob.salary;
	this->type = ob.type;
	this->rank = ob.rank;
	this->TotalGroupMembers = ob.TotalGroupMembers;
	this->CompletedProjects = ob.CompletedProjects;
	this->PendingProjects = ob.PendingProjects;
	return *this;
}

Manager::~Manager()
{
}
