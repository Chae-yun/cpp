#include <iostream>
using namespace std;
int main(){
	int num;
	cout << "���ڸ� �Է��Ͻÿ� : ";
	cin >> num;
	if (num >= 1 && num <= 100)
		cout << num << "��(��) 1~100 �Դϴ�." << endl;
	else
		cout << num << "��(��) 1~100 �� �ƴմϴ�." << endl;
	return 0;
}