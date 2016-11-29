#include <iostream>
using namespace std;

int main(){
	int nArray[] = { 10, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int* pArray = nArray;
	int count = sizeof(nArray) / sizeof(int);

	for (int i = 0; i < count; i++){
		cout << i << " : *(pArray + i) = " << *(pArray + i) << ",\t*pArray + i = " << *pArray + i << endl;
	}

	return 0;
}