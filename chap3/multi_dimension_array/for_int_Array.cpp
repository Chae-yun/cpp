#include <iostream>
using namespace std;

int main(){
	int nArray[2][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 }
	};

	int *pArray = nArray[0];

	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 3; j++){
			//cout << nArray[i][j] << "  ";
			cout << *(pArray+i*3+j) << "  "; //�������� ���ϴ� ���� ����!
		}
		cout << endl;
	}

	return 0;
}