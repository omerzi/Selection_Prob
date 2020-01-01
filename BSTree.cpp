#include "BSTree.h"
#include "BSTreeNode.h"
BSTreeNode * BSTree::Find(Type item)
{ //find the node of by the type given
	BSTreeNode * temp = this->root;
	while (temp != nullptr)
	{
		if (item == temp->key)
			return temp;
		else if (item < temp->key)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return nullptr;
}

void BSTree::Insert(KeyType key, DataType data)
{
	if (this->Find(key) != nullptr)
	{
		cout << "Error: key already exists" << endl;
		return;
	}
	BSTreeNode * temp = this->root; //current node in tree
	BSTreeNode * parent = nullptr; //Parent of temp
	BSTreeNode * newnode; // new allocated node

	while (temp != nullptr)
	{
		parent = temp;
		parent->numOfSons++;
		if (key < temp->key)
		{
			temp = temp->left;
		}
		else
			temp = temp->right;
	}
	newnode = new BSTreeNode(key, data, 0,nullptr, nullptr);
	if (parent == nullptr) // insert newnode as root
		this->root = newnode;
	else if (key < parent->key)
	{
		parent->left = (newnode); //insert newnode as left child
	}
	else
		parent->right = (newnode); // insert newnode as right child
}

void BSTree::Delete(Type item)
{
	BSTreeNode * parent = parentFind(item);
	BSTreeNode * child = Find(item);
	// maximum one child :
	if (child->left == nullptr && child->right != nullptr)
	{
		if (parent->left == child)
		{
			parent->left = child->right;
		}
		else parent->right = child->right;
		child->right = nullptr;
		delete child;
	} 
	else if (child->right == nullptr && child->left != nullptr)
	{
		if (parent->left == child)
		{
			parent->left = child->left;
		}
		else parent->right = child->left;
		child->left = nullptr;
		delete child;
	}
	else if (child->left == nullptr && child->right == nullptr)
	{
		if (parent->left == child)
		{
			parent->left = nullptr;
		}
		else parent->right = nullptr;
		delete child;
	}
	//two children:
	BSTree childTree(child->left);
	BSTreeNode* maxInChildTree = childTree.Max();
	child->key = maxInChildTree->key;
	child->data = maxInChildTree->data;
	if (maxInChildTree->left == nullptr && maxInChildTree->right != nullptr)
	{
		maxInChildTree = maxInChildTree->right;
	}
	else if (maxInChildTree->right == nullptr && maxInChildTree->left != nullptr)
	{
		maxInChildTree = maxInChildTree->left;
	}
	else if (maxInChildTree->left == nullptr && maxInChildTree->right == nullptr)
	{
		delete maxInChildTree;
	}
}

void BSTree::makeEmpty(BSTreeNode * root)
{
	if (root == nullptr)
		return; // Tree is empty
	else
	{
		makeEmpty(root->left);
		makeEmpty(root->right);
		delete root;
	}
	return;
}

bool BSTree::isEmpty()
{
	if (this->root == nullptr)
		return true;
	return false;
}

BSTreeNode * BSTree::parentFind(Type item)
{
	//find the parent of node by the type given
	BSTreeNode * temp = this->root;
	while (temp != nullptr)
	{
		if (item == temp->left->key)
			return temp;
		else if (item == temp->right->key)
			return temp;
		else if (item < temp->key)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return nullptr;
}

Type BSTree::Min()
{ //return the minimum value in the tree
	if (root->left == nullptr)
		return root->key;
	else
	{
		root = root->left;
		this->Min();
	}
}

BSTreeNode* BSTree::Max()
{ // return the max value in the tree
	if (root->right == nullptr)
		return root;
	else
	{
		root = root->right;
		this->Max();
	}
}

void BSTree::PrintTree()
{
	//prints the tree in Inorder
	if (this->root != nullptr)
		this->root->inorder();
}

BSTreeNode * BSTree::getRoot() const
{
	return this->root;
}

BSTreeNode * BSTree::FindK(BSTreeNode * node, int k)
{
	//this function recieve a tree node and return a k'ths node by ID value
	if (node == nullptr)
		return nullptr; // didn't find K'ths node
	if (k > node->numOfSons + 1)
		return nullptr;
	int NleavesLeft = 0;
	if (node->left != nullptr)
		NleavesLeft = node->left->numOfSons+1;

	if (k == NleavesLeft+1)
	{
		// found the node
		return node;
	}
	if ( node->left==nullptr || NleavesLeft+1 < k)
	{
		if (node->left == nullptr)
			FindK(node->right, k - 1);
		else
			FindK(node->right, k - NleavesLeft - 1);
	}
	else
	{
		FindK(node->left, k);
	}

}