#ifndef KDTREE_H
#define KDTREE_H

#include <vector>

using namespace std;

class KDNode {
public:
	KDNode(unsigned int nodeId, vector<int>* nodeVector, unsigned int nodeDepth) {
		this->nodeId = nodeId;
		this->demension = (*nodeVector).size();
		this->nodeDepth = nodeDepth;
		this->nodeVector = nodeVector;
		this->leftNode = NULL;
		this->rightNode = NULL;

	}

	int nodeValue() {
		return (*nodeVector)[this->nodeDepth % this->demension];
	}

	unsigned int getDemension() {
		return this->demension;
	}

	KDNode* getLeftNode() {
		return this->leftNode;
	}

	KDNode* getRightNode() {
		return this->rightNode;
	}

	int getVectorElement(int index) {
		if (index >= this->demension) {
			throw exception("fatal error: index should be below the dimension of the node!");
			return -1;
		}
		return (*this->nodeVector)[index];
	}

private:
	unsigned int nodeId;
	unsigned int nodeDepth;
	unsigned int demension;
	KDNode* leftNode;
	KDNode* rightNode;
	vector<int>* nodeVector;
};


class KDTree {

public:
	KDTree(vector<int>* rootNodeVector) {
		this->dimension = (*rootNodeVector).size();
		this->nextNodeId = 0;

		if (this->dimension <= 0) {
			throw exception("fatal error: size of the input vector should be larger than 0");
			return;
		}
		this->rootNode = new KDNode(nextNodeId++, rootNodeVector, 0);
	}

	KDNode* getRootNode() {
		return rootNode;
	}

	void insertKDNode(vector<int>* nodeVector) {
		KDNode* currentNode = rootNode;
		for (int depth = 0; depth < this->dimension; depth++) {

			if ((*nodeVector)[depth] <= currentNode->nodeValue()) {
				if (!currentNode->getLeftNode()) {
					KDNode* newNode = currentNode->getLeftNode();
					newNode = new KDNode(this->nextNodeId++, nodeVector, depth);
				}
				else {
					currentNode = currentNode->getLeftNode();
				}
			} 
			else {
				if (!currentNode->getRightNode()) {
					KDNode* newNode = currentNode->getRightNode();
					newNode = new KDNode(this->nextNodeId++, nodeVector, depth);
				}
				else {
					currentNode = currentNode->getRightNode();
				}

			}
		}

		if (!currentNode) {
			throw exception("fatal error: currentNode should not be NULL! Inserting Node has failed");
		}
	}

	void deleteKDNode() {

	}
private:
	unsigned int nextNodeId;
	int dimension;
	KDNode* rootNode;

	static double getAbsoluteDistance(KDNode* node1, KDNode* node2) {
		if (!node1 || !node2) {
			throw exception("fatal error: node cannot be NULL!");
			return -1.0;
		}

		unsigned int nodeDimension = node1->getDemension();
		if (nodeDimension != node2->getDemension()) {
			throw exception("fatal error: node1 and node2 have different dimension!");
			return -2.0;
		}

		double result = 0;
		for (unsigned int i = 0; i < nodeDimension; i++) {
			result = result + pow(node1->getVectorElement(i),2) + pow(node2->getVectorElement(i), 2);
		}
		return sqrt(result);
	}

};

#endif /* KDTREE_H */
