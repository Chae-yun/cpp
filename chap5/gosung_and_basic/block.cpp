#include <iostream>
using namespace std;
int main(){
	int a = 10;
	cout << a << endl;
	{
		int a = 20; //�� ��� ���� ��������
		cout << a << endl; //�ȿ����� �ȿ��� ������ ���� �켱��
	} //�ϳ��� �ڵ� ���
	cout << a << endl;
	return 0;
}