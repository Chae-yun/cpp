#include <iostream>
using namespace std;
int main(){
	double sum = 0;
	for (int i = 1; i <= 100; i++){
		sum += (double)1 / i; //1.0/i�� �ǰ� i�� ����� �൵ ��??
	}
	cout << "�� �� : " << sum << endl;
	return 0;
}