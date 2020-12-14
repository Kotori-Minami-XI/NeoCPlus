#include "StringBuilder.h"

static void testStringBuilderUnion();
static bool testStringBuilderInit();

/*********************************************************************
 * �������ƣ�testStringBuilderUnion
 * �������ܣ�StringBuilder�Ĳ��Լ���
 * ���������None
 * ���ز�����void
 * ��������δ�׳��쳣������true
 *********************************************************************/
static void testStringBuilderUnion() {
	if (!testStringBuilderInit()) {
		throw new exception("testStringBuilderInit failed!");
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
	StringBuilder* sb1 = new StringBuilder();
	sb1->append("123");
	sb1->append("456");
	StringBuilder::printStringBuilder(*sb1);
	string exp1 = "123456";
	if (sb1->toString() != exp1) {
		delete(sb1);
		return false;
	}
	delete(sb1);
	
	StringBuilder* sb2 = new StringBuilder("123");
	sb2->append("456");
	sb2->append("789");
	StringBuilder::printStringBuilder(*sb2);
	string exp2 = "123456789";
	if (sb2->toString() != exp2) {
		delete(sb2);
		return false;
	}
	delete(sb2);

	return true;
}

int main() {
	//testStringBuilderUnion();

	StringBuilder* sb1 = new StringBuilder();
	sb1->append("123");
	sb1->append("456");
	StringBuilder::printStringBuilder(*sb1);

	sb1->deleteCharAt(3);
	StringBuilder::printStringBuilder(*sb1);

	delete(sb1);


}