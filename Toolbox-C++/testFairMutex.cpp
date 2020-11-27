#define SLEEP_TIME 400

#include <vector>
#include "FairMutex.h"

/*********************************************************************
 * �������ƣ�adder
 * �������ܣ��ۼ�counter
 * ���������threadNumn - �̵߳ı��
 *           fairLock_p - ��ƽ����ָ��
 *           counter    - ��������ֵ
 * ���ز�����void
 * ��������counter����
 *********************************************************************/
static void adder(int threadNumn, fairMutex* fairLock_p, int* counter) {
	while (1) {
		fairLock_p->lock();
		(*counter)++;
		printf("�߳� %d �������, counter=%d\n", threadNumn, *counter);
		//Sleep(SLEEP_TIME); // ��������ӳ�һ��ʱ���ͷ�����ģ��do something�Ĳ���
		fairLock_p->unlock();
		//Sleep(SLEEP_TIME); // �ͷ������ӳ�һ��ʱ����ȥ������
	}
};


/*********************************************************************
 * �������ƣ�testFairMutexBasicFunction
 * �������ܣ�����fairMutex�������ܣ���֤��ƽ���Ĳ���
 * ���������None
 * ���ز�����void
 * ��������counter��˳��������̰߳����Ŷ�˳�����λ����
 *********************************************************************/ 
static void testFairMutexBasicFunction() {
	printf("------------ testFairMutexBasicFunction ���Կ�ʼ ------------ \n");
	int threadNum = 3;
	int counter = 0;
	fairMutex* fairLock_p = new fairMutex();

	vector<thread*> threadPool;
	for (int i = 0; i < threadNum; i++) {
		threadPool.push_back(new thread(adder, i, fairLock_p, &counter));
	}

	for (int i = 0; i < threadNum; i++) {
		threadPool[i]->join();
	}

	printf("------------ testFairMutexBasicFunction ���Գɹ� ------------ \n");
}











