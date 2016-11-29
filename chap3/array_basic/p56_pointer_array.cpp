#include <iostream>
using namespace std;

int main(){
	int nArray[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int* pArray = nArray;
	int count = sizeof(nArray) / sizeof(int);

	//short nArray[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//short* pArray = nArray;
	//short count = sizeof(nArray) / sizeof(short);

	for (int i = 0; i < count; i++){
		cout << i << " : ÁÖ¼Ò" << (pArray + i) << ", °ª : " << *(nArray + i) << endl;
	}

	cout << sizeof(nArray) << endl;

	return 0;
}