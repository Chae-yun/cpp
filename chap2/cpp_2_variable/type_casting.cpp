#include <iostream>
using namespace std;
int main(){
	/*short s = 100;
	char c;
	c=s;*/ //워닝

	/*short s = 100;
	char c = 'A';
	s = c;*/ //워닝X

	int i = 3;
	float f = 3.1f; //f 붙이면 잘립니다 워닝 없어짐 (실수의 기본형은 double 이기 때문에 워닝)
	//i = f; //워닝
	f = i; //워닝이 나지만 대부분 float 로 들어갈 수 있다.
	long l = 1000;
	i = l; //같은 타입으로 본다

	return 0;
}