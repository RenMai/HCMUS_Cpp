#ifndef _H_23TREE_H_
#define _H_23TREE_H_

#include <cstdlib>
#include <utility>
#include <iostream>
#include <exception>

using namespace std;

class duplicatekey : public exception {
public:
	virtual const char* what() const throw(){
		return "Attempting to insert duplicate key ";
	}
};

class Node23 {
private:
	friend class Tree23;
	friend class Node34;
	Node23(bool three_node = false) : isThreeNodeFlag(three_node), leftChild(0), rightChild(0), parent(0) {}
	Node23 & operator =(Node23 &rhs);
	Node23(int key);
	Node23(int small, int large);
	Node23(int small, Node23 * pParent, Node23 *pleftChild, Node23 *prightChild);
	Node23(const Node23 &n);
	Node23 & makeTwoNode(int value, Node23 *pParent, Node23 * left, Node23 * right);

	bool isLeafNode();
	bool isThreeNode();
	void setThreeNode(bool flag);
	int getSmallValue() { return smallValue; }
	int getLargeValue() { return largeValue; }

	Node23 *leftChild;
	Node23 *rightChild;
	Node23 *middleChild;
	Node23 *parent;

	int smallValue;
	int largeValue;
	bool isThreeNodeFlag;
};

inline bool Node23::isLeafNode() {
	return !leftChild ? true : false;
}
inline bool Node23::isThreeNode() {
	return this->isThreeNodeFlag;
}
inline void Node23::setThreeNode(bool flag)
{
	this->isThreeNodeFlag = flag;
}
inline Node23::Node23(int key) :isThreeNodeFlag(false), leftChild(0), rightChild(0)
{
	smallValue = key;
}
inline Node23::Node23(int small, int large) : isThreeNodeFlag(false), leftChild(0), rightChild(0)
{
	smallValue = small;
	largeValue = large;
}
inline Node23::Node23(int small, Node23 *pParent, Node23 * pleftChild,
	Node23 * prightChild) : isThreeNodeFlag(false), parent(pParent), leftChild(pleftChild), rightChild(prightChild)
{
	smallValue = small;
}
inline Node23::Node23(const Node23 & n) : isThreeNodeFlag(n.isThreeNodeFlag),
leftChild(n.leftChild), rightChild(n.rightChild), parent(n.parent)
{
}

class Node34 {
private:
	int smallValue;
	int middleValue;
	int largeValue;

	Node23 *leftChild;
	Node23 *leftMiddleChild;
	Node23 *rightMiddleChild;
	Node23 *rightChild;

public:
	Node34(Node23 *threeNode, int new_value, Node23 *leftChildOfNewValue = 0,
		Node23 *rightChildOfNewValue = 0);

	int  getSmallValue()  { return smallValue; }
	int  getMiddleValue() { return middleValue; }
	int  getLargeValue()  { return largeValue; }
	Node23 *getLeftChild()        { return leftChild; }
	Node23 *getLeftMiddleChild()  { return leftMiddleChild; }
	Node23 *getRightMiddleChild() { return rightMiddleChild; }
	Node23 *getRightChild()   { return rightChild; }
};

Node34::Node34(Node23 *threeNode, int new_key, Node23 *leftChildOfNewValue, Node23 *rightChildOfNewValue)
{
	if (new_key < threeNode->smallValue) {

		smallValue = new_key;
		middleValue = threeNode->smallValue;
		largeValue = threeNode->largeValue;

		leftChild = leftChildOfNewValue;
		leftMiddleChild = rightChildOfNewValue;
		rightMiddleChild = threeNode->middleChild;
		rightChild = threeNode->rightChild;

	}
	else if (new_key > threeNode->largeValue) {
		smallValue = threeNode->smallValue;
		middleValue = threeNode->largeValue;
		largeValue = new_key;

		leftChild = threeNode->leftChild;
		leftMiddleChild = threeNode->middleChild;
		rightMiddleChild = leftChildOfNewValue;
		rightChild = rightChildOfNewValue;
	}
	else {
		smallValue = threeNode->smallValue;
		middleValue = new_key;
		largeValue = threeNode->largeValue;

		leftChild = threeNode->leftChild;
		leftMiddleChild = leftChildOfNewValue;
		rightMiddleChild = rightChildOfNewValue;
		rightChild = threeNode->rightChild;
	}
}

