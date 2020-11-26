#include "FairMutex.h"


void adder(fairMutex* fairLock_p, int* counter) {
	while (1) {
		fairLock_p->lock();
		(*counter)++;
		printf("%lu 获得了锁, counter=%d\n", GetCurrentThreadId(), *counter);
		Sleep(SLEEP_TIME); // 获得锁后延迟一段时间释放锁，模拟do something的操作
		fairLock_p->unlock();
		Sleep(SLEEP_TIME); // 释放锁后延迟一段时间再去争抢锁
	}
};


/*
 * 测试基本lock和unlock功能
 */
void testFairMutex1() {
	int counter = 0;
	fairMutex* fairLock_p = new fairMutex();
	thread t1 = thread(adder, fairLock_p, &counter);
	thread t2 = thread(adder, fairLock_p, &counter);
	thread t3 = thread(adder, fairLock_p, &counter);

	t1.join();
	t2.join();
	t3.join();
}


void main() {
	testFairMutex1();
}











