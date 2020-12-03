#include "threadPool.h"

Task::Task(int taskId) {
	this->taskId = taskId;
}


threadPool::threadPool(int poolSize, int logLevel) {

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

	mtx.lock();
	this->poolStarted = false;
	initThreadVector();
	this->poolStarted = true;
	mtx.unlock();
}

threadPool::threadPool(const threadPool&) {
	return;
}

threadPool::~threadPool() {
	cv.notify_all(); // 唤醒所有线程执行
	for (int i = 0; i < this->poolSize; i++) {
		threadVector[i]->detach();
	}
}

void threadPool::addTask(Task* task) {
	mtx.lock();
	taskQueue.push(task);
	mtx.unlock();
}

void threadPool::initThreadVector() {
	threadVector = vector<thread*>(this->poolSize);
	for (int i = 0; i < this->poolSize; i++) {
		threadVector[i] = new thread(&threadPool::threadRun, this);
	}
}

void threadPool::entry(Task* task) {
	task->runTask();
}

void threadPool::threadRun() {
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

void threadPool::LogDebug(LogLevel traceLevel, const char* format, ...) {
	if (this->logLevel >= traceLevel) {
		va_list va;
		va_start(va, format);
		printf("%s %s %s:%u:\t", __DATE__, __TIME__, __FILE__, __LINE__);
		vprintf(format, va);
		va_end(va);
		printf("\n");
	}
}

void threadPool::printError(ErrorType errorType, const char* format, ...) {
	va_list va;
	va_start(va, format);
	printf("%s %s %s:%u:\t", __DATE__, __TIME__, __FILE__, __LINE__);
	printf("Fatal error occured: %s\t", ErrorTypeMsg[errorType].c_str());
	vprintf(format, va);
	va_end(va);
	printf("\n");
}
