#include "threadPool.h"

void testThreadPoolUnion();
bool testThreadPoolInit();
bool testAddTask();

void testThreadPoolUnion() {
	if (!testThreadPoolInit()) {
		printf("------------ 单元测试threadPool失败: 用例testThreadPoolInit失败 × ------------ \n");
		return;
	}
	if (!testAddTask()) {
		printf("------------ 单元测试threadPool失败: 用例testAddTask失败 × ------------ \n");
		return;
	}

}


bool testThreadPoolInit() {
	printf("------------ testThreadPoolInit 测试开始 ------------ \n");
	bool flag = true;

	try {
		threadPool pool1 = threadPool(-1, 1); //失败 - poolSize非法
		flag = false;
		printf("pool1初始化成功，与预期不符 ×\n");
	}
	catch (exception* e) {
		printf("%s", e->what());
		printf("pool1初始化失败，符合预期 √\n");
	}
	catch (...) {
		printf("pool1初始化失败，出现其他异常，预期不符 ×\n");
	}
	printf("------------------------------------------------------\n");

	try {
		threadPool pool2 = threadPool(1, -1); //失败 - loglevel非法
		flag = false;
		printf("pool2初始化成功，与预期不符 ×\n");
	}
	catch (exception* e) {
		printf("%s", e->what());
		printf("pool2初始化失败，符合预期 √\n");
	}
	catch (...) {
		printf("pool2初始化失败，出现其他异常，预期不符 ×\n");
	}
	printf("------------------------------------------------------\n");

	try {
		threadPool pool3 = threadPool(3); //成功 - 省略了loglevel参数
		printf("pool3初始化成功，符合预期 √\n");
	}
	catch (exception* e) {
		printf("pool3初始化失败，与预期不符，异常信息：×\n");
		printf("%s", e->what());
		flag = false;
	}
	catch (...) {
		printf("pool3初始化失败，出现其他异常，预期不符 ×\n");
	}
	printf("------------------------------------------------------\n");

	try {
		threadPool pool4 = threadPool(3, 1); //成功 - 完整版参数
		printf("pool4初始化成功，符合预期 √\n");
	}
	catch (exception* e) {
		printf("pool4初始化失败，，与预期不符，异常信息：×\n");
		printf("%s", e->what());
		flag = false;
	}
	catch (...) {
		printf("pool4初始化失败，出现其他异常，预期不符 ×\n");
	}

	if (!flag) {
		printf("----------- testThreadPoolInit 测试失败 × ----------- \n");
		return false;
	}
	printf("----------- testThreadPoolInit 测试成功 √ ----------- \n");
	printf("\n");
	return true;
}


bool testAddTask() {
	printf("----------- testAddTask 测试开始 -------------- \n");

	// 自定义任务 BitMapTask
	class BitMapTask : public Task{
	public:
		BitMapTask(int taskId, int bitId, vector<bool>* bitMap) : Task(taskId) {
			this->bitId = bitId;
			this->bitMap = bitMap;
		}
		vector<bool>* bitMap;
		int bitId;
		void setBitMap() {
			//printf("bitId=%d 执行setBitMap中... \n", bitId);

			if (bitId >= bitMap->size()) {
				printf("错误：bitMap越界 bitId=%d \n", bitId);
			}
			(*bitMap)[bitId] = true;
			//cout << (*bitMap)[bitId] << endl;
		}
		void runTask() {
			setBitMap();
		}
	};

	int numOfTasks = 100;
	int numOfThreads = 4;
	vector<bool> bitMap(numOfTasks, false);

	threadPool pool = threadPool(numOfThreads);
	for (int i = 0; i < numOfTasks; i++) {
		pool.addTask(new BitMapTask(i, i, &bitMap));
	}

	cout << "等待线程池执行任务..." << endl;
	Sleep(2000);
	cout << "线程池任务执行完毕，统计中..." << endl;
	// 检查 BitMap
	int errorCount = 0;
	for (int i = 0; i < numOfTasks; i++) {
		if (bitMap[i] == 0) {
			errorCount++;
		}
	}
	if (errorCount > 0) {
		printf("----------- testAddTask 测试失败 × ----------- \n");
		printf("bitMap未能完全置位 errorCount=%d\n", errorCount);
		return false;
	}
	cout << "统计结果：errorCount=" + to_string(errorCount) + " / numOfTasks=" + to_string(numOfTasks) << endl;

	printf("----------- testAddTask 测试成功 √ ----------- \n");
	printf("\n");
	return true;
}


void main() {	
	testThreadPoolUnion();
	//testThreadPoolInit();
	//testAddTask();

}