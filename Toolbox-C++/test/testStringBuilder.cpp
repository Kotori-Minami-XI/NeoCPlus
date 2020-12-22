#include "StringBuilder.h"

static void testStringBuilderUnion();
static bool testStringBuilderInit();
static bool testStringBuilderDeleteCharAt();
static bool testStringBuilderDeleteStr();
static bool testStringBuilderInsert(); 
static bool testStringBuilderReplace();
static bool testStringBuilderSplit();
static bool testPerformanceAppend();
static bool testPerformanceInsertHead();


/*********************************************************************
 * �������ƣ�testStringBuilderUnion
 * �������ܣ�StringBuilder�Ĳ��Լ���
 * ���������None
 * ���ز�����void
 * ��������δ�׳��쳣������true
 *********************************************************************/
static void testStringBuilderUnion() {
	printf("\n *********** ³���Բ��Կ�ʼ *********** \n");
	if (!testStringBuilderInit()) {
		throw new exception("testStringBuilderInit ʧ�� ��\n");
	}
	if (!testStringBuilderDeleteCharAt()) {
		throw new exception("testStringBuilderDeleteCharAt ʧ�� ��\n");
	}
	if (!testStringBuilderDeleteStr()) {
		throw new exception("testStringBuilderDeleteStr ʧ�� ��\n");
	}
	if (!testStringBuilderInsert()) {
		throw new exception("testStringBuilderInsert ʧ�� ��\n");
	}
	if (!testStringBuilderReplace()) {
		throw new exception("testStringBuilderReplace ʧ�� ��\n");
	}
	if (!testStringBuilderSplit()) {
		throw new exception("testStringBuilderSplit ʧ�� ��\n");
	}
}


/*********************************************************************
 * �������ƣ�testStringBuilderInit
 * �������ܣ�����StringBuilder�Ƿ���������ʼ��
 * ���������None
 * ���ز�����bool
 * ��������δ�׳��쳣������true
 *********************************************************************/
