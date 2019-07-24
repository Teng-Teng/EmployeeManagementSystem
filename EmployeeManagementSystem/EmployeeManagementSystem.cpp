#include <iostream>
using namespace std;
#include "EmployeeManagement.h";

int main() {
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

				break; 
			case 2:
				// Display employee information

				break;
			case 3:
				// Delete employee information

				break;
			case 4:
				// Modify employee information

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