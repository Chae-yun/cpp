#include <iostream>
using namespace std;

int main(){
	int nArray[3][4];

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){
			nArray[i][j] = i * 4 + j + 1; //���� ������ ������ ++�ϸ鼭 �Ҽ���
		}
	}

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){
			printf("%2d  ", nArray[i][j]);
		}
		cout << endl;
	}

	return 0;
}