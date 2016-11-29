#include <iostream>
using namespace std;
void main(){ //메인 만들 때 중괄호 두개 한꺼번에 만들기

	//정수를 입력받는 경우
	int value;
	cout << "정수 입력 : ";
	cin >> value;
	cout << "정수 출력 : " << value << endl;

	//문자열을 입력받는 경우
	char buffer[5]; //C언어와 다르게 중간에서 선언해도 괜찮
	//4바이트 넣을 수 있다(널값), 한글은 2바이트, 영어는 1바이트
	cout << "문자열 입력 : ";
	cin >> buffer;
	cout << "문자열 출력 : " << buffer << endl;
}