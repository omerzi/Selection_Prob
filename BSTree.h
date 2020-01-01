#ifndef BSTree__H
#define BSTree__H

typedef int Type;
class BSTreeNode;

class BSTree {
private:
	BSTreeNode * root;
public:
	BSTree() {this->root = nullptr; };
	BSTree(BSTreeNode * root) { this->root = root; };
	~BSTree() { delete this->root; };
	BSTreeNode * Find(Type item);
	void Insert(int key , int data);
	void Delete(Type item);
	void makeEmpty(BSTreeNode * root);
	bool isEmpty();
	BSTreeNode * parentFind(Type item);
	Type Min();
	BSTreeNode* Max();
	void PrintTree();
	friend class BSTreeNode;
};
#endif // !BSTree_H