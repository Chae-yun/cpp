#include <iostream>
using namespace std;
int main(){
	char c;
	cout << "���� ���ڸ� �Է� : ";
	cin >> c;
	cout << (c-'0') << endl;
	//cout << char(100 - (c - '0')) << endl; //���� �ǹ�..?
	return 0;
}