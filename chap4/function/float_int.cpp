#include <iostream>
using namespace std;

int func(int, int); //���� �Ű����� �̸� �־ ��� ��

int main(){
	cout << func(8, 5) << endl;
	return 0;
}

int func(int n1, int n2){
	float div;
	div = n1 / n2; //�߸�
	return div;
}