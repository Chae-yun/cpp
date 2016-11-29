#include <iostream>
using namespace std;


int main(){
	int a = 5;
	int &b = a; //별명 2개 3개 더 달아도 됨
	cout << a << "  " << b << endl;
	a = 10;
	cout << a << "  " << b << endl;
	b = 15;
	cout << a << "  " << b << endl;

	return 0;
}