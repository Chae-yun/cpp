#include <iostream>
using namespace std;
int main(){
	int month;
	cout << "마지막 날을 알고싶은 달을 입력하시오 : ";
	cin >> month;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		cout << month << "월의 마지막 날은 31일 입니다" << endl;
	else if(month==2)
		cout << month << "월의 마지막 날은 28일 입니다" << endl;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		cout << month << "월의 마지막 날은 30일 입니다" << endl;
	else
		cout << "1~12의 숫자만 입력하십시오" << endl;
	return 0;
}