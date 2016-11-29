#include <iostream>
using namespace std;
int main(){
	//자기 자신을 제외한 약수의 합이 자기 자신인 수가 완전수 1~지정한 수
	int last;
	char yn;

	while(true){
		int count = 0;

		cout << "완전수의 끝 수를 입력하시오 : ";
		cin >> last;
		cout << "완전수 (1~" << last << ")" << endl;

		for (int i = 1; i <= last; i++){
			int sum = 0;
			for (int j = 1; j <= i / 2; j++){
				if (i%j == 0)
					sum += j;
			}
			if (sum == i){
				cout << i << endl;
				count++;
			}
		}

		cout << endl << endl << "1~" << last << "의 완전수 개수 : " << count << endl;

		cout << endl << "계속하시겠습니까?(y/n) : ";
		cin >> yn;

		while (toupper(yn) != 'N'&& toupper(yn) != 'Y'){
			cout << "다시 입력하시오(y/n) : ";
			cin >> yn;
		}

		if (toupper(yn) == 'N'){
			cout << "중지합니다" << endl;
			break;
		}
		else if (toupper(yn) == 'Y')
			cout << "계속합니다" << endl << "-------------------------------" << endl;
	}
	return 0;
}