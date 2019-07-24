#include "manager.h"

Manager::Manager(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Manager::showInfo() {
	cout << "Employee number: " << this->m_Id
		<< "\tEmployee name: " << this->m_Name
		<< "\tDepartment: " << this->getDeptName()
		<< "\tJob Responsibilities: Complete the task assigned by the boss, and issue tasks to employees" << endl;
}

string Manager::getDeptName() {
	return string("Manager");
}
