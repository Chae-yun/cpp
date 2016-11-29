#include <iostream>
using namespace std;

void func(int &a){
	a = a + 1;
} //a랑 num이랑 이름은 다르지만 같은 변수가 됨
//p83

int main(){
	int num = 1;
	func(num);
	cout << num << endl;
	return 0;
}