#include <iostream>
#define A 10
#define SQ(x, y) ((x - y) * (x - y))
#define P(x) ((x)*(x)*(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
//const int A = 10;
using namespace std;
int main(){
	cout << A << endl;
	//A = 20; //����
	cout << SQ(5, 3) << endl;
	cout << P(8-3) << endl; //��ȣ ���� x*x*x �� ���� 5�� �ƴ� 8-3�� �ϸ� �� ���� �߻��� (8-3*8-3*8-3)
	int i = 0, j = 1, k = 0;
	i = MAX(++j, ++k); //++���� ��ȣ�ε� �ذ� ����
	cout << i << endl;
	cout << P(++j) << endl; //�켱������ �� �߸��Ǿ �̻� 4*5*6 �� �ƴ� 6*6*6 �� ��
	cout << SHRT_MAX << endl;
	cout << (short)(SHRT_MAX+1) << endl; //�̰� �׳� �׽�Ʈ
	cout << DBL_MAX << endl;
	return 0;
}