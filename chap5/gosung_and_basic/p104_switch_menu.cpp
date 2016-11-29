#include <iostream>
using namespace std;
int main(){
	int menuNo;

	cout << "********************" << endl;
	cout << "메뉴" << endl;
	cout << endl;
	cout << "[1] 자장면" << endl;
	cout << "[2] 짬  뽕" << endl;
	cout << "[3] 울  면" << endl;
	cout << "[4] 탕수육" << endl;
	cout << endl;
	cout << "********************" << endl;
	cout << endl;

	cout << "메뉴 번호를 입력 하세요 : ";

	cin >> menuNo;

	switch (menuNo){
	case 1:
		cout << "자장면을 선택 하셨습니다." << endl;
		break;
	case 2:
		cout << "짬뽕을 선택 하셨습니다." << endl;
		break;
	case 3:
		cout << "울면을 선택 하셨습니다." << endl;
		break;
	case 4:
		cout << "탕수육을 선택 하셨습니다." << endl;
		break;
	default:
		cout << "잘못 입력 하셨습니다." << endl;
		break;
	}
	return 0;
}