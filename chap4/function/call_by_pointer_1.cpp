#include <iostream>
using namespace std;

void test1(int*);

int main(){
	int x = 10;
	cout << "Before test1 : " << x << endl;
	test1(&x);
	cout << "After test1 : " << x << endl;

	return 0;
}

void test1(int* x){
	//*x++; //++이 우선순위상 먼저라서 주소를 증가시키고 내용을 가져오니까 쓰레기값!
	(*x)++; //옳은 표현!
	cout << "In test1 : " << *x << endl;
}