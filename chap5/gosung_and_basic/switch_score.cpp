#include <iostream>
using namespace std;
int main(){
	int score;
	cout << "������ �Է��Ͻÿ� : ";
	cin >> score;

	char c;
	if (score >= 0 && score <= 100){
		score /= 10; //��� ���� ���� ���� ����
		switch (score){ //���� ������ ���� ���ִ� ���� �߿��ϴ�
		case 10: case 9:
				c = 'A';
				break;
		case 8:
				c = 'B';
				break;
		case 7:
				c = 'C';
				break;
		case 6:
				c = 'D';
				break;
		default:
				c = 'F';
			
		}
		cout << c << "����Դϴ�." << endl;
	}
	else
		cout << "������ 0~100������ �Է��Ͻÿ�" << endl;
	return 0;
}