#include <iostream>
using namespace std;
int main(){

	int a, b;
	cout << "a�� �Է��Ͻÿ� : ";
	cin >> a;
	cout << "b�� �Է��Ͻÿ� : ";
	cin >> b;

	if (a+b>0){
		cout << "a : " << a << "    b : " << b << endl;

		int c;
		cout << "c�� �Է��Ͻÿ� : ";
		cin >> c;
		cout << "a+b-c=" << (a + b - c) << endl;
	}
	else{
		cout << "a+b>0�� �ǰ� �Է��Ͻÿ�" << endl;
	}

	return 0;
}