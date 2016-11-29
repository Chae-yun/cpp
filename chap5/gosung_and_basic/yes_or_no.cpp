#include <iostream>
using namespace std;
int main(){
	char answer;
	while (true){
		do{
			cout << "계속 진행 하시겠습니까?" << endl;
			cout << "계속하려면 'Y'를 중지하려면 'N'을 누르세요." << endl;
			cin >> answer;
		} while ((toupper(answer) != 'Y') && (toupper(answer) != 'N')); //toupper의 리턴타입은 int!

		if (toupper(answer) == 'N'){
			cout << "중지합니다." << endl;
			break;
		}
		else if ((toupper(answer) == 'Y'))
			cout << "계속 진행 합니다" << endl;

	}
	return 0;
}