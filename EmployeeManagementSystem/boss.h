#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Boss :public Worker {
public:
	Boss(int id, string name, int dId);

	// show employee information
	virtual void showInfo();

	// get department number
	virtual string getDeptName();
};

