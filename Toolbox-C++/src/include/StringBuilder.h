#ifndef STRING_BUILDER_H
#define STRING_BUILDER_H

#include <iostream>
#include <list>
#include <mutex>

using namespace std;

class StringBuilder
{
public:
	StringBuilder() {
		init();
	}

	StringBuilder(const string &str) {
		init();
		this->append(str);
	}

	StringBuilder& reverse() {
		for (auto it = this->entityList->begin(); it != this->entityList->end(); it++) {
			it->reserve();
		}
		entityList->reverse();
		return *this;
	}

	StringBuilder& append(const string& str) {
		string fragment = string(str);
		this->entityList->push_back(fragment);
		this->totalLenth += (unsigned int)str.length();
		return *this;
	}

	StringBuilder& insert(unsigned int index, const string& str) {

		string fragment = string(str);

		return *this;
	}

	StringBuilder& setCharAt(unsigned int index, const char& ch) {

	}

	StringBuilder& deleteCharAt(unsigned int index) {
		if (index >= this->totalLenth) {
			throw new exception("index should not be larger than total length of str!");
		}
		list<string>::iterator it = this->entityList->begin();
		unsigned int subIndex = this->locateIteratorByIndex(index, it);

		if (it->length() == 1) {
			this->entityList->erase(it);
		}
		else {
			it->erase(subIndex, 1);
			this->totalLenth--;
		}
		return *this;
	}

	StringBuilder& deleteStr(unsigned int index, unsigned int delLength) {
		unsigned int charCount = delLength;
		if (index + delLength > this->totalLenth) {
			throw new exception("The string that is about to be deleted is out of range!");
		}
		list<string>::iterator it = this->entityList->begin();
		unsigned int subIndex = this->locateIteratorByIndex(index, it);

		while (delLength > 0) {
			cout << subIndex << endl;
			if (delLength >= it->length() - subIndex) {
				delLength -= it->length() - subIndex;
				subIndex = 0;
				it = this->entityList->erase(it);
			}
			else {
				it->erase(subIndex, delLength);
				delLength = 0;
			}
		}
		this->totalLenth -= charCount;
		return *this;
	}

	string toString() {
		string str = "";
		for (auto it = this->entityList->begin(); it != this->entityList->end(); it++) {
			str = str + *it;
		}
		return str;
	}

	static void printStringBuilder(StringBuilder& sb) {
		for (auto it = sb.entityList->begin(); it != sb.entityList->end(); it++) {
			cout << *it;
		}
		cout << endl;
	}
private:
	list<string>* entityList;
	bool isEntityInitialized = false;
	unsigned int totalLenth;

	//禁止拷贝构造 与 赋值操作
	StringBuilder(const StringBuilder&) {}
	StringBuilder& operator= (const StringBuilder&) {}

	void init() {
		if (!this->isEntityInitialized) {
			entityList = new list<string>();
		}
		else {
			return;
		}
		this->totalLenth = 0;
		this->isEntityInitialized = true;
	}

	unsigned int locateIteratorByIndex(unsigned int index, list<string>::iterator &it) {
		it = this->entityList->begin();

		unsigned int currentStrIndex = 0;
		while (index > 0) {
			currentStrIndex++;
			if (currentStrIndex == it->length()) {
				it++;
				currentStrIndex = 0;
			}
			index--;
		}
		return currentStrIndex;
	}

};


#endif /* STRING_BUILDER_H */
