#include <iostream>
using namespace std;
int main(){
	//자기 자신을 제외한 약수의 합이 자기 자신인 수가 완전수 1~1000
	int count = 0;
	cout << "완전수 (1~1000)" << endl;
	for (int i = 1; i <= 1000; i++){
		int sum = 0;
		for (int j = 1; j <= i / 2; j++){
			if (i%j == 0)
				sum += j;
		}
		if (sum == i){
			cout << i << endl;
			count++;
		}
	}
	cout << endl << "1~1000의 완전수 개수 : " << count << endl;
	return 0;
}