#include<iostream>
using namespace std;

struct SQUARE{
	int x1, y1;
	int x2, y2;
	int x3, y3;
	int x4, y4;
};

int main(){
	SQUARE s;
	cout << "사각형의 첫번째 좌표를 입력하시오 : ";
	cin >> s.x1 >> s.y1;
	cout << "사각형의 두번째 좌표를 입력하시오 : ";
	cin >> s.x2 >> s.y2;
	cout << "사각형의 세번째 좌표를 입력하시오 : ";
	cin >> s.x3 >> s.y3;
	cout << "사각형의 네번째 좌표를 입력하시오 : ";
	cin >> s.x4 >> s.y4;

	cout << "사각형의 좌표 : ( "
		<< s.x1 << ", " << s.y1 << " ), ( "
		<< s.x2 << ", " << s.y2 << " ), ( "
		<< s.x3 << ", " << s.y3 << " ), ( "
		<< s.x4 << ", " << s.y4 << " )" << endl;

	return 0;
}