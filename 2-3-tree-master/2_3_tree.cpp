
#include <iostream>
#include <fstream>
using namespace std;

// TwoThreeNode class
class TwoThreeNode {
    private:
        // Gets the value of the smallest data item in the subtree
        // rooted by this node
        int getSmallest() {
            TwoThreeNode *node = this;
            while (!node->isLeaf()) node = node->child[0];
            return node->key[0];
        }

        // Insert into a node with 1 child
        void insert1Siblings(TwoThreeNode *newChild, int newSmallest) {
            int newKey = newChild->key[0];
            newChild->parent = this;

            if (newKey < child[0]->key[0]) {
                // newNode is inserted as first child of root
                child[1] = child[0];
                child[0] = newChild;
                key[0] = child[1]->getSmallest();
            }
            else {
                // newNode is iserted as second child of root
                child[1] = newChild;
                key[0] = newSmallest;
            }
        }

        // Insert into a node with 2 children
        void insert2Siblings(TwoThreeNode *newChild, int newSmallest) {
            int newKey = newChild->key[0];
            newChild->parent = this;

            if (newKey < child[0]->key[0]) {
                child[2] = child[1];
                child[1] = child[0];
                child[0] = newChild;

                key[1] = key[0];
                key[0] = child[1]->getSmallest();
                updateParentSmallest(newSmallest);
            }
            else if (newKey < child[1]->key[0]) {
                child[2] = child[1];
                child[1] = newChild;

                key[1] = key[0];
                key[0] = newSmallest;
            }
            else {
                child[2] = newChild;

                key[1] = newSmallest;
            }
        }

        // Insert into a node with 3 children
        void insert3Siblings(TwoThreeNode *newChild, int newSmallest) {
            int newKey = newChild->key[0];

            int splitSmallest = -1;
            TwoThreeNode *splitNode = new TwoThreeNode();
            splitNode->parent = parent;

            if (newKey < child[0]->key[0] || newKey < child[1]->key[0]) {
                // newChild is inserted in current node
                splitSmallest = key[0];
                splitNode->child[0] = child[1];
                splitNode->child[1] = child[2];
                splitNode->key[0] = key[1];

                child[1]->parent = splitNode;
                child[2]->parent = splitNode;
                newChild->parent = this;

                if (newKey < child[0]->key[0]) {
                    // newChild is inserted as first child
                    child[1] = child[0];
                    child[0] = newChild;

                    key[0] = child[1]->getSmallest();
                    updateParentSmallest(newSmallest);
                }
                else {
                    // newChild is inserted as second child
                    child[1] = newChild;

                    key[0] = newSmallest;
                }
            }
            else {
                // newChild is inserted in split node
                child[2]->parent = splitNode;
                newChild->parent = splitNode;
 
                if (newKey < child[2]->key[0]) {
                    // newChild is inserted as first child
                    splitSmallest = newSmallest;
                    splitNode->child[0] = newChild;
                    splitNode->child[1] = child[2];
                    splitNode->key[0] = key[1];
                }
                else {
                    // newChild is inserted as second child
                    splitSmallest = key[1];
                    splitNode->child[0] = child[2];
                    splitNode->child[1] = newChild;
                    splitNode->key[0] = newSmallest;
                }
            }

            child[2] = NULL;
            key[1] = -1;

            if (parent->parent == NULL) {
                // At root, so new root needs to be created
                TwoThreeNode *newNode = new TwoThreeNode();

                parent->child[0] = newNode;
                newNode->parent = parent;
                newNode->child[0] = this;
                parent = newNode;
            }

            parent->insert(splitNode, splitSmallest);
        }

        // Update the parent nods efor the smallest child value
        void updateParentSmallest(int data) {
            switch (sibNumber()) {
                case 0: if (parent->parent != NULL) parent->updateParentSmallest(data); break;
                case 1: parent->key[0] = data; break;
                case 2: parent->key[1] = data; break;
            }
        }

    public:
        int key[2];
        TwoThreeNode *parent, *child[3];

        // Constructor
        TwoThreeNode(int data = -1) {
            key[0] = data;
            key[1] = -1;
            parent = child[0] = child[1] = child[2] = NULL;
        }

        // Check if node is a leaf
        bool isLeaf() {
            return (child[0] == NULL);
        }

        // Get which sibling the node is
        int sibNumber() {
            for (int i = 0; i < 3; ++i) {
                if (this == parent->child[i]) return i;
            }
            return -1;
        }

        // Insertion
        void insert(TwoThreeNode *newChild, int newSmallest) {
            if (child[1] == NULL) insert1Siblings(newChild, newSmallest);
            else if (child[2] == NULL) insert2Siblings(newChild, newSmallest);
            else insert3Siblings(newChild, newSmallest); 
        }
};

// TwoThreeTree class
class TwoThreeTree {
    private:
        TwoThreeNode *root;

        // Find the appropriate operation point
        TwoThreeNode* findSpot(TwoThreeNode *node, int data) {
            if (node == NULL) return NULL;

            while (!node->isLeaf()) {
                if (node->key[0] == data || node->key[1] == data)
                    return NULL;
                if (node->key[0] == -1 || data < node->key[0])
                    node = node->child[0];
                else if (node->key[1] == -1 || data < node->key[1])
                    node = node->child[1];
                else
                    node = node->child[2];
            }

            if (node->key[0] == data) return NULL;
            return node->parent;
        }

        // Recursively print the subtree starting from the given node
        void print(TwoThreeNode *node, int tabs = 0) {
            for (int i = 0; i < tabs; ++i) {
                cout << "\t";
            }

            if (node == NULL) {
                cout << "`--> NULL" << endl;
                return;
            }

            cout << "`--> " << node->sibNumber()
                 << ": ( " << node->key[0] << ", " << node->key[1] << ")" << endl;

            if (!node->isLeaf()) {
                ++tabs;
                print(node->child[0], tabs);
                print(node->child[1], tabs);
                print(node->child[2], tabs);
            }
        }

    public:
        // Constructor
        TwoThreeTree() {
            root = new TwoThreeNode();
            root->child[0] = new TwoThreeNode();
            root->child[0]->parent = root;
        }

        // Insert
        bool insert(int data) {
            TwoThreeNode *newNode = new TwoThreeNode(data);
            TwoThreeNode *spot = root->child[0];

            if (spot->child[0] == NULL) {
                // First insertion
                newNode->parent = spot;
                spot->child[0] = newNode;
            }
            else {
                spot = findSpot(spot, data);
                if (spot == NULL) return false;
            
                spot->insert(new TwoThreeNode(data), data);
            }

            return true;
        }

		int getMax()
		{
			TwoThreeNode * max = root->child[0];
			while (max->child[2] != NULL)
			{
				max = max->child[2];
			}
			if (max->key[1] != -1)
				return max->key[1];
			else return max->key[0];
		}

		int getMin()
		{

		}
        // Print 
        void print() {
            print(root->child[0]);
            cout << endl;
        }
};

// Main function
int main() {
    

    // Create tree and insert data
    TwoThreeTree ttTree;
	
	ttTree.insert(18);
	ttTree.insert(31);
	ttTree.insert(12);
	ttTree.insert(23);
	ttTree.insert(30);
	ttTree.insert(48);
	ttTree.insert(10);
	ttTree.insert(15);
	ttTree.insert(20);
	ttTree.insert(21);
	ttTree.insert(24);
	ttTree.insert(31);
	ttTree.insert(45);
	ttTree.insert(47);
	ttTree.insert(50);
	ttTree.insert(52);
	ttTree.print();
	cout << ttTree.getMax();
	system("pause>nul");
    return 0;
}
