#include <iostream>
using namespace std;

int nValue = 10;
//static int nValue = 10; //전역과 똑같다

void subFuncA(){
	static int nValA = 20;
	//cout << nValue << ", " << nValA << ", " << nValB << ", " << nValM << endl;
	nValA++;
	cout << nValA << endl;
}

void subFuncB(){
	int nValB = 30;
	//cout << nValue << ", " << nValA << ", " << nValB << ", " << nValM << endl;
	nValB++;
	cout << nValB << endl;
}

int main(){
	int nValM = 40;
	//cout << nValue << ", " << nValA << ", " << nValB << ", " << nValM << endl; //nValA 와 nValB 는 지역변수
	cout << nValue << ", " << nValM << endl;
	nValue++;
	//nValA++;
	//nValB++;
	nValM++;
	subFuncA();
	subFuncB();
	cout << nValue << ", " << nValM << endl;
	cout << "-----------------------------------------\n";
	nValue++;
	//nValA++; //전역과 정적의 차이;
	//nValB++;
	nValM++;
	subFuncA(); //초기화 안됨
	subFuncB(); //다시 30으로 초기화되서 31출력
	cout << nValue << ", " << nValM << endl;
	return 0;
}