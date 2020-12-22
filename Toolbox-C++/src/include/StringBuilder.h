#ifndef STRING_BUILDER_H
#define STRING_BUILDER_H

#include <assert.h>
#include <iostream>
#include <list>
#include <vector>
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
		this->entityList->push_back(str);
		this->totalLenth += (unsigned int)str.length();
		return *this;
	}

	StringBuilder& insert(unsigned int index, const string& str) {
		unsigned int currentTotalLength = this->totalLenth;
		if (index > this->totalLenth) {
			throw new exception("param error: index should not be larger than total length of str!");
		}
		else if (index == this->totalLenth) {
			this->entityList->push_back(str);
			this->totalLenth += (unsigned int)str.length();
		}
		else {
			list<string>::iterator it = this->entityList->begin();
			unsigned int subIndex = this->locateByIndex(index, it);

			if (subIndex == 0) {
				this->entityList->insert(it, str);
				this->totalLenth += (unsigned int)str.length();
			}
			else {
				string remains = string(it->begin() + subIndex, it->end());
				it->erase(subIndex);
				this->totalLenth -= (unsigned int)remains.length();
				it++;

				this->entityList->insert(it, str);
				this->totalLenth += (unsigned int)str.length();

				this->entityList->insert(it, remains);
				this->totalLenth += (unsigned int)remains.length();
			}
		}

		assert(currentTotalLength + str.length() == this->totalLenth);

		return *this;
	}

	StringBuilder& replace(unsigned int index, unsigned int len, const string& str) {
		if (index > this->totalLenth) {
			throw new exception("param error: index should not be larger than total length of str!");
		}
		this->deleteStr(index, len);
		this->insert(index, str);
		return *this;
	}

	StringBuilder& deleteCharAt(unsigned int index) {
		if (index >= this->totalLenth) {
			throw new exception("param error: index should not be larger than total length of str!");
		}
		list<string>::iterator it = this->entityList->begin();
		unsigned int subIndex = this->locateByIndex(index, it);

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
		if (0 == delLength) {
			throw new exception("param error: the length of deleted string cannot be 0!");
		}

		unsigned int charCount = 0;
		unsigned int expCount = delLength;
		if (index + delLength > this->totalLenth) {
			throw new exception("param error: The string that is about to be deleted is out of range!");
		}
		list<string>::iterator it = this->entityList->begin();
		unsigned int subIndex = this->locateByIndex(index, it);

		while (delLength > 0) {
			if (subIndex == 0) {
				if (delLength >= it->length()) {
					delLength -= (unsigned int)it->length();
					charCount += (unsigned int)it->length();
					it = this->entityList->erase(it);
				}
				else {
					charCount += delLength;
					it->erase(subIndex, delLength);
					delLength = 0;
					subIndex = 0;
				}
			}
			else {
				if (delLength >= (unsigned int)it->length() - subIndex) {
					delLength -= (unsigned int)it->length() - subIndex;
					charCount += (unsigned int)it->length() - subIndex;
					it->erase(subIndex);
					subIndex = 0;
					it++;
				}
				else {
					charCount += delLength;
					it->erase(subIndex, delLength);
					delLength = 0;
				}
			}
		}

		assert(charCount == expCount);

		this->totalLenth -= charCount;
		return *this;
	}

	// TODO: Finish this one
	vector<StringBuilder> split(const string &symbol) {
		vector<StringBuilder> res;
		if ("" == symbol) {
			return res;
		}
		list<string>::iterator frontIter = this->entityList->begin();
		list<string>::iterator backIter = this->entityList->begin();
		while (backIter != this->entityList->end() && (*backIter).find(symbol) == -1) {
			backIter++;
		}
		return res;
	}

	string toString() {
		string str = "";
		for (auto it = this->entityList->begin(); it != this->entityList->end(); it++) {
			str = str + *it;
		}
		return str;
	}

	unsigned int getTotalLenth() {
		return this->totalLenth;
	}

	static void printStringBuilder(StringBuilder& sb) {
		for (auto it = sb.entityList->begin(); it != sb.entityList->end(); it++) {
			cout << *it;
		}
		cout << endl;
	}

private:
	list<string>* entityList;
	unsigned int totalLenth;
	bool isEntityInitialized = false;


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

	unsigned int locateByIndex(unsigned int index, list<string>::iterator &it) {
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
