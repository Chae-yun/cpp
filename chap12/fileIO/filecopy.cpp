#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream org("filecopy.cpp");

	if (!org.is_open())
		cout << "���� ������ �����ϴ�." << endl;

	//ofstream des("b.dat");
	ofstream des("b.dat", ios_base::out | ios_base::trunc | ios_base::binary);
	//���̳ʸ��� ���� �� ��������
	//�ٵ� ���Ͱ� �̻���..........

	char buf[1024];

	for (;;){
		org.read(buf, 1024);
		if (org.gcount() == 0)break;
		//���� ����� 0�̸� �����
		des.write(buf, org.gcount());
		//���⵵ 1024�ϸ� �̻��� �����⳪���ϱ� gcount()
	}

	org.close();
	des.close();

	return 0;
}