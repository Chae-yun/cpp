#include <iostream>
using namespace std;

int main(){
	for (int i = 0; i < 10; i++){
		cout << i << " : ������ : " << rand() << endl; //int rand() 0~32767
	} //rand �Լ��� ���� �˰����� ���ذ��� seed���� ��ǻ�͸���, �ð����� �� �Ȱ��Ƽ� ���� �ѵ� �׻� ���� ���� �߻�
	return 0;
}