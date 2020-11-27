#ifndef FAIRMUTEX_H
#define FAIRMUTEX_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

class fairMutex {
private:
	mutex mtx;
	condition_variable cv;
	bool isLocked;

public:
	fairMutex();

	void lock();
	void unlock();
};

#endif /* FAIRMUTEX_H */


