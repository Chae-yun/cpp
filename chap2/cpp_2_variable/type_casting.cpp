#include <iostream>
using namespace std;
int main(){
	/*short s = 100;
	char c;
	c=s;*/ //����

	/*short s = 100;
	char c = 'A';
	s = c;*/ //����X

	int i = 3;
	float f = 3.1f; //f ���̸� �߸��ϴ� ���� ������ (�Ǽ��� �⺻���� double �̱� ������ ����)
	//i = f; //����
	f = i; //������ ������ ��κ� float �� �� �� �ִ�.
	long l = 1000;
	i = l; //���� Ÿ������ ����

	return 0;
}