Node23 & Node23::makeTwoNode(int value, Node23 *pParent, Node23 *left, Node23 *right)
{
	smallValue = value;
	leftChild = left;
	rightChild = right;
	isThreeNodeFlag = false;
	parent = pParent;
	return *this;
}

class Tree23
{
protected:
	Node23 * root;
	bool DoSearch(int key, Node23 * root, Node23 * &location);
	Node23 * Split(Node23 * p, int key, Node23 * pleftChildOfNewKey = 0, Node23 * prightChildOfNewKey = 0);

	template<typename Functor> void DoTraverse(Functor f, Node23 * root);
	void DestroyTree(Node23 * root);

	Node23 * FindNextLargest(int key, Node23 * location);
	void fix(Node23 * location, Node23 * pAdoptee = 0);
	bool Redistribute(Node23 * node, int & situation_designator);
	void ReassignChildren(Node23 * node, Node23 * pleftChildOfNode, int situation);

public:
	Tree23() { root = 0; }
	~Tree23();
	template<typename Functor> void Traverse(Functor f);
	bool Search(int key, Node23 *& location);
	bool remove(int key, Node23 * location = 0);

	Node23 * insert(int key, Node23 * location = 0);
	int getMax();
	int getMin();
	int height();
	int count_leaf();

};
//int Tree23::count_leaf(Node23* tree, int n)
//{
//	if (tree->leftChild != NULL)
//		n += count_leaf(tree->leftChild, 0);
//	if (tree->rightChild != NULL)
//		n += count_leaf(tree->rightChild, 0);
//	if (tree->middleChild != NULL)
//		n += count_leaf(tree->middleChild, 0);
//	if (tree->leftChild == NULL && tree->rightChild == NULL && tree->middleChild == NULL)
//		return 1;
//	else return n;
//}
int Tree23::count_leaf()
{
	return 0;
}
int Tree23::height(){
	Node23 * temp = root;
	int k = 1;
	if (temp == NULL) return 0;
	else
	while (!temp->isLeafNode())
	{
		temp = temp->rightChild;
		++k;
	}
	return k;
}
int Tree23::getMax() {
	Node23 * temp = root;
	while (!temp->isLeafNode()) {
		temp = temp->rightChild;
	}
	if (temp->isThreeNode())	return temp->getLargeValue();
	else return temp->getSmallValue();
}
int Tree23::getMin(){
	Node23 * temp = root;
	while (!temp->isLeafNode()) {
		temp = temp->leftChild;
	}
	return temp->getSmallValue();
}

inline Tree23::~Tree23() {
	DestroyTree(root);
}
void Tree23::DestroyTree(Node23 * p)
{
	if (p == 0) {
		return;
	}
	if (p->isThreeNode()) {
		DestroyTree(p->leftChild);
		DestroyTree(p->middleChild);
		DestroyTree(p->rightChild);
		delete p;
	}
	else {
		DestroyTree(p->leftChild);
		DestroyTree(p->rightChild);
		delete p;
	}
}

template<typename Functor>inline void Tree23::Traverse(Functor f) {
	return DoTraverse(f, root);
}

template<typename Functor>void Tree23::DoTraverse(Functor f, Node23 *p) {
	if (p == 0) {
		return;
	}
	if (p->isThreeNode()) {
		DoTraverse(f, p->leftChild);
		f(p->smallValue);
		DoTraverse(f, p->middleChild);
		f(p->largeValue);
		DoTraverse(f, p->rightChild);
	}
	else {
		DoTraverse(f, p->leftChild);
		f(p->smallValue);
		DoTraverse(f, p->rightChild);
	}
}

