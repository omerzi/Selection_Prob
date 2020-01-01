#ifndef BSTreeNode__H
#define BSTreeNode__H
#include <iostream>
using namespace std;
typedef int KeyType;
typedef int DataType;

class BSTreeNode {

private:
	KeyType key;
	DataType data;
	BSTreeNode * left, *right;
public:
	BSTreeNode() = default;
	BSTreeNode(KeyType key, DataType data, BSTreeNode * left, BSTreeNode * right);
	~BSTreeNode() ;
	void inorder();
	void preorder();
	void postorder();
	friend class BSTree;

};
#endif // !BSTreeNode_H#
