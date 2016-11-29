#include <iostream>
using namespace std;

int main(){
	char szMessage[][20] = { "Hello array", "안녕하세요" }; //열의 개수는 다 다르기 때문에 꼭 써야 하고 행의 개수는 컴마로 셀 수 있다!

	cout << szMessage[0] << endl << szMessage[1] << endl;
	cout << szMessage << endl; //두 개중에 뭘 찍어야 할 지 몰라서 주소 찍음 1차원에서는 주소 찍기 어려웠는데 2차원은 첫주소 찍기 쉬움
	cout << &szMessage[1] << endl; //차이는 20
	cout << &szMessage[0][10] << endl; //이건 안되네!!

	return 0;
}