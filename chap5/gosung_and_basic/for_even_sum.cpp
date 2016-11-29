#include <iostream>
using namespace std;
int main(){
	int i;
	int sum = 0; //중요중요 곱은 1
	for (i = 1; i <= 100; i++){
		if (i % 2 == 0)
			sum += i;
	}
	cout << "1부터 100까지의 짝수의 합은 " << sum << "입니다" << endl;
	return 0;
}