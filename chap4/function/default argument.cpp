#include <iostream>
using namespace std;

void print1(int a, int b = 0, int c = 0, int d); //d�� ����Ÿ ������ ��
void print2(int a, int b, int c = 0, int d = 0);
void print3(int a = 1, int b, int c = 0, int d = 0); //b�� ����Ÿ ������ ��
void print4(int a = 1, int b = 2, int c = 3, int d = 4);
//�׻� ������������ ������� �⺻ ���� ������ ��� �Ѵ�

void print(){}
void print(int a = 1, int b = 2){}

int main(){
	print(); //�ؿ� �͵� �� �־ ��� �����ϱ� ������ ������ ���� ��!

	return 0;
}