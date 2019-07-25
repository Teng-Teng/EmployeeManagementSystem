#include "employeeManagement.h"

EmployeeManagement::EmployeeManagement() {
	// the file doesn't exist
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open()) {
		//cout << "The file doesn't exist!" << endl;

		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_IsFileEmpty = true;

		ifs.close();
		return;
	}

	// the file exist, no data
	char ch;
	ifs >> ch;

	if (ifs.eof()) {
		//cout << "The file is empty!" << endl;

		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_IsFileEmpty = true;

		ifs.close();
		return;
	}

	// the file exists and have employee information
	int num = this->getEmpNum();
	//cout << "The number of employee is: " << num << endl;
	this->m_EmpNum = num;

	// allocate memory
	this->m_EmpArray = new Worker * [this->m_EmpNum];

	// Save the data in the file to an array
	this->initEmp();

	// test code
	/*for (int i = 0; i < this->m_EmpNum; i++) {
		cout << "id: " << this->m_EmpArray[i]->m_Id
			<< " name: " << this->m_EmpArray[i]->m_Name
			<< " department: " << this->m_EmpArray[i]->getDeptName() << endl;
	}*/

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
	cout << "Please enter the ID of employees you want to add: " << endl;

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
		this->save();
		this->m_IsFileEmpty = false;

		cout << "Successfully add" << addNum << "new employee!" << endl;
	}
	else
		cout << "Incorrect input data!" << endl;

	system("pause");
	system("cls");
}

// save file
void EmployeeManagement::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->getDeptName() << endl;
	}

	ofs.close();
}

// get the number of employee in the file
int EmployeeManagement::getEmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	string deptName;
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> deptName) {
		num++;
	}

	return num;
}

// Initialize employee
void EmployeeManagement::initEmp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	string deptName;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> deptName) {
		Worker* worker = NULL;

		if (deptName == "Employee")
			worker = new Employee(id, name, 1);
		else if (deptName == "Manager")
			worker = new Manager(id, name, 2);
		else if (deptName == "Boss")
			worker = new Boss(id, name, 3);

		this->m_EmpArray[index++] = worker;
	}

	ifs.close();
}

// display employee
void EmployeeManagement::displayEmp() {
	if (this->m_IsFileEmpty)
		cout << "The file doesn't exist or the record is empty!" << endl;
	else
		for (int i = 0; i < this->m_EmpNum; i++)
			this->m_EmpArray[i]->showInfo();

	// press any key to clear the screen 
	system("pause");
	system("cls");
}

// delete employee
void EmployeeManagement::delEmp() {
	if (this->m_IsFileEmpty)
		cout << "The file doesn't exist or the record is empty!" << endl;
	else {
		cout << "Please enter the employee number you want to delete: " << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);
		if (index != -1) {
			for (int i = index; i < this->m_EmpNum - 1; i++) 
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			this->m_EmpNum--;
			this->save();
			cout << "Delete employee successfully!" << endl;
			
		} else
			cout << "Delete failed, can't find this employee!" << endl;
	}

	system("pause");
	system("cls");
}

// check if an employee exists, if exists return the index in the array, or return -1
int EmployeeManagement::isExist(int id) {
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			index = i;
			break;
		}
	}

	return index;
}

// modify employee
void EmployeeManagement::modifyEmp() {
	if (this->m_IsFileEmpty)
		cout << "The file doesn't exist or the record is empty!" << endl;
	else {
		cout << "Please enter the ID of employee you want to modify: " << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1) {
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int deptSelect = 0;

			cout << "Find the employee with ID " << id << ", please enter the new employee ID: " << endl;
			cin >> newId;

			cout << "Please enter the new name: " << endl;
			cin >> newName;

			cout << "Please select the position for the employee: " << endl;
			cout << "1. Employee" << endl;
			cout << "2. Manager" << endl;
			cout << "3. Boss" << endl;
			cin >> deptSelect;

			Worker* worker = NULL;

			switch (deptSelect) {
			case 1:
				worker = new Employee(newId, newName, deptSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, deptSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, deptSelect);
				break;
			default:
				break;
			}

			this->m_EmpArray[ret] = worker;
			cout << "Modify successfully!" << endl;
			this->save();

		} else
			cout << "Can't find this employee!" << endl;
	}

	system("pause");
	system("cls");
}

EmployeeManagement::~EmployeeManagement() {
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