bool Tree23::Search(int key, Node23 *& location) {
	if (root == 0) {
		location = 0;
		return false;
	}
	else {
		return DoSearch(key, root, location);
	}
}

bool Tree23::DoSearch(int key, Node23 * current, Node23 *& location) {
	if (current->smallValue == key || (current->isThreeNode() && current->largeValue == key)) {
		location = current;
		return true;
	}
	else if (current->isLeafNode()) {
		location = current;
		return false;
	}
	else if (current->isThreeNode()) {
		if (key < current->smallValue) {
			return DoSearch(key, current->leftChild, location);
		}
		else if (key < current->largeValue) {
			return DoSearch(key, current->middleChild, location);
		}
		else {
			return DoSearch(key, current->rightChild, location);
		}
	}
	else {
		if (key < current->smallValue) {
			return DoSearch(key, current->leftChild, location);
		}
		else return DoSearch(key, current->rightChild, location);
	}
}

Node23 * Tree23::insert(int key, Node23 * location){
	if (root == 0) {
		root = new Node23(key);
		return root;
	}
	if (location == 0 || !location->isLeafNode()) {
		Node23 * leaf;
		bool bRc = DoSearch(key, root, leaf);
		return insert(key, leaf);
	}
	Node23 * result = 0;
	if (!location->isThreeNode()) {
		result = location;
		if (key > location->smallValue) {
			location->largeValue = key;
			location->setThreeNode(true);
		}
		else if (key < location->smallValue) {
			location->largeValue = location->smallValue;
			location->smallValue = key;
			location->setThreeNode(true);
		}
		else {
			throw duplicatekey();
		}
	}
	else {
		result = Split(location, key);
	}

	return result;
}

Node23 * Tree23::Split(Node23 * location, int new_key, Node23 * pLeftChildOfNewKey, Node23 * pRightChildOfNewKey) {
	Node23 * parent = 0;
	bool isLeaf = location->isLeafNode();
	bool bRootIsNew = false;
	if (location == root) {
		parent = new Node23;
		bRootIsNew = true;
	}
	else {
		parent = location->parent;
	}
	Node34 node34(location, new_key, pLeftChildOfNewKey, pRightChildOfNewKey);
	Node23 *pSmallest = new Node23(node34.getSmallValue(), parent, node34.getLeftChild(), node34.getLeftMiddleChild());
	location->makeTwoNode(node34.getLargeValue(), parent, node34.getRightMiddleChild(), node34.getRightChild());
	Node23 * pLargest = location;
	if (!isLeaf) {
		node34.getLeftChild()->parent = pSmallest;
		node34.getLeftMiddleChild()->parent = pSmallest;

		node34.getRightMiddleChild()->parent = pLargest;
		node34.getRightChild()->parent = pLargest;
	}

	int middle = node34.getMiddleValue();
	if (bRootIsNew) {
		parent->smallValue = middle;
		parent->leftChild = pSmallest;
		parent->rightChild = pLargest;
		root = parent;

	}
	else if (parent->isThreeNode()) {
		Split(parent, middle, pSmallest, pLargest);
	}
	else {
		parent->setThreeNode(true);
		if (middle < parent->smallValue) {
			parent->largeValue = parent->smallValue;
			parent->smallValue = middle;
			parent->leftChild = pSmallest;
			parent->middleChild = pLargest;
		}
		else {
			parent->largeValue = middle;
			parent->middleChild = pSmallest;
		}
	}

	return parent;
}

