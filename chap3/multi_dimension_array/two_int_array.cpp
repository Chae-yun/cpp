#include <iostream>
using namespace std;

int main(){
	int nArray[2][3] = {
		{1,2,3},
		{4,5,6}
	};

	int *pArray1 = nArray[0];
	//int *pArray2 = nArray; //�� �̸����� ���󰡷��� 2�� ���󰡾� �ϱ� ������ ����
	//**pArray2�� �� �ȵ� �� ĭ �ǳʶپ�� �� �� �𸣰ŵ� *pArray2[3]�̶� �ؾ� ��
	//int *pArray3 = &nArray[0][0];
	//int *pArray4 = &nArray[0]; //�� �̸����� ���󰡷��� 2�� ���󰡾� �ϱ� ������ ����

	cout << nArray[0] << endl << nArray << endl << &nArray[0][0] << endl << &nArray[0] << endl <<*( pArray1+4);

	return 0;
}