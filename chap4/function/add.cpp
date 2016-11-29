#include <iostream>
using namespace std;

int add(int, int); //여기 매개변수 이름 있어도 없어도 됨

int main(){
	int num1, num2;
	cout << "1번째 정수를 입력하세요 : ";
	cin >> num1;
	cout << "2번째 정수를 입력하세요 : ";
	cin >> num2;
	cout << "두 정수의 합은 " << add(num1, num2) << "입니다\n";
	return 0;
}

int add(int n1, int n2){
	return n1 + n2;
}