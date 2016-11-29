#include <iostream>
using namespace std;
int main(){
	char X;
	cout << "문자를 입력하시오 : ";
	cin >> X;
	switch (X){
	case 'O':
		cout << "ONE" << endl;
		break;
	case 'T':
		cout << "TWO" << endl;
		break;
	case 'S':
		cout << "SIX" << endl;
		break;
	default:
		cout << "다시 입력하시오" << endl;
	}
	return 0;
}