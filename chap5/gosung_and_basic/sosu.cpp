#include <iostream>
using namespace std;
int main(){
	int count = 0;

	cout << "1~100 ������ �Ҽ� : "<<endl;

	cout << 2 << endl;

	/*for (int i = 3; i <= 100; i += 2){ //���Ϸ� �ٲٸ� �ʱ�ȭ�� ������ ���ǹ��� ���� ���ǹ����� �������� ���� �ȿ� ������ ������ �ٶ���
		int judge = 0;

		for (int j = 3; j <= i / 2; j++){
			if (i%j == 0)
				judge++;
		}

		if (judge == 0){
			cout << i << endl;
			count++;
		}
	}*/

	for (int i = 3; i <= 100; i+=2){ //���Ϸ� �ٲٸ� �ʱ�ȭ�� ������ ���ǹ��� ���� ���ǹ����� �������� ���� �ȿ� ������ ������ �ٶ���
		bool flg = true;

		for (int j = 3; j <= i/2; j++){
			if (i%j == 0)
				flg = false; break;
		}

		if (flg == true){
			cout << i << endl;
			count++;
		}
	} //ȿ������ ��� i+=2 ���ϰ� i++�ϸ� 2��� �þ flg�� �͵� ȸ�� �پ��

	cout << "1~100 ������ �Ҽ��� ������ " << count << "���Դϴ�." << endl;

	return 0;
}