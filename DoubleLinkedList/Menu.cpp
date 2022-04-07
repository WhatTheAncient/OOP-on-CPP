#include "Menu.h"

void Menu::showTextInterface()
{
	cout << "Choose what you want to do:\n" << endl;
	cout << "1.Create a list of Employee forms\n"
		<< "2.Append form in list\n"
		<< "3.Remove form from the list by ID\n"
		<< "4.Print the list of EmployeeForms\n"
		<< "5.Find the form by ID\n"
		<< "6.Exit\n" << endl;
	cout << ">>> ";
}

void Menu::askUser()
{
	unsigned int input;
	cin >> input;
	this->userChoice = static_cast<User_Choice>(input - 1);
}

void Menu::createList()
{
	EmployeeForm firstUnit = EmployeeForm("First Employee", { 12, 01, 1998 }, "College", "London", 1000, 0);
	myList.appendUnit(firstUnit, "end");
}

void Menu::appendForm()
{
	EmployeeForm newUnit;
	cin >> newUnit;

	string insertFlag = helpers::askInsertFlag();

	myList.appendUnit(newUnit, insertFlag);
}

void Menu::removeForm()
{
	auto employeeId = helpers::askId();
	myList.removeUnit(employeeId);
}

void Menu::findForm()
{
	auto employeeId = helpers::askId();
	listUnit* foundUnit = myList.findUnitById(employeeId);
	if (!foundUnit) return;
	printer.printHeader();
	printer.printForm(foundUnit->form);
}
