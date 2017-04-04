#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

int main(){
	char szBuf[100];
	strcpy(szBuf, "12345 Hello File"); //덮어씌워짐

	//ofstream outfile("out.dat"); //파일을 생성 (객체 생성, 파일 열기)
	//outfile << szBuf << endl; //파일에 저장
	//outfile.close(); //파일 닫기
	//3단계

	ofstream abc; //객체 생성
	abc.open("out.dat",ios_base::app); //파일 열기
	abc << szBuf << endl; //파일에 저장
	abc.close(); //파일 닫기
	//4단계

	ifstream infile("out.dat"); //파일 열기 (객체 생성, 파일 열기)
	infile.getline(szBuf, 100); //파일 읽기
	infile.close(); //파일 닫기

	cout << "Read File : " << szBuf << endl; //읽은 파일 내용 출력

	return 0;
}