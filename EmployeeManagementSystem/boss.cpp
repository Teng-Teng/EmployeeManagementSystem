#include "boss.h"

Boss::Boss(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Boss::showInfo() {
	cout << "Employee number: " << this->m_Id
		<< "\tEmployee name: " << this->m_Name
		<< "\tDepartment: " << this->getDeptName()
		<< "\tJob Responsibilities: Manage the company" << endl;
}

string Boss::getDeptName() {
	return string("Boss");
}
