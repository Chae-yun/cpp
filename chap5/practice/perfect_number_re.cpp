#include <iostream>
using namespace std;
int main(){
	//�ڱ� �ڽ��� ������ ����� ���� �ڱ� �ڽ��� ���� ������ 1~������ ��
	int last;
	char yn;

	while(true){
		int count = 0;

		cout << "�������� �� ���� �Է��Ͻÿ� : ";
		cin >> last;
		cout << "������ (1~" << last << ")" << endl;

		for (int i = 1; i <= last; i++){
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

		cout << endl << endl << "1~" << last << "�� ������ ���� : " << count << endl;

		cout << endl << "����Ͻðڽ��ϱ�?(y/n) : ";
		cin >> yn;

		while (toupper(yn) != 'N'&& toupper(yn) != 'Y'){
			cout << "�ٽ� �Է��Ͻÿ�(y/n) : ";
			cin >> yn;
		}

		if (toupper(yn) == 'N'){
			cout << "�����մϴ�" << endl;
			break;
		}
		else if (toupper(yn) == 'Y')
			cout << "����մϴ�" << endl << "-------------------------------" << endl;
	}
	return 0;
}