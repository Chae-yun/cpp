#include <iostream>
using namespace std;
int main(){
	char eng;
	cout << "������ �ҹ��ڸ� �Է��Ͻÿ� : ";
	cin >> eng;
	if (islower(eng)){
		for (; eng<='z'; eng++)
			cout << eng << endl;
	}
	else
		cout << "�ҹ��ڰ� �ƴմϴ�" << endl;
	return 0;
}