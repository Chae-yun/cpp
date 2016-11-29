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
	cout << "이름 : " << student.szName<< endl;
	cout << "국어 : " << student.nKor << endl;
	cout << "영어 : " << student.nEng << endl;
	cout << "수학 : " << student.nMat << endl;
	cout << "총합 : " << student.nSum << endl;
	cout << "평균 : " << student.dAvg << endl;

	cout << sizeof(student) << endl;

	return 0;
}