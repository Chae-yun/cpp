#include <iostream>
#include <time.h>
using namespace std;

int one_two_three(char*);
void who_winner(int);

int main(){

	char rcp[5];
	int my_num;

	while (true){
		cout << "����, ����, �� �߿��� �ϳ� �Է��ϼ��� (�ٸ� ���� �Է��ϸ� ����) : ";
		cin >> rcp;
		my_num = one_two_three(rcp);
		if (my_num == 0){
			cout << "\n�����մϴ�\n\n";
			break;
		}
		who_winner(my_num);
	}

	return 0;

}

int one_two_three(char* rcp){

	if (!strcmp(rcp, "����"))
		return 1;
	else if (!strcmp(rcp, "����"))
		return 2;
	else if (!strcmp(rcp, "��"))
		return 3;
	else return 0;

}

void who_winner(int num){

	int ran;
	static int win = 0, lose = 0, equal = 0;
	srand((unsigned)time(0));
	ran = 1 + (rand() % 3);

	if (ran == 1)
		cout << "\n��ǻ�� : ����\n\n";
	else if (ran == 2)
		cout << "\n��ǻ�� : ����\n\n";
	else
		cout << "\n��ǻ�� : ��\n\n";

	if (ran == num){
		cout << "�����ϴ�\n\n";
		equal++;
	}
	else if (ran == 1 && num == 3){
		cout << "��ǻ�Ͱ� �̰���ϴ�\n\n";
		lose++;
	}
	else if (ran == 3 && num == 1){
		cout << "����� �̰���ϴ�\n\n";
		win++;
	}
	else if (ran > num){
		cout << "��ǻ�Ͱ� �̰���ϴ�\n\n";
		lose++;
	}
	else{
		cout << "����� �̰���ϴ�\n\n";
		win++;
	}

	cout << win << "�� " << equal << "�� " << lose << "��\n\n";
	cout << "-----------------------------------------------------------------------\n\n";

}
//aaron753@naver.com