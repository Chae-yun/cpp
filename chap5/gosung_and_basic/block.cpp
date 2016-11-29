#include <iostream>
using namespace std;
int main(){
	int a = 10;
	cout << a << endl;
	{
		int a = 20; //이 블록 안의 지역변수
		cout << a << endl; //안에서는 안에서 선언한 것이 우선임
	} //하나의 코드 블록
	cout << a << endl;
	return 0;
}