#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Manager :public Worker {
public:
	Manager(int id, string name, int dId);

	// show employee information
	virtual void showInfo();

	// get department number
	virtual string getDeptName();
};

