#include <iostream>
using namespace std;
void main(){ //���� ���� �� �߰�ȣ �ΰ� �Ѳ����� �����

	//������ �Է¹޴� ���
	int value;
	cout << "���� �Է� : ";
	cin >> value;
	cout << "���� ��� : " << value << endl;

	//���ڿ��� �Է¹޴� ���
	char buffer[5]; //C���� �ٸ��� �߰����� �����ص� ����
	//4����Ʈ ���� �� �ִ�(�ΰ�), �ѱ��� 2����Ʈ, ����� 1����Ʈ
	cout << "���ڿ� �Է� : ";
	cin >> buffer;
	cout << "���ڿ� ��� : " << buffer << endl;
}