#include "Person.h"
#include "General.h"
using namespace std;
#include <iostream>
#pragma warning(disable:4996)



int main()
{
	char name[Person::NAME_MAX];
	int id, numofperson, index, numComp=0;
	cout << "Enter number of persons:" << endl;
	cin >> numofperson;
	Person ** p_Arr = new Person *[numofperson];
	for (int i = 0; i < numofperson; i++)
	{
		cout << "enter id and then name" << endl;
		cin >> id;
		cin.getline(name, Person::NAME_MAX);
		p_Arr[i] = new Person(id, name);
	}
	cout << "Enter the index you want (between 1-n)" << endl;
	cin >> index;
	RandSelection(p_Arr, index, numofperson, numComp);
	cout << numComp;
	for (int i = 0; i < numofperson; i++)
	{
		delete p_Arr[i];
	}
	delete[] p_Arr;


}