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
		list<string>::iterator it = this->entityList->begin();
		unsigned int subIndex = this->getIteratorByIndex(index, it);
		it->erase(subIndex, 1);
		this->totalLenth--;
		cout << *it <<endl;
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

	unsigned int getIteratorByIndex(unsigned int index, list<string>::iterator &it) {
		if (index > this->totalLenth) {
			throw new exception("index should not be larger than total length of str!");
		}

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
