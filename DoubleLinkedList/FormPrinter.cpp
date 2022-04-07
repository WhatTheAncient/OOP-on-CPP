#include "FormPrinter.h"

string date_to_string(date _date)
{
	string day = to_string(_date.day);
	if (day.length() == 1)
		day = "0" + day;

	string month = to_string(_date.month);
	if (month.length() == 1)
		month = "0" + month;

	return day + "/" + month + "/" + to_string(_date.year);
};

void FormPrinter::printLine()
{
	string line = "|" + string(97, '-') + '|';
	cout << line << endl;
};

void FormPrinter::printHeader()
{
	printLine();
	cout << "|"  << setw(3) << "ID" << "|" << setw(20) << "Surame and initials" << "|" << setw(10) << "Birthday"
		<< "|" << setw(25) << "Education" << "|" << setw(20) << "Home address"
		<< "|" << setw(8) << "Salary" << "|" << setw(5) << "Pass"
		<< "|" << endl;
	printLine();
};

void FormPrinter::printForm(EmployeeForm form)
{

	cout << "|" << setw(3) << form.getId() << "|" << setw(20) << form.getName() << "|" << setw(10) << date_to_string(form.getBirthday())
		<< "|" << setw(25) << form.getEducation() << "|" << setw(20) << form.getAddress()
		<< "|" << setw(8) << form.getSalary() << "|" << setw(5) << form.getPass()
		<< "|" << endl;
	printLine();
};
