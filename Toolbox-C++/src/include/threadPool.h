#ifndef THREADPOOL_H
#define THREADPOOL_H

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

#define NUM_ERROR_TYPE 3
#define NUM_LOG_LEVEL  4

using namespace std;

static enum ErrorType { UNKNOWN_ERROR, INVALID_PARAMETER, MEMORY_ERROR};
static const string ErrorTypeMsg[NUM_ERROR_TYPE] = {"UNKNOWN_ERROR", "INVALID_PARAMETER", "MEMORY_ERROR"};

static enum LogLevel { LOG_MINI_LEVEL, LOG_MEDIUM_LEVEL, LOG_HIGH_LEVEL, LOG_FULL_LEVEL};
static const string LogLevelMsg[NUM_LOG_LEVEL] = { "LOG_MINI_LEVEL", "LOG_MEDIUM_LEVEL", "LOG_FULL_LEVEL", "LOG_FULL_LEVEL" };

class Task {
public:
	Task(int taskId);

	virtual void runTask() = 0;

private:
	int taskId;
};

class threadPool
{
public:
	threadPool(int poolSize, int logLevel = LOG_MEDIUM_LEVEL);

	threadPool(const threadPool&);

	~threadPool();

	void addTask(Task* task);

private:
	int poolSize;

	bool poolStarted;

	LogLevel logLevel;

	vector<thread*> threadVector;

	queue<Task*> taskQueue;

	mutex mtx;

	condition_variable cv;

	void initThreadVector();

	void entry(Task* task);

	void threadRun();

	void LogDebug(LogLevel traceLevel, const char* format, ...);

	void printError(ErrorType errorType, const char* format, ...);
};



#endif /* THREADPOOL_H */

