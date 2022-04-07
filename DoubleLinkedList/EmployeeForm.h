#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


struct helpers
{
	static unsigned long int askId()
	{
		unsigned long int id = 0;
		cout << "Please enter the id of employee:   ";
		cin >> id;

		return id;
	};

	static string askInsertFlag()
	{
		cout << "Where do you want to insert new form?   (begin/middle/end)" << endl;

		string insertFlag = "";
		cin >> insertFlag;

		return insertFlag;
	};
};

struct date
{
	unsigned int day;
	unsigned int month;
	unsigned int year;
};


class EmployeeForm
{
private:
	unsigned long int id;
	string name;
	date birthday;
	string education;
	string address;
	unsigned int salary;
	bool pass;

	unsigned long int& idCounter() { static unsigned long int currentId = 0; return currentId; };
public:

	EmployeeForm() { id = ++idCounter(); };
	EmployeeForm(string name, date birthday, string education, string address, unsigned int salary, bool pass)
	{
		this->id = ++idCounter();
		this->name = name;
		this->birthday = birthday;
		this->education = education;
		this->address = address;
		this->salary = salary;
		this->pass = pass;
	};
	unsigned long int getId() { return this->id; }
	string getName() { return this->name; };
	date getBirthday() { return this->birthday; };
	string getEducation() { return this->education; };
	string getAddress() { return this->address; };
	unsigned int getSalary() { return this->salary; };
	bool getPass() { return this->pass; };
	friend istream& operator >> (istream& stream, EmployeeForm& obj);
	
};

