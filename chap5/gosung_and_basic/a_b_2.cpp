#include <iostream>
using namespace std;
int main(){

	int a, b;
	cout << "a를 입력하시오 : ";
	cin >> a;
	cout << "b를 입력하시오 : ";
	cin >> b;

	if (a+b>0){
		cout << "a : " << a << "    b : " << b << endl;

		int c;
		cout << "c를 입력하시오 : ";
		cin >> c;
		cout << "a+b-c=" << (a + b - c) << endl;
	}
	else{
		cout << "a+b>0이 되게 입력하시오" << endl;
	}

	return 0;
}