#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h> //strcpy()
using namespace std;

struct Student{
	int nNo; //번호
	char szName[20]; //이름

	void SetStudent(int nNo, char* pName){
		//nNo = nNo;
		//이름이 같으면 매개변수로(가까운 놈) 인식해서 매개변수에 매개변수 넣은 것
		//그러니까 쓰레기 값이 나오지
		this->nNo = nNo; //자바와 다르게 -> 인 이유는 컴파일러가 아까 *pThis 대신에 *this로 받아줌
		//내가 *this를 넣으면 오히려 에러가 나니까 쓰기만 해라
		strcpy(szName, pName);
	}

	void PrintStudent(){
		cout << "번호 : " << nNo << ", 이름 : " << szName << endl;
	}
};

int main(){
	int no;
	char name[20];
	Student student;

	cout << "학생 번호 입력 : ";
	cin >> no;

	cout << "학생 이름 입력 : ";
	cin >> name;

	student.SetStudent(no, name);
	student.PrintStudent();

	return 0;
}