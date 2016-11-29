#include <iostream>
using namespace std;
int main(){
	char eng;
	cout << "영문자를 입력하시오 : ";
	cin >> eng;
	if (isalpha(eng)){
		if (islower(eng)){
			for (; eng <= 'z'; eng++)
				cout << eng << endl;
		}
		else{
			for (; eng <= 'Z'; eng++)
				cout << eng << endl;
		} //이프엘스를 통째로 for (char p = ((isupper(eng)) ? 'Z' : 'z'); eng <= p; eng++) cout << eng << endl;
	}
	else
		cout << "영문자가 아닙니다" << endl;
	return 0;
}