bool Tree23::remove(int key, Node23 *location)
{
	if (location == 0) {
		bool bFound = DoSearch(key, root, location);
		if (bFound == false) {
			return false;
		}
		bool bRc = remove(key, location);
		return bRc;
	}
	else if (key != location->smallValue && key != location->largeValue) {
		return false;
	}
	Node23 *leafNode = 0;
	bool isInternalNode = !location->isLeafNode();
	if (isInternalNode) {
		leafNode = FindNextLargest(key, location);
		swap(location->smallValue, leafNode->smallValue);
	}
	else {
		leafNode = location;
	}

	if (leafNode->isThreeNode()) {
		if (key == leafNode->smallValue) {
			leafNode->smallValue = leafNode->largeValue;
		}
		leafNode->setThreeNode(false);
	}
	else {
		fix(leafNode);
	}
	return true;
}

Node23 *Tree23::FindNextLargest(int key, Node23 *location)
{
	Node23 *next = 0;
	if (location->isThreeNode() && location->smallValue == key) {
		next = location->middleChild;
	}
	else {
		next = location->rightChild;
	}
	while (!next->isLeafNode()) {
		next = next->leftChild;
	}
	return next;
}

bool Tree23::Redistribute(Node23 *node, int& situation)
{
	bool bRc = true;
	Node23 *parent = node->parent;
	if (parent->isThreeNode()) {
		if (node == parent->leftChild) {
			if (parent->middleChild->isThreeNode()) {
				node->smallValue = parent->smallValue;
				parent->smallValue = parent->middleChild->smallValue;
				parent->middleChild->smallValue = parent->middleChild->largeValue;
				parent->middleChild->setThreeNode(false);

				situation = 1;
			}
			else if (parent->rightChild->isThreeNode()) {
				node->smallValue = parent->smallValue;
				parent->smallValue = parent->middleChild->smallValue;

				parent->middleChild->smallValue = parent->largeValue;
				parent->largeValue = parent->rightChild->smallValue;
				parent->rightChild->smallValue = parent->rightChild->largeValue;
				parent->rightChild->setThreeNode(false);
				situation = 2;
			}
			else {
				bRc = false;
			}
		}
		else if (node == parent->middleChild) {
			if (parent->leftChild->isThreeNode()) {
				node->smallValue = parent->smallValue;
				parent->smallValue = parent->leftChild->largeValue;
				parent->leftChild->setThreeNode(false);

				situation = 3;
			}
			else if (parent->rightChild->isThreeNode()) {
				node->smallValue = parent->largeValue;
				parent->largeValue = parent->rightChild->smallValue;
				parent->rightChild->setThreeNode(false);

				situation = 4;
			}
			else {
				bRc = false;
			}
		}
		else {
			if (parent->middleChild->isThreeNode()) {
				node->smallValue = parent->largeValue;
				parent->largeValue = parent->middleChild->largeValue;
				parent->middleChild->setThreeNode(false);

				situation = 5;
			}
			else if (parent->leftChild->isThreeNode()) {
				node->smallValue = parent->largeValue;
				parent->largeValue = parent->middleChild->smallValue;
				parent->middleChild->smallValue = parent->smallValue;
				parent->smallValue = parent->leftChild->largeValue;
				parent->leftChild->setThreeNode(false);
				situation = 6;
			}
			else {
				bRc = false;
			}
		}
	}
	else {
		if (parent->leftChild == node) {
			if (parent->rightChild->isThreeNode()) {
				node->smallValue = parent->smallValue;
				parent->smallValue = parent->rightChild->smallValue;
				parent->rightChild->smallValue = parent->rightChild->largeValue;
				parent->rightChild->setThreeNode(false);
				situation = 7;
			}
			else {
				bRc = false;
			}
		}
		else {
			if (parent->leftChild->isThreeNode()) {
				node->smallValue = parent->smallValue;
				parent->smallValue = parent->leftChild->largeValue;
				parent->rightChild->setThreeNode(false);
				situation = 8;
			}
			else {
				bRc = false;
			}
		}
	}
	return bRc;
}

