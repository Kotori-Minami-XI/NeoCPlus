#include "FairMutex.h"


void adder(fairMutex* fairLock_p, int* counter) {
	while (1) {
		fairLock_p->lock();
		(*counter)++;
		printf("%lu �������, counter=%d\n", GetCurrentThreadId(), *counter);
		Sleep(SLEEP_TIME); // ��������ӳ�һ��ʱ���ͷ�����ģ��do something�Ĳ���
		fairLock_p->unlock();
		Sleep(SLEEP_TIME); // �ͷ������ӳ�һ��ʱ����ȥ������
	}
};


/*
 * ���Ի���lock��unlock����
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











