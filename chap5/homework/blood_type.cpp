#include <iostream>
using namespace std;
int main(){
	while (true){
		char input[10];
		cout << "Ư¡�� ������� �������� �Է��Ͻÿ�(A, B, O, AB, X�� ����) : ";
		cin >> input;
		if (strlen(input) == 2 && toupper(input[0]) == 'A'&&toupper(input[1]) == 'B')
			cout << endl << "AB���� �����ϴ� ���� ���ٸ��ϴ�" << endl << endl;
		else if (strlen(input) == 1){
			if (toupper(input[0]) == 'X'){
				cout << "�����մϴ�" << endl;
				break;
			}
			else if (toupper(input[0]) == 'A')
				cout << endl << "A���� �ҽ������� ���δ� ����� �鵵 �ֽ��ϴ�" << endl << endl;
			else if (toupper(input[0]) == 'B')
				cout << endl << "B���� �ڽŸ� �����ϴ� ������ ������ Ȱ�����ϴ�" << endl << endl;
			else if (toupper(input[0]) == 'O')
				cout << endl << "O���� �米���� ������ �� ������ϴ�" << endl << endl;
			else
				cout << endl << "A, B, O, AB, X �߿����� �Է����ֽʽÿ�" << endl << endl;
		}
		else
			cout << endl << "A, B, O, AB, X �߿����� �Է����ֽʽÿ�" << endl << endl;
	}//!strcmp(input,"A")�� �� ���� �ִ�
	return 0;
}