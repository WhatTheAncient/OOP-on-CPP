#pragma once
#include "DoubleLinkedList.h"

class Menu
{
private:

	enum class User_Choice
	{
		createList,
		appendForm,
		removeForm,
		printList,
		findForm,
		exit
	};

	User_Choice userChoice;

	DoubleLinkedList myList;

	FormPrinter printer;

	bool endOfProgram;

public:

	Menu()
	{
		endOfProgram = false;
		printer = FormPrinter();
		while (!endOfProgram)
		{
			showTextInterface();
			askUser();
			switch (userChoice)
			{
			case User_Choice::createList:
			{
				createList();
				break;
			}
			case User_Choice::appendForm:
			{
				appendForm();
				break;
			}
			case User_Choice::removeForm:
			{
				removeForm();
				break;
			}
			case User_Choice::printList:
			{
				cout << myList;
				break;
			}
			case User_Choice::findForm:
			{
				findForm();
				break;
			}
			case User_Choice::exit:
			{
				endOfProgram = true;
				break;
			}
			default: {};
			};
		}
	}

	void createList();

	void appendForm();

	void removeForm();

	void findForm();

	void showTextInterface();

	void askUser();
};

