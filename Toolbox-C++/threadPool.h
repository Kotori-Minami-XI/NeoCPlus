#ifndef THREADPOOL_H
#define THREADPOOL_H

#define DBG_PRINT (printf("%s:%u %s:%s:\t", __FILE__, __LINE__, __DATE__, __TIME__), printf) 

#define NUM_ERROR_TYPE 3
#define NUM_LOG_LEVEL  4

#include <stdio.h>
#include <stdarg.h>
#include <iostream>
#include <functional>

#include <string>

#include <vector>
#include <queue>

#include <mutex>
#include <thread>

#include <windows.h>

using namespace std;

static enum ErrorType { UNKNOWN_ERROR, INVALID_PARAMETER, MEMORY_ERROR};
static const string ErrorTypeMsg[NUM_ERROR_TYPE] = {"UNKNOWN_ERROR", "INVALID_PARAMETER", "MEMORY_ERROR"};

static enum LogLevel { LOG_MINI_LEVEL, LOG_MEDIUM_LEVEL, LOG_HIGH_LEVEL, LOG_FULL_LEVEL};
static const string LogLevelMsg[NUM_LOG_LEVEL] = { "LOG_MINI_LEVEL", "LOG_MEDIUM_LEVEL", "LOG_FULL_LEVEL", "LOG_FULL_LEVEL" };

class Task {
public:
	Task(int taskId) {
		this->taskId = taskId;
	}
	int taskId;
	virtual void runTask()=0;
};

class threadPool
{
public:
	threadPool(int poolSize, int logLevel = LOG_MEDIUM_LEVEL) {

		if (poolSize < 0) {
			printError(INVALID_PARAMETER, "poolSize should be above 0!");
			throw new exception("INVALID_PARAMETER - illegal poolSize\n");
			return;
		}
		if (logLevel < 0 || logLevel >= NUM_LOG_LEVEL) {
			printError(INVALID_PARAMETER, "logLevel is above 0 and no mroe than %d", NUM_LOG_LEVEL);
			throw new exception("INVALID_PARAMETER - illegal logLevel\n");
			return;
		}

		this->poolSize = poolSize;
		this->logLevel = (LogLevel)logLevel;

		initThreadVector();
	}

	threadPool(const threadPool&) {
		return;
	}

	~threadPool() {
		cv.notify_all(); // 唤醒所有线程执行
		for (int i = 0; i < this->poolSize; i++) {
			threadVector[i]->detach();
		}
	}

	void addTask(Task *task) {
		taskQueue.push(task);
	}

	vector<thread*>& getThreadVector() {
		return threadVector;
	}

private:

	int poolSize;
	LogLevel logLevel;
	vector<thread*> threadVector;
	queue<Task*> taskQueue;
	mutex mtx;
	condition_variable cv;

	void initThreadVector(){
		threadVector = vector<thread*>(this->poolSize);
		for (int i = 0; i < this->poolSize; i++) {
			threadVector[i] = new thread(&threadPool::threadRun, this);
		}
	}

	void entry(Task *task) {
		task->runTask();
	}

	void threadRun() {
		while (true) {
			unique_lock<mutex> locker(mtx);
			while (taskQueue.empty()) {
				cv.wait(locker);
			}

			// 队首任务出列
			Task* task = taskQueue.front();
			taskQueue.pop();

			// 下一个线程获得任务
			locker.unlock();
			cv.notify_one();

			function<void(Task*)> func = bind(&threadPool::entry, this, task);
			func(task);
		}
	}

	void LogDebug(LogLevel traceLevel, const char* format, ...) {
		if (this->logLevel >= traceLevel) {
			va_list va;
			va_start(va, format);
			printf("%s %s %s:%u:\t", __DATE__, __TIME__, __FILE__, __LINE__);
			vprintf(format, va);
			va_end(va);
			printf("\n");
		}
	}

	void printError(ErrorType errorType, const char* format, ...) {
		va_list va;
		va_start(va, format);
		printf("%s %s %s:%u:\t", __DATE__, __TIME__, __FILE__, __LINE__);
		printf("Fatal error occured: %s\t", ErrorTypeMsg[errorType].c_str());
		vprintf(format, va);
		va_end(va);
		printf("\n");
	}

};



#endif /* THREADPOOL_H */

