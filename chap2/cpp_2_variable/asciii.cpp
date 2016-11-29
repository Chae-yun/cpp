#include <iostream>
using namespace std;
int main(){
	char c;
	cout << "숫자 한자리 입력 : ";
	cin >> c;
	cout << (c-'0') << endl;
	//cout << char(100 - (c - '0')) << endl; //무슨 의미..?
	return 0;
}