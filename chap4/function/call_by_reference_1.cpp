#include <iostream>
using namespace std;


int main(){
	int a = 5;
	int &b = a; //���� 2�� 3�� �� �޾Ƶ� ��
	cout << a << "  " << b << endl;
	a = 10;
	cout << a << "  " << b << endl;
	b = 15;
	cout << a << "  " << b << endl;

	return 0;
}