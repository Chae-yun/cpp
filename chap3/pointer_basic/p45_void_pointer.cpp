#include <iostream>
using namespace std;
int main(){
	int value = 10;
	void* pValue = 0; //��

	pValue = &value;

	cout << "pValue = " << pValue << endl;
	cout << "*pValue = " << *(int *)pValue << endl; //(int *)���ϸ� ����
	cout << "value = " << value << endl;

	*(int *)pValue = 20; //(int *)���ϸ� ����

	cout << "pValue = " << pValue << endl;
	cout << "*pValue = " << *(int *)pValue << endl; //(int *)���ϸ� ����
	cout << "value = " << value << endl;

	return 0;
}