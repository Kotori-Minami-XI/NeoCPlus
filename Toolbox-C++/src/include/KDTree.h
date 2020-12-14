#ifndef KDTREE_H
#define KDTREE_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "ColorPrint.h"

#define MAX(a,b) (a >= b ? a : b)
#define MIN(a,b) (a <= b ? a : b)

using namespace std;

class KDNode {
public:
	enum NodeInfoLevel {NODEINFO_MINI, NODEINFO_MEDIUM, NODEINFO_FULL};

	KDNode(unsigned int nodeId, vector<int>* nodeVector, unsigned int nodeDepth) {
		this->nodeId = nodeId;
		this->demension = (unsigned int)(*nodeVector).size();
		this->nodeDepth = nodeDepth;
		this->nodeVector = nodeVector;
		this->nodeInfoLevel = NODEINFO_MINI;
		this->leftNode = NULL;
		this->rightNode = NULL;
	}

	void setNodeInfoLevel(NodeInfoLevel nodeInfoLevel) {
		this->nodeInfoLevel = nodeInfoLevel;
	}

	int nodeValue() {
		return (*nodeVector)[this->nodeDepth % this->demension];
	}

	unsigned int getDemension() {
		return this->demension;
	}

	void setLeftNode(KDNode *node) {
		this->leftNode = node;
	}

	void setRightNode(KDNode* node) {
		this->rightNode = node;
	}

	KDNode* getLeftNode() {
		return this->leftNode;
	}

	KDNode* getRightNode() {
		return this->rightNode;
	}

	int getVectorElement(unsigned int index) {
		if (index >= this->demension) {
			throw exception("fatal error: index should be below the dimension of the node!");
			return -1;
		}
		return (*this->nodeVector)[index];
	}

	void printNode() {
		int highlightIndex = this->nodeDepth % this->demension;
		string nodeInfo = "[";
		if (nodeInfoLevel > NODEINFO_MINI) {
			nodeInfo = "nodeId = " + to_string(this->nodeId) + " nodeValue = " + to_string(this->nodeValue()) + " nodeVector = " + nodeInfo;
		}

		for (unsigned int i = 0; i < this->demension; i++) {
			string num = to_string((*this->nodeVector)[i]);
			if (i == highlightIndex) {
				ColorPrint::colorStr(num, ColorPrint::FontFormat::BOLD, ColorPrint::FrontColor::FRONT_YELLOW, ColorPrint::BackColor::BACK_VIOLET);
			}
			nodeInfo = nodeInfo + num + " ";
		}

		nodeInfo.replace(nodeInfo.end() - 1, nodeInfo.end(), "]\n");
		printf(nodeInfo.c_str());
	}

private:
	KDNode* leftNode;
	KDNode* rightNode;
	unsigned int nodeId;
	unsigned int nodeDepth;
	unsigned int demension;
	NodeInfoLevel nodeInfoLevel;
	vector<int>* nodeVector;
};


class KDTree {
public:
	KDTree(vector<int>* rootNodeVector, bool allowedMultipleDeimension = false) {
		this->dimension = (unsigned int)(*rootNodeVector).size();
		this->allowedMultipleDeimension = allowedMultipleDeimension;
		this->nextNodeId = 0;

		if (this->dimension <= 0) {
			throw new exception("fatal error: size of the input vector should be larger than 0");
			return;
		}
		this->rootNode = new KDNode(nextNodeId++, rootNodeVector, 0);
		this->nodeMap.insert(pair<unsigned int, KDNode*>(0, rootNode));
	}

	KDNode* getRootNode() {
		return rootNode;
	}

