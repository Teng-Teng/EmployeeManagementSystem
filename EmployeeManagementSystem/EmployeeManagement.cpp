#include "EmployeeManagement.h"

EmployeeManagement::EmployeeManagement() {

}

// display the main menu
void EmployeeManagement::displayMenu() {
	cout << "*******************************************************************" << endl;
	cout << "**********   Welcome to employee management system!   *************" << endl;
	cout << "***************   0. Exit management system!       ****************" << endl;
	cout << "***************   1. Add employee information      ****************" << endl;
	cout << "***************   2. Display employee information  ****************" << endl;
	cout << "***************   3. Delete employee information   ****************" << endl;
	cout << "***************   4. Modify employee information   ****************" << endl;
	cout << "***************   5. Search employee information   ****************" << endl;
	cout << "***************   6. Sort by number                ****************" << endl;
	cout << "***************   7. Empty all documents           ****************" << endl;
	cout << "*******************************************************************" << endl;
	cout << endl;
}

// exit management system
void EmployeeManagement::exitSystem() {
	cout << "Have a good day! Bye!" << endl;
	system("pause");
	exit(0);
}

EmployeeManagement::~EmployeeManagement() {

}
