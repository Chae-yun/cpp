#include <iostream>
using namespace std;
int main(){
	char answer;
	while (true){
		do{
			cout << "��� ���� �Ͻðڽ��ϱ�?" << endl;
			cout << "����Ϸ��� 'Y'�� �����Ϸ��� 'N'�� ��������." << endl;
			cin >> answer;
		} while ((toupper(answer) != 'Y') && (toupper(answer) != 'N')); //toupper�� ����Ÿ���� int!

		if (toupper(answer) == 'N'){
			cout << "�����մϴ�." << endl;
			break;
		}
		else if ((toupper(answer) == 'Y'))
			cout << "��� ���� �մϴ�" << endl;

	}
	return 0;
}