#include <iostream>
using namespace std;
int main(){
	int score;
	cout << "점수를 입력하시오 : ";
	cin >> score;

	/*if (score<0 || score>100) //범위 설정을 먼저 해주는 것이 중요하다
		cout << "점수는 0~100까지만 입력하시오" << endl;
	else if (score>=90)
		cout << "A등급입니다" << endl;
	else if (score >= 80)
		cout << "B등급입니다" << endl;
	else if (score >= 70)
		cout << "C등급입니다" << endl;
	else if (score >= 60)
		cout << "D등급입니다" << endl;
	else
		cout << "F등급입니다" << endl;*/

	char c;
	if (score >= 0 && score <= 100){ //범위 설정을 먼저 해주는 것이 중요하다
		if (score >= 90)
			c = 'A';
		else if (score >= 80)
			c = 'B';
		else if (score >= 70)
			c = 'C';
		else if (score >= 60)
			c = 'D';
		else
			c = 'F';
		cout << c << "등급입니다." << endl;
	}
	else
		cout << "점수는 0~100까지만 입력하시오" << endl;

	return 0;
}