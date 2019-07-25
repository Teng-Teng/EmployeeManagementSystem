#include <iostream>
using namespace std;
#include "employeeManagement.h";
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main() {
	// test code
	/*Worker* worker = NULL;
	worker = new Employee(1, "teng", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "rose", 4);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "jack", 8);
	worker->showInfo();
	delete worker;*/


	EmployeeManagement em;

	int choice = 0;

	while (true) {

		// display the main menu
		em.displayMenu();

		cout << "Please enter your choice: " << endl;
		cin >> choice;

		switch (choice) {
			case 0:
				// Exit management system
				em.exitSystem();
				break;
			case 1:
				// Add employee information 
				em.addEmployee();
				break; 
			case 2:
				// Display employee information
				em.displayEmp();
				break;
			case 3:
				// Delete employee information
				em.delEmp();
				break;
			case 4:
				// Modify employee information
				em.modifyEmp();
				break;
			case 5:
				// Search employee information

				break;
			case 6:
				// Sort by number

				break;
			case 7:
				// Empty all documents

				break;
			default:
				system("cls");
				break;
		}


	}

	system("pause");

	return 0;
}