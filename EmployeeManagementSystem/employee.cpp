#include "employee.h"

Employee::Employee(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Employee::showInfo() {
	cout << "Employee number: " << this->m_Id
		<< "\tEmployee name: " << this->m_Name
		<< "\tDepartment: " << this->getDeptName()
		<< "\tJob Responsibilities: Complete the task assigned by the manager" << endl;
}

string Employee::getDeptName() {
	return string("Employee");
}
