#include <iostream>
using namespace std;

void c_b_pointer(double* a, double* b);
void c_b_reference(double& a, double& b);

int main(){
	double one, two;

	cout << "->-> ���� �ٲٴ� ��� <-<-\n\n";
	cout << "ù ��° ���ڸ� �Է��Ͻÿ� : ";
	cin >> one;
	cout << "�� ��° ���ڸ� �Է��Ͻÿ� : ";
	cin >> two;

	c_b_pointer(&one, &two);

	cout << "\nCall by pointer ��� : " << one << "  " << two << endl;

	cout << "\nù ��° ���ڸ� �Է��Ͻÿ� : ";
	cin >> one;
	cout << "�� ��° ���ڸ� �Է��Ͻÿ� : ";
	cin >> two;

	c_b_reference(one, two); //�� ��� ������ (double, double)�̷��� �ָ� 2����� �� ã�´�!

	cout << "\nCall by reference ��� : " << one << "  " << two << endl << endl;

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