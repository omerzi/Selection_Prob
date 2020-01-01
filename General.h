#ifndef GENERAL__H
#define GENERAL__H
class Person;

int Partition(Person * p_Arr[], int low, int high);
const Person & RandSelection(Person *p_Arr[], int k,int n, int &NumComp);
const Person & Select(Person * p_Arr[], int left, int right, int &NumComp,int k);
//const Person & selectHeap(Person *p_Arr[], int k, int &NumComp);
const Person & BST(Person *p_Arr[], int k, int n, int &NumComp);



#endif //GENERAL__H