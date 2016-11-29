#include <iostream>
using namespace std;

int main(){
	for (int i = 0; i < 10; i++){
		cout << i << " : 난수값 : " << rand() << endl; //int rand() 0~32767
	} //rand 함수의 난수 알고리즘의 기준값인 seed값은 컴퓨터마다, 시간마다 다 똑같아서 껐다 켜도 항상 같은 난수 발생
	return 0;
}