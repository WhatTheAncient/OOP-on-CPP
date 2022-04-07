#include "DoubleLinkedList.h"

bool DoubleLinkedList::isEmpty() {
	return first == nullptr;
};

bool DoubleLinkedList::isSingle() {
	return first == last;
}


void DoubleLinkedList::appendUnit(EmployeeForm form, string flag = "end") {
	if (!(flag == "begin" || flag == "middle" || flag == "end")) { return; }	// throw exception

	listUnit* newUnit = new listUnit(form);

	if (isEmpty()) {
		first = newUnit;
		last = first;
	}
	else {
		if (flag == "begin") {
			newUnit->next = first;
			first->prev = newUnit;
			first = newUnit;

		}
		else {
			if (flag == "middle") {
				unsigned long int currentUnitId = helpers::askId();

				listUnit* currentUnit = findUnitById(currentUnitId);
				
				newUnit->prev = currentUnit;
				newUnit->next = currentUnit->next;
				currentUnit->next = newUnit;
			}
			else {
				newUnit->prev = last;
				last->next = newUnit;
				last = newUnit;
			}
		}
	}
};

void DoubleLinkedList::removeUnit(unsigned long int employeeId) {
	if (isEmpty()) return;

	listUnit* currentUnit = first;

	do {
		if (currentUnit->form.getId() == employeeId) {
			if (isSingle()) {							// Single Element List
				first = nullptr;
				last = nullptr;
			}
			else {
				if (currentUnit == first) {				// Head
					first->prev = nullptr;
					first = first->next;
				}
				else {
					if (currentUnit == last) {			// Tail
						last = last->prev;
						last->next = nullptr;
					}
					else {								// Middle
						currentUnit->prev->next = currentUnit->next;
						currentUnit->next->prev = currentUnit->prev;
					}
				}
			}
			delete currentUnit;
			return;
		}
		currentUnit = currentUnit->next;
	} while (currentUnit);
};

listUnit* DoubleLinkedList::findUnitById(unsigned long int employeeId) {
	listUnit* currentUnit = first;
	while (currentUnit != last->next)
	{
		if ((currentUnit->form.getId() == employeeId)) {
			return currentUnit;
		}
		currentUnit = currentUnit->next;
	}
};

ostream& operator << (ostream& stream, DoubleLinkedList& list) {
	listUnit* currentUnit = list.first;
	FormPrinter().printHeader();
	do {
		FormPrinter().printForm(currentUnit->form);
		currentUnit = currentUnit->next;
	} while (currentUnit);
	
	return stream;
}
