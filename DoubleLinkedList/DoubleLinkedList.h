#pragma once
#include "FormPrinter.h"

struct listUnit {
	EmployeeForm form;
	listUnit* next;
	listUnit* prev;

	listUnit(EmployeeForm form) : form(form), next(nullptr), prev(nullptr) {};
};

class DoubleLinkedList
{
private:
	listUnit* first;
	listUnit* last;
public:
	DoubleLinkedList() : first(nullptr), last(nullptr) {};

	bool isEmpty();
	
	bool isSingle();

	void appendUnit(EmployeeForm, string);

	void removeUnit(unsigned long int);

	listUnit* findUnitById(unsigned long int);

	friend ostream& operator << (ostream&, DoubleLinkedList&);
};

