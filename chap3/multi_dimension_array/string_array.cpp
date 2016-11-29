#include <iostream>
using namespace std;

int main(){
	char szMessage1[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'a', 'r', 'r', 'a', 'y', 0 }; //하나씩 쓸 때는 반드시 널 표시!! 안하면 만날 때까지 계속 출력
	char szMessage2[] = { "Hello array" };
	char szMessage3[] = "Hello array";

	cout << szMessage1 << endl << szMessage2 << endl << szMessage3 << endl;

	return 0;
}