#include <iostream>
using namespace std;

int func(int, int); //여기 매개변수 이름 있어도 없어도 됨

int main(){
	cout << func(8, 5) << endl;
	return 0;
}

int func(int n1, int n2){
	float div;
	div = n1 / n2; //잘림
	return div;
}