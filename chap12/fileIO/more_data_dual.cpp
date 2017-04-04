#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int nCount = 10;
	int nNo;
	char szName[20];

	fstream file; //파일 생성
	file.open("out3.dat", ios_base::out | ios_base::in | ios_base::trunc); //파일 열기
	//in, out 명시는 해줘라
	//trunc를 안하면 파일이 안생긴다.....
	for (int i = 0; i < nCount; i++){
		nNo = i + 1;
		sprintf(szName, "이름_%d", nNo);
		file << nNo << szName << endl; //파일에 저장
	}

	file.seekg(0, ios_base::beg);
	//커서를 처음으로 돌려준다
	//처음 매개변수는 offset(두번째부터 얼마나 떨어진 곳에서 가져올건지, 두번째 매개변수는 읽어올 시작점)

	for (int i = 0; i < nCount; i++){
		file >> nNo;
		file >> szName; //파일 읽기
		cout << i << " : " << nNo << ", " << szName << endl;
	}
	file.close(); //파일 닫기

	return 0;
}