#include <iostream>
using namespace std;
int main(){
	int a[] = { 1, 2, 3, 4, 5 };
	const int* p1 = &a[0]; //������ ���ٲ�
	cout << p1 << endl;
	//cout << a << endl; //�迭�� ��ü�� ������ �ʴ� �迭�� ù �ּҸ� �ǹ� (������ ���)
	//cout << &a[0] << endl; //�� �ᱹ ���ǹǷ� a�� ����
	//cout << &a[1] << endl; //�� �渶�� ������ Ÿ�Ը�ŭ �ּ� ���̳�
	p1++; //�ּҴ� ������ �� �ִ�
	cout << p1 << endl;
	//*p1 = 5; //���� �ٲٷ��ϱ� ����

	cout << "---------\n";

	int* const p2 = &a[0]; //�ּҸ� ���ٲ�
	cout << p2 << endl;
	//p2++; //�ּ� �ٲٷ��ϱ� ����
	*p2 = 5; //������ ������ �� �ִ�
	cout << *p2 << endl;

	cout << "---------\n";

	const int* const p3 = &a[0]; //�ּҸ� ���ٲ�
	cout << p3 << endl;
	//p3++; //�ּ� �ٲٷ��ϱ� ����
	//*p3 = 5; //���� �ٲٷ��ϱ� ����

	return 0;
}