#include "KDTree.h"

static bool testPrintNode();
static bool testInitKDTree();
static bool testInsertKDNode();
static bool testGetAbsoluteDistance();
static bool testIterateTree();

/*********************************************************************
 * 函数名称：testPrintNode
 * 函数功能：测试printNode是否能输出node的相关信息
 * 输入参数：None
 * 返回参数：bool
 * 输出结果：未抛出异常并打印Node信息，返回true
 *********************************************************************/
static bool testPrintNode() {
	try {
		printf("------------ testPrintNode 测试开始 -------------- \n");
		vector<int> nodeVecotr{ 4,5,6,7 };
		KDNode node0 = KDNode(1, &nodeVecotr, 0);
		node0.printNode();
		printf("------------ testPrintNode 测试成功 √------------ \n");
		return true;
	}
	catch (...){
		printf("------------ testPrintNode 测试失败 ×------------ \n");
		return false;
	}
}


/*********************************************************************
 * 函数名称：testInitKDTree
 * 函数功能：测试KDTree的构造函数是否正常
 * 输入参数：None
 * 返回参数：bool
 * 输出结果：未抛出异常，返回true
 *********************************************************************/
static bool testInitKDTree() {
	try {
		printf("------------ testInitKDTree 测试开始 -------------- \n");
		vector<int> rootNode = vector<int>{ 1, 2, 3, 4 };
		KDTree tree = KDTree(&rootNode);
		printf("------------ testInitKDTree 测试成功 √------------ \n");
		return true;
	}
	catch (...) {
		printf("------------ testInitKDTree 测试失败 ×------------ \n");
		return false;
	}
}


/*********************************************************************
 * 函数名称：testInsertKDNode
 * 函数功能：测试KDTree的插入函数是否正常
 * 输入参数：None
 * 返回参数：bool
 * 输出结果：未抛出异常，返回true
 *********************************************************************/
static bool testInsertKDNode() {
	try {
		printf("------------ testInsertKDNode 测试开始 -------------- \n");
		vector<int> rootNode = vector<int>{ 1, 2, 3, 4 };
		KDTree tree = KDTree(&rootNode);

		vector<int> node1 = vector<int>{ 4, 5, 1, 2 };
		tree.insertKDNode(&node1);

		vector<int> node2 = vector<int>{ 4, 5, 1, 2 };
		tree.insertKDNode(&node2);

		vector<int> node3 = vector<int>{ 1, 2, 1, 4 };
		tree.insertKDNode(&node3);

		printf("------------ testInsertKDNode 测试成功 √------------ \n");
		return true;
	}
	catch (...) {
		printf("------------ testInsertKDNode 测试失败 ×------------ \n");
		return false;
	}
}


/*********************************************************************
 * 函数名称：testGetAbsoluteDistance
 * 函数功能：测试getAbsoluteDistance算出来的两点距离是否正确
 * 输入参数：None
 * 返回参数：bool
 * 输出结果：未抛出异常，返回true
 *********************************************************************/
static bool testGetAbsoluteDistance() {
	try {
		printf("------------ testInsertKDNode 测试开始 -------------- \n");
		double e = 0.0000000001;
		vector<int> rootNode = vector<int>{ 1, 2, 3, 4 };
		KDTree tree = KDTree(&rootNode);

		vector<int> nodeV1 = vector<int>{ 1, 2, 3, 4 };
		KDNode* node1 = tree.insertKDNode(&nodeV1);
		double res1 = tree.getAbsoluteDistance(tree.getRootNode(), node1);
		if (res1 - 0.0 < e || 0.0 - res1 < e) {
			printf("res1结果为：%lf 符合预期 √\n", res1);
		}
		else {
			printf("res1结果为：%lf 不符合预期 ×\n", res1);
			return false;
		}

		vector<int> nodeV2 = vector<int>{ 4, 5, 1, 2 };
		KDNode* node2 = tree.insertKDNode(&nodeV2);
		double res2 = tree.getAbsoluteDistance(tree.getRootNode(), node2);
		if (res2 - 7.211103 < e || 7.211103 - res2 < e) {
			printf("res2结果为：%lf 符合预期 √\n", res2);
		}
		else {
			printf("res2结果为：%lf 不符合预期 ×\n", res2);
			return false;
		}

		printf("------------ testInsertKDNode 测试成功 √------------ \n");
		return true;
	}
	catch (...) {
		printf("------------ testInsertKDNode 测试失败 ×------------ \n");
		return false;
	}
}


/*********************************************************************
 * 函数名称：testIterateTree
 * 函数功能：测试树的结构是否正确，采用中序遍历
 * 输入参数：None
 * 返回参数：bool
 * 输出结果：未抛出异常，返回true
 *********************************************************************/
static bool testIterateTree() {
	printf("------------ testIterateTree 测试开始 -------------- \n");
	vector<int> rootNode = vector<int>{ 1, 2, 3, 4 };
	vector<int> node1 = vector<int>{ 4, 3, 1, 1 };
	vector<int> node2 = vector<int>{ 2, 2, 3, 4 };
	vector<int> node3 = vector<int>{ 2, 1, 1, 4 };

	KDTree tree = KDTree(&rootNode);
	tree.insertKDNode(&node1);
	tree.insertKDNode(&node2);
	tree.insertKDNode(&node3);

	KDTree::iterateTree(tree.getRootNode(), &KDNode::printNode);

	printf("------------ testIterateTree 测试成功 √------------ \n");
}



void main3() {
 //   testPrintNode();
	//testInitKDTree();
	//testInsertKDNode();
	//testGetAbsoluteDistance();
	//testIterateTree();

}



