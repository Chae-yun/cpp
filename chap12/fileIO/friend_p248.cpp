#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

class Student{
	int nNo; //번호
	char szName[20]; //이름

public:
	Student(){}
	Student(int no, char* name){
		SetData(no, name);
	}
	void SetData(int no, char* name){
		nNo = no;
		strcpy(szName, name);
	}
	//파일에 저장하는 함수
	void Save(ofstream& ofs){
		ofs << nNo << szName << endl;
		cout << "SAVE : " << nNo << ", " << szName << endl;
	}
	//파일에서 읽어오는 함수
	void Read(ifstream& ifs){
		ifs >> nNo >> szName;
		cout << "READ : " << nNo << ", " << szName << endl;
	}
	//파일에 저장하기 위한 << 연산자 중복정의
	friend ofstream& operator<<(ofstream& ofs, Student& student){
		cout << "<< ";
		student.Save(ofs);
		return ofs;
	}
	//파일에서 읽어오기 위한 >> 연산자 중복정의
	friend ifstream& operator>>(ifstream& ifs, Student& student){
		cout << ">> ";
		student.Read(ifs);
		return ifs;
	}
};

////파일에 저장하기 위한 << 연산자 중복정의
//ofstream& operator<<(ofstream& ofs, Student& student){
//	cout << "<<";
//	student.Save(ofs);
//	return ofs;
//}
//일반함수로 쓰면 되지만 스튜던트만 써야하니까 안에 넣어놓고 친구로 하자
//그러면 스튜던트만 사용을 할 수 있고 역할은 일반함수처럼 된다.

int main(){
	Student students[3]; //학생 객체 생성

	students[0].SetData(1, "김하나"); //객체 초기값 지정
	students[1].SetData(2, "김두리");
	students[2].SetData(3, "김세나");

	int nCount = sizeof(students) / sizeof(Student); //배열 개수 계산

	cout << "COUNT : " << nCount << endl;
	ofstream outfile("out3.dat"); //파일 생성
	for (int i = 0; i < nCount; i++){
		//students[i].Save(outfile); //함수 호출로 저장
		outfile << students[i]; //중복정의된 << 연산자로 저장
	}
	outfile.close(); //파일 닫기

	cout << "------------------------------------------" << endl;

	ifstream infile("out3.dat"); //파일 열기
	for (int i = 0; i < nCount; i++){
		//students[i].Read(infile); //함수 호출로 읽기
		infile >> students[i]; //중복정의된 >> 연산자로 읽기
	}
	infile.close(); //파일 닫기

	return 0;
}