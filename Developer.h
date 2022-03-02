#pragma once
#include "Employees.h"
class Developer :public Employees
{
	int experience;
	string wtype;
	string status;
public:
	Developer();
	Developer(string, string, string, int,string,int,string,string);
	int getexperience();
	string getype();
	string getstatus();

	Developer& operator=(const Developer &ob);
	void setexperience(int);
	void setype(string);
	void setstatus(string);
	~Developer();
};

