#include <iostream>
using namespace std;
int main(){
	char* pMessage = "welcome to korea";
	cout << "*pMessage : " << *pMessage << endl;
	cout << "*(pMessage+1) : " << *(pMessage + 1) << endl;
	cout << "pMessage+1 : " << *pMessage + 1 << endl;
	cout << "*(pMessage+8) : " << *(pMessage + 8) << endl;
	cout << "pMessage : " << pMessage << endl; //���ڿ��� �ּҰ� ������ �ʰ� ���� ������ ��°�� ���� �⺻Ÿ���� �ּҳ���
	cout << "pMessage : " << &(*pMessage) << endl; //�̷��� �ϸ� �׳� &*������ ������ ���ڿ��� �ּ�ã�� ��ƴ�

	cout << "\n�Ʒ����" << endl;
	for (int i = 0; *(pMessage + i); i++)
		//cout << *(pMessage + i) << endl;
		cout << pMessage[i] << endl; //�̷��� �迭�� �ᵵ ���� (&* ó�� &[]�� ����Ŵ)
	//�����Ϳ� �迭�� ȣȯ��

	return 0;
}