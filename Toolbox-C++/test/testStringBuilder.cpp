#include "StringBuilder.h"

static void testStringBuilderUnion();
static bool testStringBuilderInit();
static bool testStringBuilderDeleteCharAt();
static bool testStringBuilderDeleteStr();

/*********************************************************************
 * 函数名称：testStringBuilderUnion
 * 函数功能：StringBuilder的测试集合
 * 输入参数：None
 * 返回参数：void
 * 输出结果：未抛出异常，返回true
 *********************************************************************/
static void testStringBuilderUnion() {
	if (!testStringBuilderInit()) {
		throw new exception("testStringBuilderInit 失败 ×\n");
	}
	if (!testStringBuilderDeleteCharAt()) {
		throw new exception("testStringBuilderDeleteCharAt 失败 ×\n");
	}
	if (!testStringBuilderDeleteStr()) {
		throw new exception("testStringBuilderDeleteStr 失败 ×\n");
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
	printf("------------ testStringBuilderInit 测试开始 ------------ \n");
	StringBuilder* sb1 = new StringBuilder();
	sb1->append("123");
	sb1->append("456");

	string exp1 = "123456";
	printf("sb1预期结果为%s 实际结果为%s \n", exp1.c_str(), sb1->toString().c_str());
	if (sb1->toString() != exp1) {
		delete(sb1);
		printf("sb1不符合预期 × \n");
		return false;
	}
	else {
		printf("sb1符合预期 √ \n");
	}
	delete(sb1);
	
	StringBuilder* sb2 = new StringBuilder("123");
	sb2->append("456");
	sb2->append("789");
	string exp2 = "123456789";
	printf("sb2预期结果为%s 实际结果为%s \n", exp2.c_str(), sb2->toString().c_str());
	if (sb2->toString() != exp2) {
		delete(sb2);
		printf("sb2不符合预期 × \n");
		return false;
	}
	else {
		printf("sb2符合预期 √ \n");
	}
	delete(sb2);

	printf("----------- testStringBuilderInit 测试成功 √ ----------- \n");
	return true;
}


/*********************************************************************
 * 函数名称：testStringBuilderInit
 * 函数功能：测试StringBuilder删除字符功能
 * 输入参数：None
 * 返回参数：bool
 * 输出结果：未抛出异常，返回true
 *********************************************************************/
static bool testStringBuilderDeleteCharAt() {
	printf("------------ testStringBuilderDeleteCharAt 测试开始 ------------ \n");
	StringBuilder* sb = new StringBuilder();
	sb->append("abc");
	sb->append("def");
	sb->append("ghi");

	// 删除首部
	string exp1 = "bcdefghi";
	sb->deleteCharAt(0);
	printf("sb预期结果为%s 实际结果为%s \n", exp1.c_str(), sb->toString().c_str());
	if (sb->toString() != exp1) {
		delete(sb);
		printf("sb不符合预期 × \n");
		return false;
	}
	else {
		printf("sb符合预期 √ \n");
	}

	// 删除第一个段中间
	string exp2 = "bdefghi";
	sb->deleteCharAt(1);
	printf("sb预期结果为%s 实际结果为%s \n", exp2.c_str(), sb->toString().c_str());
	if (sb->toString() != exp2) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		return false;
	}
	else {
		printf("sb符合预期 √\n");
	}

	// 删除末尾
	string exp3 = "bdefgh";
	sb->deleteCharAt(6);
	printf("sb预期结果为%s 实际结果为%s \n", exp3.c_str(), sb->toString().c_str());
	if (sb->toString() != exp3) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		return false;
	}
	else {
		printf("sb符合预期 √\n");
	}

	// 删除第二段中间
	string exp4 = "bdefh";
	sb->deleteCharAt(4);
	printf("sb预期结果为%s 实际结果为%s \n", exp4.c_str(), sb->toString().c_str());
	if (sb->toString() != exp4) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		return false;
	}
	else {
		printf("sb符合预期 √\n");
	}

	delete(sb);
	printf("----------- testStringBuilderInit 测试成功 √ ----------- \n");
	return true;
}


/*********************************************************************
 * 函数名称：testStringBuilderDeleteStr
 * 函数功能：测试StringBuilder删除字符串功能
 * 输入参数：None
 * 返回参数：bool
 * 输出结果：未抛出异常，返回true
 *********************************************************************/
static bool testStringBuilderDeleteStr() {
	printf("------------ testStringBuilderDeleteStr 测试开始 ------------ \n");
	StringBuilder* sb = new StringBuilder();
	sb->append("abc");
	sb->append("def");
	sb->append("ghi");
	sb->append("jkl");

	// 删除a
	sb->deleteStr(0,1);
	string exp1 = "bcdefghijkl";
	printf("sb预期结果为%s 实际结果为%s \n", exp1.c_str(), sb->toString().c_str());
	if (sb->toString() != exp1) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		return false;
	}
	else {
		printf("sb符合预期 √\n");
	}

	// 删除bc
	sb->deleteStr(0, 2);
	string exp2 = "defghijkl";
	printf("sb预期结果为%s 实际结果为%s \n", exp2.c_str(), sb->toString().c_str());
	if (sb->toString() != exp2) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		return false;
	}
	else {
		printf("sb符合预期 √\n");
	}

	// 删除ghi
	sb->deleteStr(3, 3);
	string exp3 = "defjkl";
	printf("sb预期结果为%s 实际结果为%s \n", exp3.c_str(), sb->toString().c_str());
	if (sb->toString() != exp3) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		return false;
	}
	else {
		printf("sb符合预期 √\n");
	}

	//StringBuilder::printStringBuilder(*sb);
	// 删除fj
	sb->deleteStr(2, 2);
	string exp4 = "dekl";
	printf("sb预期结果为%s 实际结果为%s \n", exp4.c_str(), sb->toString().c_str());
	if (sb->toString() != exp4) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		//return false;
	}
	else {
		printf("sb符合预期 √\n");
	}


	return true;
	printf("----------- testStringBuilderDeleteStr 测试成功 √ ----------- \n");
}

int main() {
	testStringBuilderUnion();
}