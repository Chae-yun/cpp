#include <iostream>
using namespace std;
int main(){
	/*char eng;
	cout << "�����ڸ� �Է��Ͻÿ� : ";
	cin >> eng;
	if (isalpha(eng)){
		if (islower(eng)){
			for (; eng <= 'z'; eng++)
				cout << eng << endl;
		}
		else{
			for (; eng <= 'Z'; eng++)
				cout << eng << endl;
		} //���������� ��°�� for (char p = ((isupper(eng)) ? 'Z' : 'z'); eng <= p; eng++) cout << eng << endl;
	}
	else
		cout << "�����ڰ� �ƴմϴ�" << endl;*/
	char c;
	cin >> c;
	for (char i = c, a = 0; a < 5, i <= 'Z'; i++, a++)
		cout << i; //������ �ΰ��� �ڿ� �͸� ��ȿ�Ѵ� ������ ����
	return 0;
}