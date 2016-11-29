#include <iostream>
#define PI 3.14 //함수 안에 있어도 괜찮지만 잘 안씀
#define MUL(x) (x)*(x)+(x)
#define MAX(x, y) x > y ? x : y //여기에 괄호로 묶어주지 않으면 제대로 안나오는게 define 의 문제점
//const float PI = 3.14;
using namespace std;
int main(){
	int r;
	cout << "원의 반지름을 입력하시오 : ";
	cin >> r;
	cout << "원의 넓이 : " << r*r*PI << endl;

	int n1, n2;
	cout << "\n두 수를 입력하시오 : ";
	cin >> n1 >> n2;
	int nMax;
	nMax = MAX(n1, n2); //괄호로 묶어주면 이것도 그냥 바로 써도 나옴
	cout << nMax << "가 큽니다.\n";

	cout << MUL(r) << endl << endl;
	cout << MUL(n1 + n2) << endl << endl; //이것도 문제점, 바로 대응시키기때문에 인식을 못하거나(컴파일에러) 논리에러를 발생시킴
	cout << MUL(7 - 2) << endl;
	//그래서  #define 할때 일단 무조건 전체괄호 주고 안에도 MUL(x) (x)*(x) 라고 써주는 것
	
	return 0;
}