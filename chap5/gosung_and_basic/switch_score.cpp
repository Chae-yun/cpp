#include <iostream>
using namespace std;
int main(){
	int score;
	cout << "점수를 입력하시오 : ";
	cin >> score;

	char c;
	if (score >= 0 && score <= 100){
		score /= 10; //배수 구할 때도 많이 쓰임
		switch (score){ //범위 설정을 먼저 해주는 것이 중요하다
		case 10: case 9:
				c = 'A';
				break;
		case 8:
				c = 'B';
				break;
		case 7:
				c = 'C';
				break;
		case 6:
				c = 'D';
				break;
		default:
				c = 'F';
			
		}
		cout << c << "등급입니다." << endl;
	}
	else
		cout << "점수는 0~100까지만 입력하시오" << endl;
	return 0;
}