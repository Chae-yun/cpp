/*#include <iostream>
using namespace std;
int main(){
	int num;
	while (true){
		int last = 0;
		cout << "ABC...를 출력하고 싶은 줄 만큼 숫자를 입력하시오 : ";
		cin >> num;
		if (num <= 0){
			cout << "범위를 벗어나 종료합니다" << endl;
			break;
		}
		char ch;
		do{
			for (ch = 'A'; ch <= last + 'A'; ch++){
				cout << ch;
				if (ch > 'Z')
					ch = 'A';
			}
			cout << endl;
			last++;
		} while (ch < num + 'A');
	}
	return 0;
}*/

#include <iostream>
using namespace std;
int main(){
	int jul;
	while (true){
		cout << "ABC...를 출력하고 싶은 줄 만큼 숫자를 입력하시오 : ";
		cin >> jul;
		if (jul > 0){
			for (int i = 0; i < jul; i++){ //char로 쓰면 범위가 작기 때문에 반복이 많이 안된다 (그 엄청 고민했던거)
				//char a = 'A';
				for (int j = 0; j <= i; j++)
					/*if (a == 'Z' + 1)
						a = 'A';
					cout << (char)('A'+j);*/
					cout << (char)('A' + j%26); //나머지로 하면 간단ㅜㅜㅠㅠㅠ
				cout << endl;
			}
		}
		else{
			cout << "범위를 벗어나 종료합니다" << endl;
			break;
		}
	}
	return 0;
}