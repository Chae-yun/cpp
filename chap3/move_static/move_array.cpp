#include <iostream>
using namespace std;

int main(){
	int *pArray = 0;
	pArray = new int[10];

	for (int i = 0; i < 10; i++){
		pArray[i] = 10 + i; //배열의 첨자 방식
	}
	for (int i = 0; i < 10; i++){
		cout<< pArray[i] << endl; //배열의 첨자 방식
	}
	cout << endl;

	for (int i = 0; i < 10; i++){
		*(pArray + i) = 20 + i; //포인터 방식
	}
	for (int i = 0; i < 10; i++){
		cout << *(pArray + i) << endl; //포인터 방식
	}
	cout << endl;

	for (int i = 0; i < 10; i++){
		if (i % 2 == 1)
			cout << pArray[i] << endl;
		else
			cout << *(pArray + i) << endl;
	} //뭘로 써도 노상관
	
	delete[] pArray; //뭐 뭐든 저 사이에만 넣으면 되남
	//delete []pArray;

	return 0;
}