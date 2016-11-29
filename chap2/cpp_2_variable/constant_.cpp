#include <iostream>
#define A 10
#define SQ(x, y) ((x - y) * (x - y))
#define P(x) ((x)*(x)*(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
//const int A = 10;
using namespace std;
int main(){
	cout << A << endl;
	//A = 20; //에러
	cout << SQ(5, 3) << endl;
	cout << P(8-3) << endl; //괄호 없는 x*x*x 일 때는 5가 아닌 8-3을 하면 논리 오류 발생됨 (8-3*8-3*8-3)
	int i = 0, j = 1, k = 0;
	i = MAX(++j, ++k); //++등은 괄호로도 해결 못함
	cout << i << endl;
	cout << P(++j) << endl; //우선순위가 또 잘못되어서 이상 4*5*6 이 아닌 6*6*6 이 됨
	cout << SHRT_MAX << endl;
	cout << (short)(SHRT_MAX+1) << endl; //이건 그냥 테스트
	cout << DBL_MAX << endl;
	return 0;
}