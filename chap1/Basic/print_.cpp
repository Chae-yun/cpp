#include<iostream>
using namespace std; //�̰� ���ָ� std:: �Ƚ��൵ ��
/*void main(){
std::cout << "Hello\n";
std::cout << 5 << std::endl;
}*/
namespace b1{
	long a = 5;
	void funca(){
		cout << "a ���";
	}
}

namespace b3{
	int a = 10;
	void funca(){
		cout << "b ���";
	}
}

int main(){
	cout << b1::a; //::����������
	b1::funca();
	int k;
	cin >> k;
	return 0; //int main �̱� ������ ������ �־�� ����.
	//������ 0�� �ƴϸ� os�� �������ᰡ ���� �ʾҴٰ� �ν�
}