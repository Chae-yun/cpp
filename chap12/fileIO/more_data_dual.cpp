#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int nCount = 10;
	int nNo;
	char szName[20];

	fstream file; //���� ����
	file.open("out3.dat", ios_base::out | ios_base::in | ios_base::trunc); //���� ����
	//in, out ��ô� �����
	//trunc�� ���ϸ� ������ �Ȼ����.....
	for (int i = 0; i < nCount; i++){
		nNo = i + 1;
		sprintf(szName, "�̸�_%d", nNo);
		file << nNo << szName << endl; //���Ͽ� ����
	}

	file.seekg(0, ios_base::beg);
	//Ŀ���� ó������ �����ش�
	//ó�� �Ű������� offset(�ι�°���� �󸶳� ������ ������ �����ð���, �ι�° �Ű������� �о�� ������)

	for (int i = 0; i < nCount; i++){
		file >> nNo;
		file >> szName; //���� �б�
		cout << i << " : " << nNo << ", " << szName << endl;
	}
	file.close(); //���� �ݱ�

	return 0;
}