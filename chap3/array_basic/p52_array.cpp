#include <iostream>
using namespace std;
int main(){
	//int nArray[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; //�̷��� �� ���� ������ �Ƚᵵ OK
	int nArray[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int nArray[10] = { 0, }; //�̷��� �� 0���� �ʱ�ȭ ','��� �Ǵµ�??
	//�׷��� �� 1�� �ϰų� �̷���� �� ��� �ȵǰ� �ݺ��� ������ ��
	//int nArray[10]; //��ü������ �ʱ�ȭ�� �Ƚ�����
	int count = sizeof(nArray) / sizeof(int);
	
	for (int i = 0; i < count; i++)
		cout << i << " : " << nArray[i] << endl;

	cout << sizeof(nArray) << endl;

	return 0;
}