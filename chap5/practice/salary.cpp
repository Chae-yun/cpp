#include <iostream>
using namespace std;
int main(){
	/*long salary;
	while (true){
		int total = 0, nanum = 50000;
		cout << "������ �Է��Ͻÿ�(0���� �۰ų� ������ ����) : ";
		cin >> salary;
		if (salary <= 0)
			break;
		for (int i = 1; nanum >= 1;i++){
			total += salary / nanum;
			cout << nanum << "��   " << salary / nanum << "��" << endl;
			salary %= nanum;
			if (i%2)
				nanum /= 5;
			else
				nanum /= 2;
			//��Ÿ�� �÷��� ���� ����ص� �ȴ� �̷��� for�� i��� ��
			//bool flg = true;
			//if (flg)
			//	nanum /= 5;
			//else
			//	nanum /= 2;
			//flg = !flg;
		}
		cout << endl << "�� " << total << "���Դϴ�" << endl << endl;
	}*/

	long salary;
	while (true){
		int total = 0, nanum = 50000;
		cout << "������ �Է��Ͻÿ�(0���� �۰ų� ������ ����) : ";
		cin >> salary;
		if (salary <= 0)
			break;
		while (salary > 0){
			total += salary / nanum;
			if ((salary / nanum) != 0)
				cout << nanum << "��   " << salary / nanum << "��" << endl;
			salary %= nanum;
			bool flg = true;
			if (flg)
				nanum /= 5;
			else
				nanum /= 2;
			flg = !flg;

		}
		cout << endl << "�� " << total << "���Դϴ�" << endl << endl;
	}
	return 0;
}