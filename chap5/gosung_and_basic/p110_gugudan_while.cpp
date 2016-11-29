#include <iostream>
using namespace std;
int main(){
	int dan;

	while(1){ //while(true)와 같다
		cout << "무한 루프를 이용한 구구단 출력 프로그램입니다." << endl;
		cout << "0을 입력 하면 종료 합니다." << endl;
		cout << "출력할 단을 입력 하세요(1~19) : ";

		cin >> dan;

		if (dan == 0){
			cout << "구구단 출력을 종료 합니다." << endl;
			break;
		}

		if (dan < 1 || dan>19){
			cout << "다시 실행합니다" << endl;
			continue;
		} //여기 변형

		cout << dan << "을 출력합니다." << endl;

		for (int i = 1; i <= 9; i++){
			cout << "    " << dan << " * " << i << " = " << (dan*i) << endl;
		}
	}

	return 0;
}