#include <iostream>
using namespace std;
int main(){
	int num;
	cout << "숫자를 입력하시오 : ";
	cin >> num;
	if (num >= 1 && num <= 100)
		cout << num << "은(는) 1~100 입니다." << endl;
	else
		cout << num << "은(는) 1~100 이 아닙니다." << endl;
	return 0;
}