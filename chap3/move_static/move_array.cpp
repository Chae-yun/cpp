#include <iostream>
using namespace std;

int main(){
	int *pArray = 0;
	pArray = new int[10];

	for (int i = 0; i < 10; i++){
		pArray[i] = 10 + i; //�迭�� ÷�� ���
	}
	for (int i = 0; i < 10; i++){
		cout<< pArray[i] << endl; //�迭�� ÷�� ���
	}
	cout << endl;

	for (int i = 0; i < 10; i++){
		*(pArray + i) = 20 + i; //������ ���
	}
	for (int i = 0; i < 10; i++){
		cout << *(pArray + i) << endl; //������ ���
	}
	cout << endl;

	for (int i = 0; i < 10; i++){
		if (i % 2 == 1)
			cout << pArray[i] << endl;
		else
			cout << *(pArray + i) << endl;
	} //���� �ᵵ ����
	
	delete[] pArray; //�� ���� �� ���̿��� ������ �ǳ�
	//delete []pArray;

	return 0;
}