#include <iostream>
using namespace std;

void print1(int a, int b = 0, int c = 0, int d); //d에 데이타 넣으면 됨
void print2(int a, int b, int c = 0, int d = 0);
void print3(int a = 1, int b, int c = 0, int d = 0); //b에 데이타 넣으면 됨
void print4(int a = 1, int b = 2, int c = 3, int d = 4);
//항상 우측에서부터 순서대로 기본 값을 지정해 줘야 한다

void print(){}
void print(int a = 1, int b = 2){}

int main(){
	print(); //밑에 것도 안 넣어도 사용 가능하기 때문에 에러가 나는 것!

	return 0;
}