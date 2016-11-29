#include <iostream>
using namespace std;
int main(){

	int num;
	cout << "임의의 수를 입력하시오 : ";
	cin >> num;

	if (num==0)
		cout << num << "입니다." << endl;
	else if (num > 0)
		cout << num << "은 양수입니다." << endl;
	else
		cout << num << "은 음수입니다." << endl;

	return 0;
}