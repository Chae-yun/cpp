#include <iostream>
using namespace std;
int main(){
	int num;
	cout << "숫자를 입력하시오 : ";
	cin >> num;
	if (num % 2 == 0)
		cout << num << "은(는) 짝수 입니다." << endl;
	else
		cout << num << "은(는) 홀수 입니다." << endl;
	return 0;
}