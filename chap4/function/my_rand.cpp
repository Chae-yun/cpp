#include <iostream>
#include <time.h>
using namespace std;

void myRand(int, int);

int main(){
	int start, end;
	cout << "������ ���ڸ� �Է��ϼ���(ũ�ų� ����) : ";
	cin >> start;
	cout << "���� ���ڸ� �Է��ϼ���(����) : ";
	cin >> end;

	myRand(start, end);

	return 0;
}

void myRand(int n1, int n2){
	srand((unsigned)time(0));

	for (int i = 0; i < 10; i++){
		cout << i << " : ������ : " << (n1 + (rand() % (n2 - n1))) << endl; //���ϰ��� int 0~32767
	}
}