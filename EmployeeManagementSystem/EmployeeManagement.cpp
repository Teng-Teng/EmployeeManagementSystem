#include "employeeManagement.h"

EmployeeManagement::EmployeeManagement() {
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;
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
	cout << "See you next time!" << endl;
	system("pause");
	exit(0);
}

// add employee
void EmployeeManagement::addEmployee() {
	cout << "Please enter the number of employees you want to add: " << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0) {
		// Calculate the size for the new space
		int newSize = this->m_EmpNum + addNum;

		// allocate memory
		Worker** newSpace = new Worker * [newSize];

		// Copy the data to the new space
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++)
				newSpace[i] = this->m_EmpArray[i];
		}

		// add new data
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int department;

			cout << "Please enter the working ID for employee " << i + 1 << " : " << endl;
			cin >> id;

			cout << "Please enter the name for employee " << i + 1 << " : " << endl;
			cin >> name;

			cout << "Please select the position for the employee: " << endl;
			cout << "1. Employee" << endl;
			cout << "2. Manager" << endl;
			cout << "3. Boss" << endl;
			cin >> department;

			Worker* worker = NULL;

			switch (department) {
				case 1:
					worker = new Employee(id, name, department);
					break;
				case 2:
					worker = new Manager(id, name, department);
					break;
				case 3:
					worker = new Boss(id, name, department);
					break;
				default:
					break;
			}

			newSpace[this->m_EmpNum + i] = worker;
		}

		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;

		this->m_EmpNum = newSize;

		// Save data to file 


		cout << "Successfully add" << addNum << "new employee!" << endl;
	}
	else
		cout << "Incorrect input data!" << endl;

	system("pause");
	system("cls");
}

EmployeeManagement::~EmployeeManagement() {

}
