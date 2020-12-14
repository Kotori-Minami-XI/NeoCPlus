#include "StringBuilder.h"

static void testStringBuilderUnion();
static bool testStringBuilderInit();

/*********************************************************************
 * 函数名称：testStringBuilderUnion
 * 函数功能：StringBuilder的测试集合
 * 输入参数：None
 * 返回参数：void
 * 输出结果：未抛出异常，返回true
 *********************************************************************/
static void testStringBuilderUnion() {
	if (!testStringBuilderInit()) {
		throw new exception("testStringBuilderInit failed!");
	}
}


/*********************************************************************
 * 函数名称：testStringBuilderInit
 * 函数功能：测试StringBuilder是否能正常初始化
 * 输入参数：None
 * 返回参数：bool
 * 输出结果：未抛出异常，返回true
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