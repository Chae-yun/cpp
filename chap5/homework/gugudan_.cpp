#include <iostream>
using namespace std;
int main(){
	while(true){
		char input[10];
		cout << "����� ���ϴ� ���� �Է��Ͻÿ� (0�� 1~9�� ��� ���, x�� ����) : ";
		cin >> input;
		if (strlen(input) > 1)
			cout << endl << "�������� ������ϴ�" << endl << "0~9 Ȥ�� x�� �Է����ֽʽÿ�" << endl << endl;
		else if (toupper(input[0]) == 'X'){
			cout << "�����մϴ�" << endl;
			break;
		}
		else if (input[0] == '0'){
			cout << endl << "1~9�� ���" << endl;
			for (int i = 1; i <= 9; i++){
				cout << endl << i << "�� ���" << endl;
				for (int j = 1; j <= 9; j++)
					cout << i << " X " << j << " = " << (i*j) << endl;
			}
			cout << endl;
		}
		else if (input[0] >= '1' && input[0] <= '9'){
			cout << endl << input << "�� ���" << endl;
			for (int i = 1; i <= 9; i++)
				cout << input << " X " << i << " = " << (input[0] * i) << endl;
			cout << endl;
		}
		else
			cout << endl << "�������� ������ϴ�" << endl << "0~9 Ȥ�� x�� �Է����ֽʽÿ�" << endl << endl;
	}
	return 0;
}