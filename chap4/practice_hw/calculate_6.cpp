#include <iostream>
using namespace std;

double add(double, double);
double min(double, double);
double mul(double, double);
double div(double, double);

int main(){
	double one, two;

	cout << "->-> 사칙연산 기계 <-<-\n\n";
	cout << "첫 번째 숫자를 입력하시오 : ";
	cin >> one;
	cout << "두 번째 숫자를 입력하시오 : ";
	cin >> two;

	cout << "\n더하기 결과 : " << add(one, two) << endl;
	cout << "\n빼기 결과 : " << min(one, two) << endl;
	cout << "\n곱하기 결과 : " << mul(one, two) << endl;
	cout << "\n나누기 결과 : " << div(one, two) << endl << endl;
	return 0;
}

double add(double a, double b){
	return a + b;
}

double min(double a, double b){
	return a - b;
}

double mul(double a, double b){
	return a * b;
}

double div(double a, double b){
	if (b == 0)
		return 0;
	return a / b;
}