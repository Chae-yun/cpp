#include <iostream>
using namespace std;
int main(){
	int value = 10;
	void* pValue = 0; //널

	pValue = &value;

	cout << "pValue = " << pValue << endl;
	cout << "*pValue = " << *(int *)pValue << endl; //(int *)안하면 에러
	cout << "value = " << value << endl;

	*(int *)pValue = 20; //(int *)안하면 에러

	cout << "pValue = " << pValue << endl;
	cout << "*pValue = " << *(int *)pValue << endl; //(int *)안하면 에러
	cout << "value = " << value << endl;

	return 0;
}