	KDNode* insertKDNode(vector<int>* nodeVector) {
		KDNode* currentNode = rootNode;
		KDNode* newNode = NULL;

		if (!this->allowedMultipleDeimension && (*nodeVector).size() != this->dimension) {
			throw new exception("fatal error: this node is imcompatible with the tree. The tree does not allow different dimension\n");
			return NULL;
		}
		if (this->nodeMap.find(nextNodeId) != this->nodeMap.end()) {
			throw new exception("fatal error: this node is already exsisted. insertion failed\n");
			return NULL;
		}

		try {
			for (int depth = 0; depth < this->dimension; depth++) {
				if ((*nodeVector)[depth] <= currentNode->nodeValue()) {
					if (!currentNode->getLeftNode()) {
						newNode = new KDNode(this->nextNodeId, nodeVector, depth);
						currentNode->setLeftNode(newNode);
						this->nodeMap.insert(pair<unsigned int, KDNode*>(nextNodeId, newNode));
						nextNodeId++;
						break;
					}
					else {
						currentNode = currentNode->getLeftNode();
					}
				}
				else {
					if (!currentNode->getRightNode()) {
						newNode = new KDNode(this->nextNodeId, nodeVector, depth);
						currentNode->setRightNode(newNode);
						this->nodeMap.insert(pair<unsigned int, KDNode*>(nextNodeId, newNode));
						nextNodeId++;
						break;
					}
					else {
						currentNode = currentNode->getRightNode();
					}

				}
			}
		}
		catch (...) {
			throw new exception("fatal error: excepetion happens!");
			if (newNode) {
				delete(newNode);
			}
		}

		if (!currentNode) {
			throw new exception("fatal error: currentNode should not be NULL! Inserting Node has failed");
		}
		return newNode;
	}

	void deleteKDNode() {

	}

	KDNode* getNodeById(unsigned int nodeId) {
		if (this->nodeMap.find(nodeId) == this->nodeMap.end()) {
			return NULL;
		}
		return this->nodeMap[nodeId];
	}

	double getAbsoluteDistance(KDNode* node1, KDNode* node2) {
		if (!node1 || !node2) {
			throw new exception("fatal error: node cannot be NULL!");
			return -1.0;
		}

		unsigned int nodeDimension = node1->getDemension();
		if (!(this->allowedMultipleDeimension) && (nodeDimension != node1->getDemension()) || (nodeDimension != node2->getDemension())) {
			throw new exception("fatal error: Different dimension is not allowed!");
			return -2.0;
		}

		double result = 0;
		for (unsigned int i = 0; i < MAX(nodeDimension, MAX(node1->getDemension(), node2->getDemension())); i++) {
			if (i < node1->getDemension()) {
				result = result + pow(node1->getVectorElement(i) - node2->getVectorElement(i), 2);
			}
			else {
				result = result + pow(node1->getVectorElement(i), 2);
			}

			if (i < node2->getDemension()) {
				result = result + pow(node1->getVectorElement(i) - node2->getVectorElement(i), 2);
			}
			else {
				result = result + pow(node2->getVectorElement(i), 2);
			}
		}
		return sqrt(result);
	}

	static void iterateTree(KDNode* node, void (KDNode::*func)()){
		if (!node) {
			return;
		}
		if (node->getLeftNode()) {
			iterateTree(node->getLeftNode(), func);
		}

		(node->*func)();

		if (node->getRightNode()) {
			iterateTree(node->getRightNode(), func);
		}
	}

	KDNode* findNearestNode(KDNode* currentNode, KDNode* targetNode) {
		double minDistance = (double)LONG_MAX;
		int depth = 0;
		helper(currentNode, targetNode, depth, minDistance);
	}

	KDNode* helper(KDNode* currentNode, KDNode* targetNode, int depth, double& minDistance) {
		if (currentNode->getLeftNode() && targetNode->nodeValue() <= currentNode->nodeValue()) {
			helper(currentNode->getLeftNode(), targetNode, depth+1, minDistance);
		}
		else if (currentNode->getRightNode() && targetNode->nodeValue() > currentNode->nodeValue()) {
			helper(currentNode->getRightNode(), targetNode, depth + 1, minDistance);
		}

		if (!currentNode->getLeftNode() && !currentNode->getRightNode()) {
			minDistance = MIN(minDistance, getAbsoluteDistance(currentNode, targetNode));



			return currentNode;
		}

		minDistance = MIN(minDistance, getAbsoluteDistance(currentNode, targetNode));
		//if (getAbsoluteDistance(currentNode, targetNode) <= )
	}





private:
	unsigned int nextNodeId;
	int dimension;
	bool allowedMultipleDeimension;
	unordered_map<unsigned int, KDNode*> nodeMap;
	KDNode* rootNode;



};

#endif /* KDTREE_H */
