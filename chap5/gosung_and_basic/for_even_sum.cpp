#include <iostream>
using namespace std;
int main(){
	int i;
	int sum = 0; //�߿��߿� ���� 1
	for (i = 1; i <= 100; i++){
		if (i % 2 == 0)
			sum += i;
	}
	cout << "1���� 100������ ¦���� ���� " << sum << "�Դϴ�" << endl;
	return 0;
}