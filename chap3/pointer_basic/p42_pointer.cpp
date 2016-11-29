#include <iostream>
using namespace std;
int main(){
	int value = 10;
	int* pValue = 0; //³Î

	pValue = &value;

	cout << "pValue = " << pValue << endl;
	cout << "*pValue = " << *pValue << endl;
	cout << "value = " << value << endl;

	*pValue = 20;

	cout << "pValue = " << pValue << endl;
	cout << "*pValue = " << *pValue << endl;
	cout << "value = " << value << endl;

	return 0;
}