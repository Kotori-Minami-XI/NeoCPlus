#include "threadPool.h"

void testThreadPoolUnion();
bool testThreadPoolInit();

void testThreadPoolUnion() {
	if (!testThreadPoolInit()) {
		printf("------------ ��Ԫ����threadPoolʧ��: ����testThreadPoolInitʧ�� �� ------------ \n");
		return;
	}

}


bool testThreadPoolInit() {
	printf("------------ testThreadPoolInit ���Կ�ʼ ------------ \n");
	bool flag = true;

	try {
		threadPool pool1 = threadPool(-1, 1); //ʧ�� - poolSize�Ƿ�
		flag = false;
		printf("pool1��ʼ���ɹ�����Ԥ�ڲ��� ��\n");
	}
	catch (exception* e) {
		printf("%s", e->what());
		printf("pool1��ʼ��ʧ�ܣ�����Ԥ�� ��\n");
	}
	catch (...) {
		printf("pool1��ʼ��ʧ�ܣ����������쳣��Ԥ�ڲ��� ��\n");
	}
	printf("------------------------------------------------------\n");

	try {
		threadPool pool2 = threadPool(1, -1); //ʧ�� - loglevel�Ƿ�
		flag = false;
		printf("pool2��ʼ���ɹ�����Ԥ�ڲ��� ��\n");
	}
	catch (exception* e) {
		printf("%s", e->what());
		printf("pool2��ʼ��ʧ�ܣ�����Ԥ�� ��\n");
	}
	catch (...) {
		printf("pool2��ʼ��ʧ�ܣ����������쳣��Ԥ�ڲ��� ��\n");
	}
	printf("------------------------------------------------------\n");

	try {
		threadPool pool3 = threadPool(3); //�ɹ� - ʡ����loglevel����
		printf("pool3��ʼ���ɹ�������Ԥ�� ��\n");
	}
	catch (exception* e) {
		printf("pool3��ʼ��ʧ�ܣ���Ԥ�ڲ������쳣��Ϣ����\n");
		printf("%s", e->what());
		flag = false;
	}
	catch (...) {
		printf("pool3��ʼ��ʧ�ܣ����������쳣��Ԥ�ڲ��� ��\n");
	}
	printf("------------------------------------------------------\n");

	try {
		threadPool pool4 = threadPool(3, 1); //�ɹ� - ���������
		printf("pool4��ʼ���ɹ�������Ԥ�� ��\n");
	}
	catch (exception* e) {
		printf("pool4��ʼ��ʧ�ܣ�����Ԥ�ڲ������쳣��Ϣ����\n");
		printf("%s", e->what());
		flag = false;
	}
	catch (...) {
		printf("pool4��ʼ��ʧ�ܣ����������쳣��Ԥ�ڲ��� ��\n");
	}

	if (!flag) {
		printf("----------- testThreadPoolInit ����ʧ�� �� ----------- \n");
		return false;
	}
	printf("----------- testThreadPoolInit ���Գɹ� �� ----------- \n");
	return true;
}



void main() {	
	testThreadPoolInit();



}