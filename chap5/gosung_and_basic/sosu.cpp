#include <iostream>
using namespace std;
int main(){
	int count = 0;

	cout << "1~100 사이의 소수 : "<<endl;

	cout << 2 << endl;

	/*for (int i = 3; i <= 100; i += 2){ //와일로 바꾸면 초기화는 밖으로 조건문은 와일 조건문으로 증감식은 와일 안에 하지만 포문이 바람직
		int judge = 0;

		for (int j = 3; j <= i / 2; j++){
			if (i%j == 0)
				judge++;
		}

		if (judge == 0){
			cout << i << endl;
			count++;
		}
	}*/

	for (int i = 3; i <= 100; i+=2){ //와일로 바꾸면 초기화는 밖으로 조건문은 와일 조건문으로 증감식은 와일 안에 하지만 포문이 바람직
		bool flg = true;

		for (int j = 3; j <= i/2; j++){
			if (i%j == 0)
				flg = false; break;
		}

		if (flg == true){
			cout << i << endl;
			count++;
		}
	} //효율적인 방법 i+=2 안하고 i++하면 2배로 늘어남 flg쓴 것도 회수 줄어듦

	cout << "1~100 사이의 소수의 개수는 " << count << "개입니다." << endl;

	return 0;
}