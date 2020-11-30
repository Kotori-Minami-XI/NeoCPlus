#include "threadPool.h"

void testThreadPoolUnion();
bool testThreadPoolInit();

void testThreadPoolUnion() {
	if (!testThreadPoolInit()) {
		printf("------------ 单元测试threadPool失败: 用例testThreadPoolInit失败 × ------------ \n");
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
	return true;
}



void main() {	
	testThreadPoolInit();



}