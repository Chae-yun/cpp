#include<iostream>
#define PI 3.14
using namespace std;
int main(){
	int a;
	cout << "원의 반지름을 입력하시오 : ";
	cin >> a;
	cout << "원의 면적 : " << a*a*PI << endl;
	return 0;
}