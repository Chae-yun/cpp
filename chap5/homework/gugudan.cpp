#include <iostream>
using namespace std;
int main(){
	int input;
	do{
		cout << "����� ���ϴ� ���� �Է��Ͻÿ� (0�� 1~9�� ��� ���, x�� ����) : ";
		cin >> input;
		if (input == 88 || input == 120){
			cout << "�����մϴ�" << endl;
			break;
		}
		else if (input == 0){
			cout << endl << "1~9�� ���" << endl;
			for (int i = 1; i <= 9; i++){
				cout << endl << i << "�� ���" << endl;
				for (int j = 1; j <= 9; j++)
					cout << i << " X " << j << " = " << (i*j) << endl;
			}
			cout << endl;
		}
		else if (input >= 1 && input <= 9){
			cout << endl << input << "�� ���" << endl;
			for (int i = 1; i <= 9; i++)
				cout << input << " X " << i << " = " << (input*i) << endl;
			cout << endl;
		}
		else
			cout << endl << "�������� ������ϴ�" << endl << "0~9 Ȥ�� x�� �Է����ֽʽÿ�" << endl << endl;
	} while (true);
	return 0;
}