#define SLEEP_TIME 400

#include <vector>
#include "FairMutex.h"

/*********************************************************************
 * 函数名称：adder
 * 函数功能：累加counter
 * 输入参数：threadNumn - 线程的编号
 *           fairLock_p - 公平锁的指针
 *           counter    - 计数器的值
 * 返回参数：void
 * 输出结果：counter递增
 *********************************************************************/
static void adder(int threadNumn, fairMutex* fairLock_p, int* counter) {
	while (1) {
		fairLock_p->lock();
		(*counter)++;
		printf("线程 %d 获得了锁, counter=%d\n", threadNumn, *counter);
		//Sleep(SLEEP_TIME); // 获得锁后延迟一段时间释放锁，模拟do something的操作
		fairLock_p->unlock();
		//Sleep(SLEEP_TIME); // 释放锁后延迟一段时间再去争抢锁
	}
};


/*********************************************************************
 * 函数名称：testFairMutexBasicFunction
 * 函数功能：测试fairMutex基本功能，保证公平锁的策略
 * 输入参数：None
 * 返回参数：void
 * 输出结果：counter按顺序递增，线程按照排队顺序依次获得锁
 *********************************************************************/ 
static void testFairMutexBasicFunction() {
	printf("------------ testFairMutexBasicFunction 测试开始 ------------ \n");
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

	printf("------------ testFairMutexBasicFunction 测试成功 ------------ \n");
}











