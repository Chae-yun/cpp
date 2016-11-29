#include <iostream>
#include <time.h>
using namespace std;

int main(){
	srand((unsigned)time(0)); //void srand(unsigned int _seed)
	//time_t time(time_t *const_time) 1970년 1월 1일 부터 흐른 시간(초)을 64비트 정수형으로 리턴
	//time_t의 정의 패킹 계속 따라가보면 의미 나옴
	//안의 0은 무슨 의미??? 꼭 검색해봐

	for (int i = 0; i < 10; i++){
		cout << i << " : 난수값 : " << rand() << endl; //리턴값은 int 0~32767
	}
	return 0;
}