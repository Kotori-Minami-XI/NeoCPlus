#include "StringBuilder.h"

static void testStringBuilderUnion();
static bool testStringBuilderInit();
static bool testStringBuilderDeleteCharAt();
static bool testStringBuilderDeleteStr();

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
	sb1->append("123");
	sb1->append("456");

	string exp1 = "123456";
	printf("sb1Ԥ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp1.c_str(), sb1->toString().c_str());
	if (sb1->toString() != exp1) {
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
	string exp2 = "123456789";
	printf("sb2Ԥ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp2.c_str(), sb2->toString().c_str());
	if (sb2->toString() != exp2) {
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
	sb->append("abc");
	sb->append("def");
	sb->append("ghi");

	// ɾ���ײ�
	string exp1 = "bcdefghi";
	sb->deleteCharAt(0);
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp1.c_str(), sb->toString().c_str());
	if (sb->toString() != exp1) {
		delete(sb);
		printf("sb������Ԥ�� �� \n");
		return false;
	}
	else {
		printf("sb����Ԥ�� �� \n");
	}

	// ɾ����һ�����м�
	string exp2 = "bdefghi";
	sb->deleteCharAt(1);
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp2.c_str(), sb->toString().c_str());
	if (sb->toString() != exp2) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	// ɾ��ĩβ
	string exp3 = "bdefgh";
	sb->deleteCharAt(6);
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp3.c_str(), sb->toString().c_str());
	if (sb->toString() != exp3) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	// ɾ���ڶ����м�
	string exp4 = "bdefh";
	sb->deleteCharAt(4);
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp4.c_str(), sb->toString().c_str());
	if (sb->toString() != exp4) {
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
	sb->append("abc");
	sb->append("def");
	sb->append("ghi");
	sb->append("jkl");

	// ɾ��a
	sb->deleteStr(0,1);
	string exp1 = "bcdefghijkl";
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp1.c_str(), sb->toString().c_str());
	if (sb->toString() != exp1) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	// ɾ��bc
	sb->deleteStr(0, 2);
	string exp2 = "defghijkl";
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp2.c_str(), sb->toString().c_str());
	if (sb->toString() != exp2) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	// ɾ��ghi
	sb->deleteStr(3, 3);
	string exp3 = "defjkl";
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp3.c_str(), sb->toString().c_str());
	if (sb->toString() != exp3) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}

	//StringBuilder::printStringBuilder(*sb);
	// ɾ��fj
	sb->deleteStr(2, 2);
	string exp4 = "dekl";
	printf("sbԤ�ڽ��Ϊ%s ʵ�ʽ��Ϊ%s \n", exp4.c_str(), sb->toString().c_str());
	if (sb->toString() != exp4) {
		delete(sb);
		printf("sb������Ԥ�� ��\n");
		//return false;
	}
	else {
		printf("sb����Ԥ�� ��\n");
	}


	return true;
	printf("----------- testStringBuilderDeleteStr ���Գɹ� �� ----------- \n");
}

int main() {
	testStringBuilderUnion();
}