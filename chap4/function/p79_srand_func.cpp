#include <iostream>
#include <time.h>
using namespace std;

int main(){
	srand((unsigned)time(0)); //void srand(unsigned int _seed)
	//time_t time(time_t *const_time) 1970�� 1�� 1�� ���� �帥 �ð�(��)�� 64��Ʈ ���������� ����
	//time_t�� ���� ��ŷ ��� ���󰡺��� �ǹ� ����
	//���� 0�� ���� �ǹ�??? �� �˻��غ�

	for (int i = 0; i < 10; i++){
		cout << i << " : ������ : " << rand() << endl; //���ϰ��� int 0~32767
	}
	return 0;
}