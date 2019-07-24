#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

class EmployeeManagement {
public:
	EmployeeManagement();

	// display the main menu
	void displayMenu();

	// exit system
	void exitSystem();

	// add employee
	void addEmployee();

	// total number of employee
	int m_EmpNum;

	// Employee array pointer
	Worker** m_EmpArray;

	~EmployeeManagement();
};
