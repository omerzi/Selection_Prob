#include "General.h"
#include "Person.h"
#include "BSTree.h"
#include "BSTreeNode.h"
#include <stdlib.h>  
#include <ctime>
#pragma warning (disable:4996)
int Partition(Person * p_Arr[], int low, int high)
{
	srand((time(0)));
	int randIndex = rand() % (high - low + 1) + low;
	Person pivot(*p_Arr[randIndex]);
	int i = low - 1;
	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (p_Arr[j]->getID() < pivot.getID())
		{
			i++;    // increment index of smaller element
			Person * temp = p_Arr[j];
			p_Arr[j] = p_Arr[i];
			p_Arr[i] = temp;
		}
	}
	Person* temp = p_Arr[randIndex];
	p_Arr[randIndex] = p_Arr[i + 1];
	p_Arr[i + 1] = temp;
	i++;
	return i;
}
//----------------------------------------------------//
const Person & RandSelection(Person * p_Arr[], int k,int n, int & NumComp)
{
	return Select(p_Arr, 0, n - 1, NumComp, k);
}
//----------------------------------------------------//
const Person & Select(Person * p_Arr[], int left, int right, int & NumComp, int k)
{
	int pivot;
	int leftPart;
	pivot = Partition(p_Arr, left, right);
	leftPart = pivot - left + 1;
	if (k == leftPart)
	{
		NumComp++;
		return *p_Arr[pivot];
	}
	else NumComp++;
	if (k < leftPart)
	{
		NumComp++;
		return Select(p_Arr, left, pivot - 1, NumComp, k);
	}
	else
	{
		NumComp++;
		return Select(p_Arr, pivot + 1, right, NumComp, k - leftPart);
	}
}

const Person & BST(Person * p_Arr[], int k,int n, int & NumComp)
{
	//this function creates a BST from the person array, and finds the K'th number size (by id)
	//creating the tree from the given array:
	BSTree tr;
	for (int i = 0; i < n; i++)
	{
		tr.Insert(p_Arr[i]);
	}
	BSTreeNode * node = tr.FindK(tr.getRoot(), k);
	return *node->getData();
}



