/*#include <iostream>
using namespace std;
int main(){
	int num;
	while (true){
		int last = 0;
		cout << "ABC...�� ����ϰ� ���� �� ��ŭ ���ڸ� �Է��Ͻÿ� : ";
		cin >> num;
		if (num <= 0){
			cout << "������ ��� �����մϴ�" << endl;
			break;
		}
		char ch;
		do{
			for (ch = 'A'; ch <= last + 'A'; ch++){
				cout << ch;
				if (ch > 'Z')
					ch = 'A';
			}
			cout << endl;
			last++;
		} while (ch < num + 'A');
	}
	return 0;
}*/

#include <iostream>
using namespace std;
int main(){
	int jul;
	while (true){
		cout << "ABC...�� ����ϰ� ���� �� ��ŭ ���ڸ� �Է��Ͻÿ� : ";
		cin >> jul;
		if (jul > 0){
			for (int i = 0; i < jul; i++){ //char�� ���� ������ �۱� ������ �ݺ��� ���� �ȵȴ� (�� ��û ����ߴ���)
				//char a = 'A';
				for (int j = 0; j <= i; j++)
					/*if (a == 'Z' + 1)
						a = 'A';
					cout << (char)('A'+j);*/
					cout << (char)('A' + j%26); //�������� �ϸ� ���ܤ̤̤ФФ�
				cout << endl;
			}
		}
		else{
			cout << "������ ��� �����մϴ�" << endl;
			break;
		}
	}
	return 0;
}