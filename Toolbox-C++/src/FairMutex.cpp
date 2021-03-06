#include "FairMutex.h"

/*********************************************************************
 * 函数名称：fairMutex
 * 函数功能：fairMutex构造函数
 * 输入参数：None
 * 返回参数：None
 * 输出结果：初始化成员函数isLocked
 *********************************************************************/
fairMutex::fairMutex() {
	isLocked = false;
}


/*********************************************************************
 * 函数名称：lock
 * 函数功能：公平锁fairMutex的上锁操作，如果获得锁则将标志位isLocked置
 *           位为true并继续执行。如果没有获得锁则通过条件变量进行等待其
 *		     他线程的唤醒操作
 * 输入参数：None
 * 返回参数：void
 * 输出结果：isLocked置位或者等待其他线程唤醒
 *********************************************************************/
void fairMutex::lock() {
	unique_lock<mutex> locker(mtx);
	while (isLocked) {
		cv.wait(locker);
	}
	isLocked = true;
}

/*********************************************************************
 * 函数名称：unlock
 * 函数功能：公平锁fairMutex的解锁操作，将isLocked置为false，并通知唤醒
 *           条件变量等待队列的第一个线程并让自己开始陷入休眠。如果不让
 *           自己陷入休眠则可能还是会自己抢到锁，使其他线程陷入饥饿状态
 * 输入参数：None
 * 返回参数：void
 * 输出结果：唤醒等待队列的第一个线程，并让自己陷入休眠1ms
 *********************************************************************/
void fairMutex::unlock() {
	unique_lock<mutex> locker(mtx);
	isLocked = false;
	locker.unlock();
	cv.notify_one();
	Sleep(1);
}