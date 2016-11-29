#include <iostream>
using namespace std;
int main(){
	char a = 'Z';
	const char* p1 = &a; //캐릭터 하나는 포인터로 사용하지 않음 사용하려면 널을 넣어줘야 함
	cout << p1 << endl;

	return 0;
}