#include <iostream>
using namespace std;
int main(){
	/*long salary;
	while (true){
		int total = 0, nanum = 50000;
		cout << "월급을 입력하시오(0보다 작거나 같으면 종료) : ";
		cin >> salary;
		if (salary <= 0)
			break;
		for (int i = 1; nanum >= 1;i++){
			total += salary / nanum;
			cout << nanum << "원   " << salary / nanum << "장" << endl;
			salary %= nanum;
			if (i%2)
				nanum /= 5;
			else
				nanum /= 2;
			//불타입 플래그 변수 사용해도 된다 이러면 for에 i없어도 됨
			//bool flg = true;
			//if (flg)
			//	nanum /= 5;
			//else
			//	nanum /= 2;
			//flg = !flg;
		}
		cout << endl << "총 " << total << "장입니다" << endl << endl;
	}*/

	long salary;
	while (true){
		int total = 0, nanum = 50000;
		cout << "월급을 입력하시오(0보다 작거나 같으면 종료) : ";
		cin >> salary;
		if (salary <= 0)
			break;
		while (salary > 0){
			total += salary / nanum;
			if ((salary / nanum) != 0)
				cout << nanum << "원   " << salary / nanum << "장" << endl;
			salary %= nanum;
			bool flg = true;
			if (flg)
				nanum /= 5;
			else
				nanum /= 2;
			flg = !flg;

		}
		cout << endl << "총 " << total << "장입니다" << endl << endl;
	}
	return 0;
}