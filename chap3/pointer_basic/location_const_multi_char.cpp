#include <iostream>
using namespace std;
int main(){
	const char* p1 = "abcde"; //내용을 못바꿈
	//상수는 항상 내용을 처음에 주어야 함
	cout << p1 << endl;
	p1++;
	cout << p1 << endl;
	p1 = "efgh"; //이거는 아예 가르키는 주소를 바꾸는 것이기 때문에 됨
	cout << p1 << endl;
	//*p1 = 'z'; //내용 바꾸는 것은 컴파일 에러

	cout << "---------\n";

	char* const p2 = "abcde"; //내용을 못바꿈
	cout << p2 << endl;
	//p2++; //주소 바꾸는 것 안됨
	//p2 = "efgh"; //마찬가지
	//*p2 = 'z'; //컴파일 에러는 나지 않지만 디버깅 에러가 남
	//이게 문자열의 에러 정확히 왜인지는 모름 *******주의주의*******
	//문자열의 경우 const가 중간에 있으면 주소도 내용도 둘 다 바꿀 수 없다
	//cout << p2 << endl;

	cout << "---------\n";

	const char* const p3 = "abcde"; //내용을 못바꿈
	cout << p3 << endl;
	//p3++; //주소 바꾸려니까 에러
	//p3 = "efgh"; //주소 바꾸려니까 에러
	//*p3 = 'z'; //내용 바꾸려니까 컴파일 에러

	return 0;
}