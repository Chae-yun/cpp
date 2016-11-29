#include <iostream>
using namespace std;

void func(int *a){
	*a = *a + 1;
}

int main(){
	int num = 1;
	func(&num); //포인터로 선언했으니까 주소를 전달
	cout << num << endl;
	return 0;
}