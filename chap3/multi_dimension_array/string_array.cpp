#include <iostream>
using namespace std;

int main(){
	char szMessage1[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'a', 'r', 'r', 'a', 'y', 0 }; //�ϳ��� �� ���� �ݵ�� �� ǥ��!! ���ϸ� ���� ������ ��� ���
	char szMessage2[] = { "Hello array" };
	char szMessage3[] = "Hello array";

	cout << szMessage1 << endl << szMessage2 << endl << szMessage3 << endl;

	return 0;
}