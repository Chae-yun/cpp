#include <iostream>
using namespace std;
int main(){
	char *pMessage = "welcome to korea";

	for (int i = 0;; i++){
		if (*(pMessage + i) == NULL){ //#define NULL 0    �׸��� '\0'�� ���� �̽������� �������̱� ������ 2���� �ƴϰ� 1���ڷ� ���! "���� '�̰�
			cout << "count=" << i << endl;
			break;
		}
	}

	
	/*int i;
	for (i = 0; *(pMessage + i) != NULL; i++);
	cout << "count=" << i << endl;*/ //�̷� ����� �ִ�

	return 0;
}