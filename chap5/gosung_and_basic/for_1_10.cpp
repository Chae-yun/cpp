#include <iostream>
using namespace std;
int main(){
	for (int i = 1; i <= 10; i++){
		if (i == 5)
			//break; //4������ ��� ����
			continue; //5���� ��´� //��ƾ���� �������� ���ٸ� ������ ������ ����

		cout << i << endl;
	}
	return 0;
}