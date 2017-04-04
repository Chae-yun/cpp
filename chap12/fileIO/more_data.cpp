#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int nCount = 10;
	int nNo;
	char szName[20];

	ofstream outfile("out2.dat"); //파일 생성
	for (int i = 0; i < nCount; i++){
		nNo = i + 1;
		sprintf(szName, "이름_%d", nNo);
		outfile << nNo << szName << endl; //파일에 저장
	}
	outfile.close(); //파일 닫기

	ifstream infile("out2.dat"); //파일 열기
	for (int i = 0; i < nCount; i++){
		infile >> nNo;
		infile >> szName; //파일 읽기
		cout << i << " : " << nNo << ", " << szName << endl;
	}
	infile.close(); //파일 닫기

	return 0;
}