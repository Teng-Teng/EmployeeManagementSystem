#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
#define FILENAME "empFile.txt"

class EmployeeManagement {
public:
	EmployeeManagement();

	// display the main menu
	void displayMenu();

	// exit system
	void exitSystem();

	// add employee
	void addEmployee();

	// save file
	void save();

	// get the number of employee in the file
	int getEmpNum();

	// Initialize employee
	void initEmp();

	// diaplay employee
	void displayEmp();

	// delete employee
	void delEmp();

	// check if an employee exists, if exists return the index in the array, or return -1
	int isExist(int id);

	// modify employee
	void modifyEmp();

	// total number of employee
	int m_EmpNum;

	// whether the file is empty
	bool m_IsFileEmpty;

	// Employee array pointer
	Worker** m_EmpArray;

	~EmployeeManagement();
};
