#include "FairMutex.h"

fairMutex::fairMutex() {
	isLocked = false;
}

void fairMutex::lock() {
	unique_lock<mutex> locker(mtx);
	while (isLocked) {
		cv.wait(locker);
	}
	isLocked = true;
}

void fairMutex::unlock() {
	isLocked = false;
	cv.notify_one();
}