#include "threadPool.h"

void testThreadPoolUnion();
bool testThreadPoolInit();
bool testAddTask();

void testThreadPoolUnion() {
	if (!testThreadPoolInit()) {
		printf("------------ ��Ԫ����threadPoolʧ��: ����testThreadPoolInitʧ�� �� ------------ \n");
		return;
	}
	if (!testAddTask()) {
		printf("------------ ��Ԫ����threadPoolʧ��: ����testAddTaskʧ�� �� ------------ \n");
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
	printf("\n");
	return true;
}


bool testAddTask() {
	printf("----------- testAddTask ���Կ�ʼ -------------- \n");

	// �Զ������� BitMapTask
	class BitMapTask : public Task{
	public:
		BitMapTask(int taskId, int bitId, vector<bool>* bitMap) : Task(taskId) {
			this->bitId = bitId;
			this->bitMap = bitMap;
		}
		vector<bool>* bitMap;
		int bitId;
		void setBitMap() {
			//printf("bitId=%d ִ��setBitMap��... \n", bitId);

			if (bitId >= bitMap->size()) {
				printf("����bitMapԽ�� bitId=%d \n", bitId);
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

	cout << "�ȴ��̳߳�ִ������..." << endl;
	Sleep(2000);
	cout << "�̳߳�����ִ����ϣ�ͳ����..." << endl;
	// ��� BitMap
	int errorCount = 0;
	for (int i = 0; i < numOfTasks; i++) {
		if (bitMap[i] == 0) {
			errorCount++;
		}
	}
	if (errorCount > 0) {
		printf("----------- testAddTask ����ʧ�� �� ----------- \n");
		printf("bitMapδ����ȫ��λ errorCount=%d\n", errorCount);
		return false;
	}
	cout << "ͳ�ƽ����errorCount=" + to_string(errorCount) + " / numOfTasks=" + to_string(numOfTasks) << endl;

	printf("----------- testAddTask ���Գɹ� �� ----------- \n");
	printf("\n");
	return true;
}


void main() {	
	testThreadPoolUnion();
	//testThreadPoolInit();
	//testAddTask();

}