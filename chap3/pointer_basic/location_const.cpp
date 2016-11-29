#include <iostream>
using namespace std;
int main(){
	int a[] = { 1, 2, 3, 4, 5 };
	const int* p1 = &a[0]; //내용을 못바꿈
	cout << p1 << endl;
	//cout << a << endl; //배열명 자체가 변하지 않는 배열의 첫 주소를 의미 (포인터 상수)
	//cout << &a[0] << endl; //뭐 결국 상쇄되므로 a와 같다
	//cout << &a[1] << endl; //한 방마다 데이터 타입만큼 주소 차이남
	p1++; //주소는 변경할 수 있다
	cout << p1 << endl;
	//*p1 = 5; //내용 바꾸려니까 에러

	cout << "---------\n";

	int* const p2 = &a[0]; //주소를 못바꿈
	cout << p2 << endl;
	//p2++; //주소 바꾸려니까 에러
	*p2 = 5; //내용은 변경할 수 있다
	cout << *p2 << endl;

	cout << "---------\n";

	const int* const p3 = &a[0]; //주소를 못바꿈
	cout << p3 << endl;
	//p3++; //주소 바꾸려니까 에러
	//*p3 = 5; //내용 바꾸려니까 에러

	return 0;
}