#include <iostream>
using namespace std;
int main(){
	int iCode = 1000;

	cout << iCode << " -> " << (char)iCode << endl; //char에 1000을 담지 못하므로 출력을 하지 않는다.

	iCode = (int)1.4321;
	cout << iCode << endl;

	//형변환을 해주지 않으면 컴파일러에서 경고 메시지가 출력된다.
	iCode = (int)1.5678;
	cout << iCode << endl;
	
	double dResult = 0.0;
	dResult = 100 + 3 / 2; //3 / 2가 1이다
	cout << dResult << endl;

	//형변환의 또 다른 표현이다. (double)3 / 2와 동일하다.
	dResult = 100 + (double)3 / 2;
	cout << dResult << endl;

	return 0;
}