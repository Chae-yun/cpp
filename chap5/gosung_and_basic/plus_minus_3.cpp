#include <iostream>
using namespace std;
int main(){

	int num;
	cout << "������ ���� �Է��Ͻÿ� : ";
	cin >> num;

	if (num==0)
		cout << num << "�Դϴ�." << endl;
	else if (num > 0)
		cout << num << "�� ����Դϴ�." << endl;
	else
		cout << num << "�� �����Դϴ�." << endl;

	return 0;
}