#include <iostream>
using namespace std;
int main(){
	char eng;
	cout << "영문자 소문자를 입력하시오 : ";
	cin >> eng;
	if (islower(eng)){
		for (; eng<='z'; eng++)
			cout << eng << endl;
	}
	else
		cout << "소문자가 아닙니다" << endl;
	return 0;
}