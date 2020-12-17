#include "StringBuilder.h"

static void testStringBuilderUnion();
static bool testStringBuilderInit();
static bool testStringBuilderDeleteCharAt();
static bool testStringBuilderDeleteStr();
static bool testStringBuilderInsert(); 
static bool testStringBuilderReplace();
static bool testStringBuilderSplit();

/*********************************************************************
 * �������ƣ�testStringBuilderUnion
 * �������ܣ�StringBuilder�Ĳ��Լ���
 * ���������None
 * ���ز�����void
 * ��������δ�׳��쳣������true
 *********************************************************************/
static void testStringBuilderUnion() {
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
	exp = "123cdef";
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
    // �滻ͷ�� ���������ַ�����

	// �滻ͷ�� �����̵��ַ�����
	// �滻ͷ�� �����̵��ַ�����
	// �滻ͷ�� �����̵��ַ�����


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


void test() {
	//string a = "123";
//clock_t  t1 = clock();

//for (int i = 0; i < 1000000; i++) {
//	//a.insert(0,"a");
//	a.append("a");
//}
//clock_t  t2 = clock();
//cout << (long double)(t2 - t1) / CLOCKS_PER_SEC << endl;
}




int main() {
	testStringBuilderUnion();
}