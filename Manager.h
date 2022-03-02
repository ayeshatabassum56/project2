#pragma once
#include "Employees.h"
class Manager :public Employees
{
	char rank;
	int TotalGroupMembers;
	int CompletedProjects;
	int PendingProjects;
public:
	Manager();
	Manager(string, string, string, int,string,char,int,int,int);
	char getrank();
	int getTotalGroupMembers();
	int getCompletedProjects();
	int getPendingProjects();

	void setrank( char);
	void setTotalGroupMembers(int);
	void setCompletedProjects(int);
	void setPendingProjects(int);
	Manager& operator=(const Manager &ob);
	~Manager();
};

