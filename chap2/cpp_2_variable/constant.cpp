#include <iostream>
#define PI 3.14 //�Լ� �ȿ� �־ �������� �� �Ⱦ�
#define MUL(x) (x)*(x)+(x)
#define MAX(x, y) x > y ? x : y //���⿡ ��ȣ�� �������� ������ ����� �ȳ����°� define �� ������
//const float PI = 3.14;
using namespace std;
int main(){
	int r;
	cout << "���� �������� �Է��Ͻÿ� : ";
	cin >> r;
	cout << "���� ���� : " << r*r*PI << endl;

	int n1, n2;
	cout << "\n�� ���� �Է��Ͻÿ� : ";
	cin >> n1 >> n2;
	int nMax;
	nMax = MAX(n1, n2); //��ȣ�� �����ָ� �̰͵� �׳� �ٷ� �ᵵ ����
	cout << nMax << "�� Ů�ϴ�.\n";

	cout << MUL(r) << endl << endl;
	cout << MUL(n1 + n2) << endl << endl; //�̰͵� ������, �ٷ� ������Ű�⶧���� �ν��� ���ϰų�(�����Ͽ���) �������� �߻���Ŵ
	cout << MUL(7 - 2) << endl;
	//�׷���  #define �Ҷ� �ϴ� ������ ��ü��ȣ �ְ� �ȿ��� MUL(x) (x)*(x) ��� ���ִ� ��
	
	return 0;
}