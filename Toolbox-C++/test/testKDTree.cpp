#include "KDTree.h"

static bool testPrintNode();
static bool testInitKDTree();
static bool testInsertKDNode();
static bool testGetAbsoluteDistance();
static bool testIterateTree();

/*********************************************************************
 * �������ƣ�testPrintNode
 * �������ܣ�����printNode�Ƿ������node�������Ϣ
 * ���������None
 * ���ز�����bool
 * ��������δ�׳��쳣����ӡNode��Ϣ������true
 *********************************************************************/
static bool testPrintNode() {
	try {
		printf("------------ testPrintNode ���Կ�ʼ -------------- \n");
		vector<int> nodeVecotr{ 4,5,6,7 };
		KDNode node0 = KDNode(1, &nodeVecotr, 0);
		node0.printNode();
		printf("------------ testPrintNode ���Գɹ� ��------------ \n");
		return true;
	}
	catch (...){
		printf("------------ testPrintNode ����ʧ�� ��------------ \n");
		return false;
	}
}


/*********************************************************************
 * �������ƣ�testInitKDTree
 * �������ܣ�����KDTree�Ĺ��캯���Ƿ�����
 * ���������None
 * ���ز�����bool
 * ��������δ�׳��쳣������true
 *********************************************************************/
static bool testInitKDTree() {
	try {
		printf("------------ testInitKDTree ���Կ�ʼ -------------- \n");
		vector<int> rootNode = vector<int>{ 1, 2, 3, 4 };
		KDTree tree = KDTree(&rootNode);
		printf("------------ testInitKDTree ���Գɹ� ��------------ \n");
		return true;
	}
	catch (...) {
		printf("------------ testInitKDTree ����ʧ�� ��------------ \n");
		return false;
	}
}


/*********************************************************************
 * �������ƣ�testInsertKDNode
 * �������ܣ�����KDTree�Ĳ��뺯���Ƿ�����
 * ���������None
 * ���ز�����bool
 * ��������δ�׳��쳣������true
 *********************************************************************/
static bool testInsertKDNode() {
	try {
		printf("------------ testInsertKDNode ���Կ�ʼ -------------- \n");
		vector<int> rootNode = vector<int>{ 1, 2, 3, 4 };
		KDTree tree = KDTree(&rootNode);

		vector<int> node1 = vector<int>{ 4, 5, 1, 2 };
		tree.insertKDNode(&node1);

		vector<int> node2 = vector<int>{ 4, 5, 1, 2 };
		tree.insertKDNode(&node2);

		vector<int> node3 = vector<int>{ 1, 2, 1, 4 };
		tree.insertKDNode(&node3);

		printf("------------ testInsertKDNode ���Գɹ� ��------------ \n");
		return true;
	}
	catch (...) {
		printf("------------ testInsertKDNode ����ʧ�� ��------------ \n");
		return false;
	}
}


/*********************************************************************
 * �������ƣ�testGetAbsoluteDistance
 * �������ܣ�����getAbsoluteDistance���������������Ƿ���ȷ
 * ���������None
 * ���ز�����bool
 * ��������δ�׳��쳣������true
 *********************************************************************/
static bool testGetAbsoluteDistance() {
	try {
		printf("------------ testInsertKDNode ���Կ�ʼ -------------- \n");
		double e = 0.0000000001;
		vector<int> rootNode = vector<int>{ 1, 2, 3, 4 };
		KDTree tree = KDTree(&rootNode);

		vector<int> nodeV1 = vector<int>{ 1, 2, 3, 4 };
		KDNode* node1 = tree.insertKDNode(&nodeV1);
		double res1 = tree.getAbsoluteDistance(tree.getRootNode(), node1);
		if (res1 - 0.0 < e || 0.0 - res1 < e) {
			printf("res1���Ϊ��%lf ����Ԥ�� ��\n", res1);
		}
		else {
			printf("res1���Ϊ��%lf ������Ԥ�� ��\n", res1);
			return false;
		}

		vector<int> nodeV2 = vector<int>{ 4, 5, 1, 2 };
		KDNode* node2 = tree.insertKDNode(&nodeV2);
		double res2 = tree.getAbsoluteDistance(tree.getRootNode(), node2);
		if (res2 - 7.211103 < e || 7.211103 - res2 < e) {
			printf("res2���Ϊ��%lf ����Ԥ�� ��\n", res2);
		}
		else {
			printf("res2���Ϊ��%lf ������Ԥ�� ��\n", res2);
			return false;
		}

		printf("------------ testInsertKDNode ���Գɹ� ��------------ \n");
		return true;
	}
	catch (...) {
		printf("------------ testInsertKDNode ����ʧ�� ��------------ \n");
		return false;
	}
}


/*********************************************************************
 * �������ƣ�testIterateTree
 * �������ܣ��������Ľṹ�Ƿ���ȷ�������������
 * ���������None
 * ���ز�����bool
 * ��������δ�׳��쳣������true
 *********************************************************************/
static bool testIterateTree() {
	printf("------------ testIterateTree ���Կ�ʼ -------------- \n");
	vector<int> rootNode = vector<int>{ 1, 2, 3, 4 };
	vector<int> node1 = vector<int>{ 4, 3, 1, 1 };
	vector<int> node2 = vector<int>{ 2, 2, 3, 4 };
	vector<int> node3 = vector<int>{ 2, 1, 1, 4 };

	KDTree tree = KDTree(&rootNode);
	tree.insertKDNode(&node1);
	tree.insertKDNode(&node2);
	tree.insertKDNode(&node3);

	KDTree::iterateTree(tree.getRootNode(), &KDNode::printNode);

	printf("------------ testIterateTree ���Գɹ� ��------------ \n");
}



void main3() {
 //   testPrintNode();
	//testInitKDTree();
	//testInsertKDNode();
	//testGetAbsoluteDistance();
	//testIterateTree();

}



