#include <iostream>
using namespace std;
int main(){
	int num;
	cout << "���ڸ� �Է��Ͻÿ� : ";
	cin >> num;
	if (num % 2 == 0)
		cout << num << "��(��) ¦�� �Դϴ�." << endl;
	else
		cout << num << "��(��) Ȧ�� �Դϴ�." << endl;
	return 0;
}