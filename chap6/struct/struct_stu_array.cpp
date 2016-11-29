#include<iostream>
using namespace std;

struct TStudent{
	int nNo;
	char szName[20];

	int nKor;
	int nEng;
	int nMat;

	int nSum;
	double dAvg;
};

int main(){
	TStudent student;

	student.nNo = 1;
	strcpy_s(student.szName, "홍길동");
	student.nKor = 70;
	student.nEng = 80;
	student.nMat = 90;

	student.nSum = student.nKor + student.nEng + student.nMat;
	student.dAvg = student.nSum / (double)3;

	cout << "번호 : " << student.nNo << endl;
	cout << "이름 : " << student.szName << endl;
	cout << "국어 : " << student.nKor << endl;
	cout << "영어 : " << student.nEng << endl;
	cout << "수학 : " << student.nMat << endl;
	cout << "총합 : " << student.nSum << endl;
	cout << "평균 : " << student.dAvg << endl;

	cout << sizeof(student) << endl;
	//cout << student << endl; //cout에 저런 함수는 정의 되어있지 않기 때문에 에러
	cout << &student << endl; //주소 찍기

	TStudent *p = &student; //4바이트

	cout << student.nNo << endl;
	cout << (*p).nNo << endl;
	cout << p->nNo << endl; //(*). 이 곧 ->

	cout << p << endl; //위의 &student와 같다

	TStudent *p1 = new TStudent; //new 안해주면 초기화 해달라고
	p1->nNo = 5;

	TStudent sta[10]; //배열은 하나인데 2차원 느낌, 프로그램이 더 간단해짐
	cout << sizeof(sta) << endl; //48이 10개

	TStudent *p2 = &sta[0];
	//TStudent *p2 = sta; //[0]이 *과 비슷하므로 &랑 상쇄되어 같다.

	cout << p2 << endl;
	p2++; //+1은 데이터 사이즈 만큼 이동이다
	cout << p2 << endl; //48, 0x30만큼 이동

	return 0;
}