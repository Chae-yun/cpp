#include <iostream>
using namespace std;

int main(){
	char szMessage[][20] = { "Hello array", "�ȳ��ϼ���" }; //���� ������ �� �ٸ��� ������ �� ��� �ϰ� ���� ������ �ĸ��� �� �� �ִ�!

	cout << szMessage[0] << endl << szMessage[1] << endl;
	cout << szMessage << endl; //�� ���߿� �� ���� �� �� ���� �ּ� ���� 1���������� �ּ� ��� ������µ� 2������ ù�ּ� ��� ����
	cout << &szMessage[1] << endl; //���̴� 20
	cout << &szMessage[0][10] << endl; //�̰� �ȵǳ�!!

	return 0;
}