#include <iostream>
using namespace std;

int nValue = 10;
//static int nValue = 10; //������ �Ȱ���

void subFuncA(){
	static int nValA = 20;
	//cout << nValue << ", " << nValA << ", " << nValB << ", " << nValM << endl;
	nValA++;
	cout << nValA << endl;
}

void subFuncB(){
	int nValB = 30;
	//cout << nValue << ", " << nValA << ", " << nValB << ", " << nValM << endl;
	nValB++;
	cout << nValB << endl;
}

int main(){
	int nValM = 40;
	//cout << nValue << ", " << nValA << ", " << nValB << ", " << nValM << endl; //nValA �� nValB �� ��������
	cout << nValue << ", " << nValM << endl;
	nValue++;
	//nValA++;
	//nValB++;
	nValM++;
	subFuncA();
	subFuncB();
	cout << nValue << ", " << nValM << endl;
	cout << "-----------------------------------------\n";
	nValue++;
	//nValA++; //������ ������ ����;
	//nValB++;
	nValM++;
	subFuncA(); //�ʱ�ȭ �ȵ�
	subFuncB(); //�ٽ� 30���� �ʱ�ȭ�Ǽ� 31���
	cout << nValue << ", " << nValM << endl;
	return 0;
}