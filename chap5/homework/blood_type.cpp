#include <iostream>
using namespace std;
int main(){
	while (true){
		char input[10];
		cout << "특징을 보고싶은 혈액형을 입력하시오(A, B, O, AB, X는 종료) : ";
		cin >> input;
		if (strlen(input) == 2 && toupper(input[0]) == 'A'&&toupper(input[1]) == 'B')
			cout << endl << "AB형은 생각하는 것이 남다릅니다" << endl << endl;
		else if (strlen(input) == 1){
			if (toupper(input[0]) == 'X'){
				cout << "종료합니다" << endl;
				break;
			}
			else if (toupper(input[0]) == 'A')
				cout << endl << "A형은 소심하지만 때로는 당당한 면도 있습니다" << endl << endl;
			else if (toupper(input[0]) == 'B')
				cout << endl << "B형은 자신만 생각하는 경향이 있지만 활기찹니다" << endl << endl;
			else if (toupper(input[0]) == 'O')
				cout << endl << "O형은 사교성이 좋지만 잘 토라집니다" << endl << endl;
			else
				cout << endl << "A, B, O, AB, X 중에서만 입력해주십시오" << endl << endl;
		}
		else
			cout << endl << "A, B, O, AB, X 중에서만 입력해주십시오" << endl << endl;
	}//!strcmp(input,"A")로 할 수도 있다
	return 0;
}