void Tree23::fix(Node23 *node, Node23 *pChildOfNode)
{
	if (node == root) {
		delete root;
		root = pChildOfNode;
	}
	else {
		Node23 *parent = node->parent;
		int situation;
		if (Redistribute(node, situation)) {
			if (!node->isLeafNode()) {
				ReassignChildren(node, pChildOfNode, situation);
			}
		}
		else {
			Node23 *pSibling;

			Node23 *middleChild;
			Node23 *Node23::*Ptr2newParentOfChild;
			bool parentIsEmpty = false;
			if (parent->isThreeNode()) {
				if (parent->rightChild == node) {
					pSibling = parent->middleChild;
					pSibling->largeValue = parent->largeValue;

					middleChild = pSibling->rightChild;
					Ptr2newParentOfChild = &Node23::rightChild;
				}
				else if (parent->middleChild == node) {
					pSibling = parent->rightChild;

					pSibling->largeValue = pSibling->smallValue;
					pSibling->smallValue = parent->largeValue;

					middleChild = pSibling->leftChild;
					Ptr2newParentOfChild = &Node23::leftChild;
				}
				else {
					pSibling = parent->middleChild;

					pSibling->largeValue = pSibling->smallValue;
					pSibling->smallValue = parent->largeValue;

					middleChild = pSibling->leftChild;
					Ptr2newParentOfChild = &Node23::leftChild;
				}
				parent->setThreeNode(false);
			}
			else {
				if (parent->rightChild == node) {
					pSibling = parent->leftChild;

					pSibling->largeValue = parent->smallValue;

					middleChild = pSibling->rightChild;
					Ptr2newParentOfChild = &Node23::rightChild;
				}
				else {
					pSibling = parent->rightChild;

					pSibling->largeValue = pSibling->smallValue;
					pSibling->smallValue = parent->smallValue;

					middleChild = pSibling->leftChild;
					Ptr2newParentOfChild = &Node23::leftChild;
				}
				parentIsEmpty = true;
			}
			pSibling->setThreeNode(true);
			if (!node->isLeafNode()) {
				pSibling->middleChild = middleChild;
				pSibling->*Ptr2newParentOfChild = pChildOfNode;
			}
			delete node;
			if (parentIsEmpty) {
				fix(parent, pSibling);
			}
		}
	}
}

void Tree23::ReassignChildren(Node23 *node, Node23* pChildOfNode, int situation)
{
	Node23 *parent = node->parent;
	switch (situation) {
	case 1:
		node->leftChild = pChildOfNode;
		node->rightChild = parent->middleChild->leftChild;
		parent->middleChild->leftChild = parent->middleChild->middleChild;
		break;
	case 2:
		node->leftChild = pChildOfNode;

		node->rightChild = parent->middleChild->leftChild;

		parent->middleChild->leftChild = parent->middleChild->rightChild;
		parent->middleChild->rightChild = parent->rightChild->leftChild;
		parent->rightChild->leftChild = parent->rightChild->middleChild;
		break;
	case 3:
	case 4:
		node->leftChild = pChildOfNode;
		node->rightChild = parent->rightChild->leftChild;
		parent->rightChild->leftChild = parent->rightChild->middleChild;
		break;
	case 5:
		node->rightChild = pChildOfNode;
		node->leftChild = parent->middleChild->rightChild;
		parent->middleChild->rightChild = parent->middleChild->middleChild;
	case 6:
		node->rightChild = (node->leftChild = pChildOfNode) ? node->leftChild : node->rightChild;

		node->leftChild = parent->middleChild->rightChild;

		parent->middleChild->rightChild = parent->middleChild->leftChild;
		parent->middleChild->leftChild = parent->leftChild->rightChild;
		parent->leftChild->rightChild = parent->leftChild->middleChild;
		break;
	case 7:
		node->leftChild = pChildOfNode;
		node->rightChild = parent->rightChild->leftChild;
		parent->rightChild->leftChild = parent->rightChild->middleChild;
		break;
	case 8:
		node->rightChild = pChildOfNode;
		node->leftChild = parent->leftChild->rightChild;
		parent->leftChild->rightChild = parent->rightChild->middleChild;
		break;
	}
}
#endif
