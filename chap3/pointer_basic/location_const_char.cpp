#include <iostream>
using namespace std;
int main(){
	char a = 'Z';
	const char* p1 = &a; //ĳ���� �ϳ��� �����ͷ� ������� ���� ����Ϸ��� ���� �־���� ��
	cout << p1 << endl;

	return 0;
}