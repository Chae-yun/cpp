#include <iostream>
using namespace std;
int main(){
	//�ڱ� �ڽ��� ������ ����� ���� �ڱ� �ڽ��� ���� ������ 1~1000
	int count = 0;
	cout << "������ (1~1000)" << endl;
	for (int i = 1; i <= 1000; i++){
		int sum = 0;
		for (int j = 1; j <= i / 2; j++){
			if (i%j == 0)
				sum += j;
		}
		if (sum == i){
			cout << i << endl;
			count++;
		}
	}
	cout << endl << "1~1000�� ������ ���� : " << count << endl;
	return 0;
}