static bool testStringBuilderInit() {
	printf("------------ testStringBuilderInit ���Կ�ʼ ------------ \n");
	StringBuilder* sb1 = new StringBuilder();
	string exp;
	sb1->append("123");
	sb1->append("456");

	exp = "123456";
	printf("sb1Ԥ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb1->toString().c_str());
	if (sb1->toString() != exp) {
		delete(sb1);
		printf("sb1������Ԥ�� �� \n");
		return false;
	}
	else {
		printf("sb1����Ԥ�� �� \n");
	}
	delete(sb1);
	
	StringBuilder* sb2 = new StringBuilder("123");
	sb2->append("456");
	sb2->append("789");
	exp = "123456789";
	printf("sb2Ԥ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb2->toString().c_str());
	if (sb2->toString() != exp) {
		delete(sb2);
		printf("sb2������Ԥ�� �� \n");
		return false;
	}
	else {
		printf("sb2����Ԥ�� �� \n");
	}
	delete(sb2);

	printf("----------- testStringBuilderInit ���Գɹ� �� ----------- \n");
	return true;
}


/*********************************************************************
 * �������ƣ�testStringBuilderInit
 * �������ܣ�����StringBuilderɾ���ַ�����
 * ���������None
 * ���ز�����bool
 * ��������δ�׳��쳣������true
 *********************************************************************/
static bool testStringBuilderDeleteCharAt() {
	printf("------------ testStringBuilderDeleteCharAt ���Կ�ʼ ------------ \n");
	StringBuilder* sb = new StringBuilder();
	string exp;
	sb->append("abc");
	sb->append("def");
	sb->append("ghi");

	// ɾ���ײ�
	exp = "bcdefghi";
	sb->deleteCharAt(0);
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� �� \n");
		return false;
	}
	else {
		printf("sb����Ԥ�� �� \n");
	}

	// ɾ����һ�����м�
	exp = "bdefghi";
	sb->deleteCharAt(1);
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	// ɾ��ĩβ
	exp = "bdefgh";
	sb->deleteCharAt(6);
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	// ɾ���ڶ����м�
	exp = "bdefh";
	sb->deleteCharAt(4);
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	delete(sb);
	printf("----------- testStringBuilderInit ���Գɹ� �� ----------- \n");
	return true;
}


/*********************************************************************
 * �������ƣ�testStringBuilderDeleteStr
 * �������ܣ�����StringBuilderɾ���ַ�������
 * ���������None
 * ���ز�����bool
 * ��������δ�׳��쳣������true
 *********************************************************************/
static bool testStringBuilderDeleteStr() {
	printf("------------ testStringBuilderDeleteStr ���Կ�ʼ ------------ \n");
	StringBuilder* sb = new StringBuilder();
	string exp;
	sb->append("abc");
	sb->append("def");
	sb->append("ghi");
	sb->append("jkl");

	// ɾ��a
	sb->deleteStr(0,1);
	exp = "bcdefghijkl";
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	// ɾ��bc
	sb->deleteStr(0, 2);
	exp = "defghijkl";
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	// ɾ��ghi
	sb->deleteStr(3, 3);
	exp = "defjkl";
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	// ɾ��fj
	sb->deleteStr(2, 2);
	exp = "dekl";
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	// ɾ��ek
	sb->deleteStr(1, 2);
	exp = "dl";
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	// ɾ��dl
	sb->deleteStr(0, 2);
	exp = "";
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	return true;
	printf("----------- testStringBuilderDeleteStr ���Գɹ� �� ----------- \n");
}


/*********************************************************************
 * �������ƣ�testStringBuilderInsert
 * �������ܣ�����StringBuilder����ַ�������
 * ���������None
 * ���ز�����bool
 * ��������δ�׳��쳣������true
 *********************************************************************/
static bool testStringBuilderInsert() {
	printf("------------ testStringBuilderInsert ���Կ�ʼ ------------ \n");
	StringBuilder* sb = new StringBuilder();
	string exp;

	// ͷ����� ab
	sb->insert(0 , "ab");
	exp = "ab";
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	// β����� ef
	sb->insert(2, "ef");
	exp = "abef";
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	// �в���� cd
	sb->insert(2, "cd");
	exp = "abcdef";
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	// �в���� cd
	sb->insert(4, "ee");
	exp = "abcdeeef";
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	printf("----------- testStringBuilderInsert ���Գɹ� �� ----------- \n");
	return true;
}


/*********************************************************************
 * �������ƣ�testStringBuilderReplace
 * �������ܣ�����StringBuilder�滻�ַ�������
 * ���������None
 * ���ز�����bool
 * ��������δ�׳��쳣������true
 *********************************************************************/
static bool testStringBuilderReplace() {
	printf("------------ testStringBuilderReplace ���Կ�ʼ ------------ \n");
	StringBuilder* sb = new StringBuilder();
	string exp;
	sb->insert(0, "123456");

	// �滻ͷ�� ���ȳ��ȣ�
	exp = "ab3456";
	sb->replace(0, 2, "ab");
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	// �滻β�� ���ȳ��ȣ�
	exp = "ab34ef";
	sb->replace(4, 2, "ef");
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	// �滻�м� ���ȳ��ȣ�
	exp = "abcdef";
	sb->replace(2, 2, "cd");
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	// �滻ͷ�� ���������ַ�����
	exp = "123def";
	sb->replace(0, 3, "123");
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	// �滻ͷ�� ���������ַ�����
	exp = "aabbccdef";
	sb->replace(0, 3, "aabbcc");
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

    // �滻β�� ���������ַ�����
	exp = "aabbccdeddd";
	sb->replace(8, 1, "ddd");
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	// �滻�м� ���������ַ�����
	exp = "aabbcceeeeddd";
	sb->replace(6, 1, "eee");
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	// �滻ͷ�� �����̵��ַ�����
	exp = "cccceeeeddd";
	sb->replace(0, 4, "cc");
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	// �滻β�� �����̵��ַ�����
	exp = "cccceeeedaa";
	sb->replace(9, 2, "aa");
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	// �滻�м� �����̵��ַ�����
	exp = "ccccaadaa";
	sb->replace(4, 4, "aa");
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	printf("----------- testStringBuilderReplace ���Գɹ� �� ----------- \n");
	return true;
}


/*********************************************************************
 * �������ƣ�testStringBuilderSplit
 * �������ܣ�����StringBuilder�ָ��ַ�������
 * ���������None
 * ���ز�����bool
 * ��������δ�׳��쳣������true
 *********************************************************************/
bool testStringBuilderSplit() {
	printf("------------ testStringBuilderSplit ���Կ�ʼ ------------ \n");



	printf("----------- testStringBuilderSplit ���Գɹ� �� ----------- \n");
	return true;
}


/*********************************************************************
 * �������ƣ�testPerformanceAppend
 * �������ܣ�����StringBuilder��string��Append�ϵ����ܲ��
 * ���������None
 * ���ز�����bool
 * ��������δ�׳��쳣������true
 *********************************************************************/
static bool testPerformanceAppend() {
	printf("----------- testPerformanceAppend  ----------- \n");
	string *str = new string("");
	StringBuilder* sb = new StringBuilder("");
	long long numOfIterations = 1000000;

    clock_t t1 = clock();
	// string��append
	for (int i = 0; i < numOfIterations; i++) {
		str->append("a");
	}
	clock_t t2 = clock();
	// StringBuilder��append
	for (int i = 0; i < numOfIterations; i++) {
		sb->append("a");
	}
	clock_t t3 = clock();

	long double stringClock = (long double)(t2 - t1);
	long double stringBuilderClock = (long double)(t3 - t2);

	printf("string��append���� %lf CLOCKS, StringBuilder��append���� %lf CLOCKS\n", 
		stringClock, stringBuilderClock);
	printf("string��append���� %lf seconds, StringBuilder��append���� %lf seconds\n",
		stringClock / CLOCKS_PER_SEC, stringBuilderClock / CLOCKS_PER_SEC);
	printf("StringBuilder��ͷ��Insert���ܴ�Լ��string��Insert���ܵ� %lf %% \n", 100 / (stringBuilderClock / stringClock));

	printf("----------- testPerformanceAppend ���Գɹ� �� ----------- \n");
	return true;
}


/*********************************************************************
 * �������ƣ�testPerformanceInsertHead
 * �������ܣ�����StringBuilder��string��ͷ��Insert�ϵ����ܲ��
 * ���������None
 * ���ز�����bool
 * ��������δ�׳��쳣������true
 *********************************************************************/
static bool testPerformanceInsertHead() {
	printf("----------- testPerformanceInsertHead  ----------- \n");
	string* str = new string("aaaaaaaaaaa");
	StringBuilder* sb = new StringBuilder("aaaaaaaaaaa");
	long long numOfIterations = 1000000;

	clock_t t1 = clock();
	// string��append
	for (int i = 0; i < numOfIterations; i++) {
		str->insert(0, "a");
	}
	clock_t t2 = clock();
	// StringBuilder��append
	for (int i = 0; i < numOfIterations; i++) {
		sb->insert(0, "a");
	}
	clock_t t3 = clock();

	long double stringClock = (long double)(t2 - t1);
	long double stringBuilderClock = (long double)(t3 - t2);

	printf("string��ͷ��Insert���� %lf CLOCKS, StringBuilder��Insert���� %lf CLOCKS\n",
		stringClock, stringBuilderClock);
	printf("string��ͷ��Insert���� %lf seconds, StringBuilder��Insert���� %lf seconds\n",
		stringClock / CLOCKS_PER_SEC, stringBuilderClock / CLOCKS_PER_SEC);
	printf("StringBuilder��ͷ��Insert���ܴ�Լ��string��Insert���ܵ� %lf %% \n", 100 / (stringBuilderClock / stringClock));

	printf("----------- testPerformanceInsertHead ���Գɹ� �� ----------- \n");
	return true;
}


/*********************************************************************
 * �������ƣ�testPerformanceInsertMeddle
 * �������ܣ�����StringBuilder��string���м�Insert�ϵ����ܲ��
 * ���������None
 * ���ز�����bool
 * ��������δ�׳��쳣������true
 *********************************************************************/
static bool testPerformanceInsertMeddle() {
	printf("----------- testPerformanceInsertMeddle  ----------- \n");
	string* str = new string("aaaaaaaaaa");
	StringBuilder* sb = new StringBuilder("aaaaaaaaaa");
	long long numOfIterations = 10000;

	clock_t t1 = clock();
	// string��append
	for (int i = 0; i < numOfIterations; i++) {
		str->insert(7, "a");
	}
	clock_t t2 = clock();
	// StringBuilder��append
	for (int i = 0; i < numOfIterations; i++) {
		sb->insert(7, "a");
	}
	clock_t t3 = clock();

	long double stringClock = (long double)(t2 - t1);
	long double stringBuilderClock = (long double)(t3 - t2);

	printf("string���м�Insert���� %lf CLOCKS, StringBuilder��Insert���� %lf CLOCKS\n",
		stringClock, stringBuilderClock);
	printf("string���м�Insert���� %lf seconds, StringBuilder��Insert���� %lf seconds\n",
		stringClock / CLOCKS_PER_SEC, stringBuilderClock / CLOCKS_PER_SEC);
	printf("StringBuilder��ͷ��Insert���ܴ�Լ��string��Insert���ܵ� %lf %% \n", 100 / (stringBuilderClock / stringClock));

	printf("----------- testPerformanceInsertMeddle ���Գɹ� �� ----------- \n");
	return true;
}

int main() {
	testStringBuilderUnion();

	printf("\n *********** ���ܲ��Կ�ʼ *********** \n");
	testPerformanceAppend();
	testPerformanceInsertHead();
	testPerformanceInsertMeddle();
}