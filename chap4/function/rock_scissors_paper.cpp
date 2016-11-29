#include <iostream>
#include <time.h>
using namespace std;

int one_two_three(char*);
void who_winner(int);

int main(){

	char rcp[5];
	int my_num;

	while (true){
		cout << "가위, 바위, 보 중에서 하나 입력하세요 (다른 것을 입력하면 종료) : ";
		cin >> rcp;
		my_num = one_two_three(rcp);
		if (my_num == 0){
			cout << "\n종료합니다\n\n";
			break;
		}
		who_winner(my_num);
	}

	return 0;

}

int one_two_three(char* rcp){

	if (!strcmp(rcp, "가위"))
		return 1;
	else if (!strcmp(rcp, "바위"))
		return 2;
	else if (!strcmp(rcp, "보"))
		return 3;
	else return 0;

}

void who_winner(int num){

	int ran;
	static int win = 0, lose = 0, equal = 0;
	srand((unsigned)time(0));
	ran = 1 + (rand() % 3);

	if (ran == 1)
		cout << "\n컴퓨터 : 가위\n\n";
	else if (ran == 2)
		cout << "\n컴퓨터 : 바위\n\n";
	else
		cout << "\n컴퓨터 : 보\n\n";

	if (ran == num){
		cout << "비겼습니다\n\n";
		equal++;
	}
	else if (ran == 1 && num == 3){
		cout << "컴퓨터가 이겼습니다\n\n";
		lose++;
	}
	else if (ran == 3 && num == 1){
		cout << "당신이 이겼습니다\n\n";
		win++;
	}
	else if (ran > num){
		cout << "컴퓨터가 이겼습니다\n\n";
		lose++;
	}
	else{
		cout << "당신이 이겼습니다\n\n";
		win++;
	}

	cout << win << "승 " << equal << "무 " << lose << "패\n\n";
	cout << "-----------------------------------------------------------------------\n\n";

}
//aaron753@naver.com