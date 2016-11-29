#include<iostream>
using namespace std;
struct POINT{
	int x;
	int y;
}; //여기까지는 메모리가 잡히지 않음 그러나 사이즈는 나옴

POINT p; //전역으로 선언하면 기본이 0

int main(){
	//POINT p; 지역으로 선언하면 초기화 되지 않았다고 에러!
	cout << p.x << endl;
	cout << sizeof(POINT) << endl;
	cout << sizeof(p) << endl; //둘중 아무거나 상관없음

	return 0;
}