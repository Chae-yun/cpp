#include <iostream>
using namespace std;

void Swap_CallByValue(int value1, int value2){
	int temp = value1;
	value1 = value2;
	value2 = temp;
}

void Swap_CallByPointer(int* pValue1, int* pValue2){
	int temp = *pValue1;
	*pValue1 = *pValue2;
	*pValue2 = temp;
}

void Swap_CallByReference(int& value1, int& value2){
	int temp = value1;
	value1 = value2;
	value2 = temp;
}

int main(){
	int value1, value2;
	
	value1 = 10;
	value2 = 20;
	cout << value1 << ", " << value2 << " swap(call by value)\t";
	Swap_CallByValue(value1, value2);
	cout << value1 << ", " << value2 << endl;

	value1 = 10;
	value2 = 20;
	cout << value1 << ", " << value2 << " swap(call by pointer)\t";
	Swap_CallByPointer(&value1, &value2);
	cout << value1 << ", " << value2 << endl;

	value1 = 10;
	value2 = 20;
	cout << value1 << ", " << value2 << " swap(call by reference)\t";
	Swap_CallByReference(value1, value2);
	cout << value1 << ", " << value2 << endl;

	return 0;
}