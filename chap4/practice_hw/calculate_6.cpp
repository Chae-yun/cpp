#include <iostream>
using namespace std;

double add(double, double);
double min(double, double);
double mul(double, double);
double div(double, double);

int main(){
	double one, two;

	cout << "->-> ��Ģ���� ��� <-<-\n\n";
	cout << "ù ��° ���ڸ� �Է��Ͻÿ� : ";
	cin >> one;
	cout << "�� ��° ���ڸ� �Է��Ͻÿ� : ";
	cin >> two;

	cout << "\n���ϱ� ��� : " << add(one, two) << endl;
	cout << "\n���� ��� : " << min(one, two) << endl;
	cout << "\n���ϱ� ��� : " << mul(one, two) << endl;
	cout << "\n������ ��� : " << div(one, two) << endl << endl;
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