#include <iostream>
using namespace std;
int main(){
	char X;
	cout << "���ڸ� �Է��Ͻÿ� : ";
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
		cout << "�ٽ� �Է��Ͻÿ�" << endl;
	}
	return 0;
}