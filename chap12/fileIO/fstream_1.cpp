#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

int main(){
	char szBuf[100];
	strcpy(szBuf, "12345 Hello File"); //�������

	//ofstream outfile("out.dat"); //������ ���� (��ü ����, ���� ����)
	//outfile << szBuf << endl; //���Ͽ� ����
	//outfile.close(); //���� �ݱ�
	//3�ܰ�

	ofstream abc; //��ü ����
	abc.open("out.dat",ios_base::app); //���� ����
	abc << szBuf << endl; //���Ͽ� ����
	abc.close(); //���� �ݱ�
	//4�ܰ�

	ifstream infile("out.dat"); //���� ���� (��ü ����, ���� ����)
	infile.getline(szBuf, 100); //���� �б�
	infile.close(); //���� �ݱ�

	cout << "Read File : " << szBuf << endl; //���� ���� ���� ���

	return 0;
}