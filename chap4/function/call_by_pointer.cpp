#include <iostream>
using namespace std;

void func(int *a){
	*a = *a + 1;
}

int main(){
	int num = 1;
	func(&num); //�����ͷ� ���������ϱ� �ּҸ� ����
	cout << num << endl;
	return 0;
}