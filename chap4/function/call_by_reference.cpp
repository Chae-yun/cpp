#include <iostream>
using namespace std;

void func(int &a){
	a = a + 1;
} //a�� num�̶� �̸��� �ٸ����� ���� ������ ��
//p83

int main(){
	int num = 1;
	func(num);
	cout << num << endl;
	return 0;
}