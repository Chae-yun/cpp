#include <iostream>
using namespace std;
int main(){
	char* pMessage = "welcome to korea";
	cout << "*pMessage : " << *pMessage << endl;
	cout << "*(pMessage+1) : " << *(pMessage + 1) << endl;
	cout << "pMessage+1 : " << *pMessage + 1 << endl;
	cout << "*(pMessage+8) : " << *(pMessage + 8) << endl;
	cout << "pMessage : " << pMessage << endl; //문자열은 주소가 나오지 않고 널일 때까지 통째로 나옴 기본타입은 주소나옴
	cout << "pMessage : " << &(*pMessage) << endl; //이렇게 하면 그냥 &*상쇄시켜 버려서 문자열은 주소찾기 어렵다

	cout << "\n아래출력" << endl;
	for (int i = 0; *(pMessage + i); i++)
		//cout << *(pMessage + i) << endl;
		cout << pMessage[i] << endl; //이렇게 배열로 써도 같다 (&* 처럼 &[]도 상쇄시킴)
	//포인터와 배열은 호환됨

	return 0;
}