#ifndef BSTreeNode__H
#define BSTreeNode__H
#include <iostream>
using namespace std;
typedef int KeyType;
typedef char * DataType;

class BSTreeNode {

private:
	int numOfSons;
	KeyType key;
	DataType data;
	BSTreeNode * left, *right;
public:
	BSTreeNode() {this->numOfSons = 0;	};
	BSTreeNode(KeyType key, DataType data, int numOfSons,BSTreeNode * left, BSTreeNode * right);
	~BSTreeNode() ;
	const KeyType getKey() const;
	DataType getData() const;
	void inorder();
	void preorder();
	void postorder();
	friend class BSTree;

};
#endif // !BSTreeNode_H#
