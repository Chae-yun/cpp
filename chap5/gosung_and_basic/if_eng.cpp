#include <iostream>
using namespace std;
int main(){
	char eng;
	cout << "영문자를 입력하시오 : ";
	cin >> eng;

	/*if (eng >= 65 && eng <= 90)
		cout << eng << "은(는) 대문자입니다." << endl;
	else if (eng >= 97 && eng <= 122)
		cout << eng << "은(는) 소문자입니다." << endl;
	else
		cout << eng << "은(는) 영문자가 아닙니다." << endl;*/

	if (isalpha(eng)) { //간편한 함수!
		cout << eng << "은(는) 영문자입니다." << endl;

		if (isupper(eng))
			cout << eng << "은(는) 대문자입니다." << endl;
		else
			cout << eng << "은(는) 소문자입니다." << endl;

	}
	else{
		cout << eng << "은(는) 영문자가 아닙니다." << endl;

		if (isdigit(eng))
			cout << eng << "은(는) 숫자입니다." << endl;
		else
			cout << eng << "은(는) 숫자가 아닙니다." << endl;

	}

	return 0;
}