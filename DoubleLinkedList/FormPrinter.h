#pragma once
#include "EmployeeForm.h"

class FormPrinter
{
public:
	FormPrinter() { }
	void printLine();
	void printHeader();
	void printForm(EmployeeForm);
};
