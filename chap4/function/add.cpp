#include <iostream>
using namespace std;

int add(int, int); //���� �Ű����� �̸� �־ ��� ��

int main(){
	int num1, num2;
	cout << "1��° ������ �Է��ϼ��� : ";
	cin >> num1;
	cout << "2��° ������ �Է��ϼ��� : ";
	cin >> num2;
	cout << "�� ������ ���� " << add(num1, num2) << "�Դϴ�\n";
	return 0;
}

int add(int n1, int n2){
	return n1 + n2;
}