#include <iostream>
#include <time.h>
using namespace std;

void myRand(int, int);

int main(){
	int start, end;
	cout << "시작할 숫자를 입력하세요(크거나 같음) : ";
	cin >> start;
	cout << "끝낼 숫자를 입력하세요(작음) : ";
	cin >> end;

	myRand(start, end);

	return 0;
}

void myRand(int n1, int n2){
	srand((unsigned)time(0));

	for (int i = 0; i < 10; i++){
		cout << i << " : 난수값 : " << (n1 + (rand() % (n2 - n1))) << endl; //리턴값은 int 0~32767
	}
}