#include <iostream>
using namespace std;
int main(){
	int score;
	cout << "������ �Է��Ͻÿ� : ";
	cin >> score;

	/*if (score<0 || score>100) //���� ������ ���� ���ִ� ���� �߿��ϴ�
		cout << "������ 0~100������ �Է��Ͻÿ�" << endl;
	else if (score>=90)
		cout << "A����Դϴ�" << endl;
	else if (score >= 80)
		cout << "B����Դϴ�" << endl;
	else if (score >= 70)
		cout << "C����Դϴ�" << endl;
	else if (score >= 60)
		cout << "D����Դϴ�" << endl;
	else
		cout << "F����Դϴ�" << endl;*/

	char c;
	if (score >= 0 && score <= 100){ //���� ������ ���� ���ִ� ���� �߿��ϴ�
		if (score >= 90)
			c = 'A';
		else if (score >= 80)
			c = 'B';
		else if (score >= 70)
			c = 'C';
		else if (score >= 60)
			c = 'D';
		else
			c = 'F';
		cout << c << "����Դϴ�." << endl;
	}
	else
		cout << "������ 0~100������ �Է��Ͻÿ�" << endl;

	return 0;
}