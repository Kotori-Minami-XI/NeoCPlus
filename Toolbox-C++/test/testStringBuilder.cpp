#include "StringBuilder.h"

static void testStringBuilderUnion();
static bool testStringBuilderInit();
static bool testStringBuilderDeleteCharAt();
static bool testStringBuilderDeleteStr();
static bool testStringBuilderInsert(); 
static bool testStringBuilderReplace();
static bool testStringBuilderSplit();

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
	if (!testStringBuilderInsert()) {
		throw new exception("testStringBuilderInsert 失败 ×\n");
	}
	if (!testStringBuilderReplace()) {
		throw new exception("testStringBuilderReplace 失败 ×\n");
	}
	if (!testStringBuilderSplit()) {
		throw new exception("testStringBuilderSplit 失败 ×\n");
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
	string exp;
	sb1->append("123");
	sb1->append("456");

	exp = "123456";
	printf("sb1预期结果为%s 实际结果为%s \n", exp.c_str(), sb1->toString().c_str());
	if (sb1->toString() != exp) {
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
	exp = "123456789";
	printf("sb2预期结果为%s 实际结果为%s \n", exp.c_str(), sb2->toString().c_str());
	if (sb2->toString() != exp) {
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
	string exp;
	sb->append("abc");
	sb->append("def");
	sb->append("ghi");

	// 删除首部
	exp = "bcdefghi";
	sb->deleteCharAt(0);
	printf("sb预期结果为%s 实际结果为%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb不符合预期 × \n");
		return false;
	}
	else {
		printf("sb符合预期 √ \n");
	}

	// 删除第一个段中间
	exp = "bdefghi";
	sb->deleteCharAt(1);
	printf("sb预期结果为%s 实际结果为%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		return false;
	}
	else {
		printf("sb符合预期 √\n");
	}

	// 删除末尾
	exp = "bdefgh";
	sb->deleteCharAt(6);
	printf("sb预期结果为%s 实际结果为%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		return false;
	}
	else {
		printf("sb符合预期 √\n");
	}

	// 删除第二段中间
	exp = "bdefh";
	sb->deleteCharAt(4);
	printf("sb预期结果为%s 实际结果为%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
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
	string exp;
	sb->append("abc");
	sb->append("def");
	sb->append("ghi");
	sb->append("jkl");

	// 删除a
	sb->deleteStr(0,1);
	exp = "bcdefghijkl";
	printf("sb预期结果为%s 实际结果为%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		return false;
	}
	else {
		printf("sb符合预期 √\n");
	}

	// 删除bc
	sb->deleteStr(0, 2);
	exp = "defghijkl";
	printf("sb预期结果为%s 实际结果为%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		return false;
	}
	else {
		printf("sb符合预期 √\n");
	}

	// 删除ghi
	sb->deleteStr(3, 3);
	exp = "defjkl";
	printf("sb预期结果为%s 实际结果为%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		return false;
	}
	else {
		printf("sb符合预期 √\n");
	}

	// 删除fj
	sb->deleteStr(2, 2);
	exp = "dekl";
	printf("sb预期结果为%s 实际结果为%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		return false;
	}
	else {
		printf("sb符合预期 √\n");
	}

	// 删除ek
	sb->deleteStr(1, 2);
	exp = "dl";
	printf("sb预期结果为%s 实际结果为%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		return false;
	}
	else {
		printf("sb符合预期 √\n");
	}

	// 删除dl
	sb->deleteStr(0, 2);
	exp = "";
	printf("sb预期结果为%s 实际结果为%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		return false;
	}
	else {
		printf("sb符合预期 √\n");
	}

	return true;
	printf("----------- testStringBuilderDeleteStr 测试成功 √ ----------- \n");
}


/*********************************************************************
 * 函数名称：testStringBuilderInsert
 * 函数功能：测试StringBuilder添加字符串功能
 * 输入参数：None
 * 返回参数：bool
 * 输出结果：未抛出异常，返回true
 *********************************************************************/
static bool testStringBuilderInsert() {
	printf("------------ testStringBuilderInsert 测试开始 ------------ \n");
	StringBuilder* sb = new StringBuilder();
	string exp;

	// 头部添加 ab
	sb->insert(0 , "ab");
	exp = "ab";
	printf("sb预期结果为%s 实际结果为%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		return false;
	}
	else {
		printf("sb符合预期 √\n");
	}

	// 尾部添加 ef
	sb->insert(2, "ef");
	exp = "abef";
	printf("sb预期结果为%s 实际结果为%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		return false;
	}
	else {
		printf("sb符合预期 √\n");
	}

	// 中部添加 cd
	sb->insert(2, "cd");
	exp = "abcdef";
	printf("sb预期结果为%s 实际结果为%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		return false;
	}
	else {
		printf("sb符合预期 √\n");
	}

	// 中部添加 cd
	sb->insert(4, "ee");
	exp = "abcdeeef";
	printf("sb预期结果为%s 实际结果为%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		return false;
	}
	else {
		printf("sb符合预期 √\n");
	}

	printf("----------- testStringBuilderInsert 测试成功 √ ----------- \n");
	return true;
}


/*********************************************************************
 * 函数名称：testStringBuilderReplace
 * 函数功能：测试StringBuilder替换字符串功能
 * 输入参数：None
 * 返回参数：bool
 * 输出结果：未抛出异常，返回true
 *********************************************************************/
static bool testStringBuilderReplace() {
	printf("------------ testStringBuilderReplace 测试开始 ------------ \n");
	StringBuilder* sb = new StringBuilder();
	string exp;
	sb->insert(0, "123456");

	// 替换头部 （等长度）
	exp = "ab3456";
	sb->replace(0, 2, "ab");
	printf("sb预期结果为%s 实际结果为%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		return false;
	}
	else {
		printf("sb符合预期 √\n");
	}

	// 替换尾部 （等长度）
	exp = "ab34ef";
	sb->replace(4, 2, "ef");
	printf("sb预期结果为%s 实际结果为%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		return false;
	}
	else {
		printf("sb符合预期 √\n");
	}

	// 替换中间 （等长度）
	exp = "abcdef";
	sb->replace(2, 2, "cd");
	printf("sb预期结果为%s 实际结果为%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		return false;
	}
	else {
		printf("sb符合预期 √\n");
	}

	// 替换头部 （更长的字符串）
	exp = "123cdef";
	sb->replace(0, 3, "123");
	printf("sb预期结果为%s 实际结果为%s \n", exp.c_str(), sb->toString().c_str());
	if (sb->toString() != exp) {
		delete(sb);
		printf("sb不符合预期 ×\n");
		return false;
	}
	else {
		printf("sb符合预期 √\n");
	}

	// 替换头部 （更长的字符串）
    // 替换头部 （更长的字符串）

	// 替换头部 （更短的字符串）
	// 替换头部 （更短的字符串）
	// 替换头部 （更短的字符串）


	printf("----------- testStringBuilderReplace 测试成功 √ ----------- \n");
	return true;
}


/*********************************************************************
 * 函数名称：testStringBuilderSplit
 * 函数功能：测试StringBuilder分割字符串功能
 * 输入参数：None
 * 返回参数：bool
 * 输出结果：未抛出异常，返回true
 *********************************************************************/
bool testStringBuilderSplit() {
	printf("------------ testStringBuilderSplit 测试开始 ------------ \n");
	printf("----------- testStringBuilderSplit 测试成功 √ ----------- \n");
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