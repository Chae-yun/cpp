#include <iostream>
using namespace std;
int main(){
	int month;
	cout << "������ ���� �˰���� ���� �Է��Ͻÿ� : ";
	cin >> month;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		cout << month << "���� ������ ���� 31�� �Դϴ�" << endl;
	else if(month==2)
		cout << month << "���� ������ ���� 28�� �Դϴ�" << endl;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		cout << month << "���� ������ ���� 30�� �Դϴ�" << endl;
	else
		cout << "1~12�� ���ڸ� �Է��Ͻʽÿ�" << endl;
	return 0;
}