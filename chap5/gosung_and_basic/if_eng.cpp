#include <iostream>
using namespace std;
int main(){
	char eng;
	cout << "�����ڸ� �Է��Ͻÿ� : ";
	cin >> eng;

	/*if (eng >= 65 && eng <= 90)
		cout << eng << "��(��) �빮���Դϴ�." << endl;
	else if (eng >= 97 && eng <= 122)
		cout << eng << "��(��) �ҹ����Դϴ�." << endl;
	else
		cout << eng << "��(��) �����ڰ� �ƴմϴ�." << endl;*/

	if (isalpha(eng)) { //������ �Լ�!
		cout << eng << "��(��) �������Դϴ�." << endl;

		if (isupper(eng))
			cout << eng << "��(��) �빮���Դϴ�." << endl;
		else
			cout << eng << "��(��) �ҹ����Դϴ�." << endl;

	}
	else{
		cout << eng << "��(��) �����ڰ� �ƴմϴ�." << endl;

		if (isdigit(eng))
			cout << eng << "��(��) �����Դϴ�." << endl;
		else
			cout << eng << "��(��) ���ڰ� �ƴմϴ�." << endl;

	}

	return 0;
}