#include <iostream>
using namespace std;
int main(){
	int dan;

	while(1){ //while(true)�� ����
		cout << "���� ������ �̿��� ������ ��� ���α׷��Դϴ�." << endl;
		cout << "0�� �Է� �ϸ� ���� �մϴ�." << endl;
		cout << "����� ���� �Է� �ϼ���(1~19) : ";

		cin >> dan;

		if (dan == 0){
			cout << "������ ����� ���� �մϴ�." << endl;
			break;
		}

		if (dan < 1 || dan>19){
			cout << "�ٽ� �����մϴ�" << endl;
			continue;
		} //���� ����

		cout << dan << "�� ����մϴ�." << endl;

		for (int i = 1; i <= 9; i++){
			cout << "    " << dan << " * " << i << " = " << (dan*i) << endl;
		}
	}

	return 0;
}