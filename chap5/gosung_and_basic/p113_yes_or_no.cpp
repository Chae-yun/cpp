#include <iostream>
using namespace std;
int main(){
	char answer;
	do{
		cout << "��� ���� �Ͻðڽ��ϱ�?" << endl;
		cout << "����Ϸ��� 'Y'�� �����Ϸ��� 'N'�� ��������." << endl;
		cin >> answer;
	} while ((toupper(answer) != 'Y') && (toupper(answer) != 'N'));

	if ((toupper(answer) == 'Y'))
		cout << "��� ���� �մϴ�" << endl;
	else
		cout << "�����մϴ�." << endl;

	return 0;
}