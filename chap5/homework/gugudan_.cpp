#include <iostream>
using namespace std;
int main(){
	while(true){
		char input[10];
		cout << "출력을 원하는 단을 입력하시오 (0은 1~9단 모두 출력, x는 종료) : ";
		cin >> input;
		if (strlen(input) > 1)
			cout << endl << "범위에서 벗어났습니다" << endl << "0~9 혹은 x만 입력해주십시오" << endl << endl;
		else if (toupper(input[0]) == 'X'){
			cout << "종료합니다" << endl;
			break;
		}
		else if (input[0] == '0'){
			cout << endl << "1~9단 출력" << endl;
			for (int i = 1; i <= 9; i++){
				cout << endl << i << "단 출력" << endl;
				for (int j = 1; j <= 9; j++)
					cout << i << " X " << j << " = " << (i*j) << endl;
			}
			cout << endl;
		}
		else if (input[0] >= '1' && input[0] <= '9'){
			cout << endl << input << "단 출력" << endl;
			for (int i = 1; i <= 9; i++)
				cout << input << " X " << i << " = " << (input[0] * i) << endl;
			cout << endl;
		}
		else
			cout << endl << "범위에서 벗어났습니다" << endl << "0~9 혹은 x만 입력해주십시오" << endl << endl;
	}
	return 0;
}