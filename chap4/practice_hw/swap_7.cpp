#include <iostream>
using namespace std;

void c_b_pointer(double* a, double* b);
void c_b_reference(double& a, double& b);

int main(){
	double one, two;

	cout << "->-> 숫자 바꾸는 기계 <-<-\n\n";
	cout << "첫 번째 숫자를 입력하시오 : ";
	cin >> one;
	cout << "두 번째 숫자를 입력하시오 : ";
	cin >> two;

	c_b_pointer(&one, &two);

	cout << "\nCall by pointer 결과 : " << one << "  " << two << endl;

	cout << "\n첫 번째 숫자를 입력하시오 : ";
	cin >> one;
	cout << "두 번째 숫자를 입력하시오 : ";
	cin >> two;

	c_b_reference(one, two); //음 얘는 위에서 (double, double)이렇게 주면 2개라고 못 찾는다!

	cout << "\nCall by reference 결과 : " << one << "  " << two << endl << endl;

	return 0;
}

void c_b_pointer(double* a, double* b){
	double temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void c_b_reference(double& a, double& b){
	double temp;
	temp = a;
	a = b;
	b = temp;
}