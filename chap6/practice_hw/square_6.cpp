#include<iostream>
using namespace std;

struct SQUARE{
	int x1, y1;
	int x2, y2;
	int x3, y3;
	int x4, y4;
};

int main(){
	SQUARE s;
	cout << "�簢���� ù��° ��ǥ�� �Է��Ͻÿ� : ";
	cin >> s.x1 >> s.y1;
	cout << "�簢���� �ι�° ��ǥ�� �Է��Ͻÿ� : ";
	cin >> s.x2 >> s.y2;
	cout << "�簢���� ����° ��ǥ�� �Է��Ͻÿ� : ";
	cin >> s.x3 >> s.y3;
	cout << "�簢���� �׹�° ��ǥ�� �Է��Ͻÿ� : ";
	cin >> s.x4 >> s.y4;

	cout << "�簢���� ��ǥ : ( "
		<< s.x1 << ", " << s.y1 << " ), ( "
		<< s.x2 << ", " << s.y2 << " ), ( "
		<< s.x3 << ", " << s.y3 << " ), ( "
		<< s.x4 << ", " << s.y4 << " )" << endl;

	return 0;
}