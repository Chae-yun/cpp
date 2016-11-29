#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h> //strcpy()
using namespace std;

struct Student{
	int nNo; //번호
	char szName[20]; //이름
};

void SetStudent(Student* pThis, int no, char* pName){
	pThis->nNo = no;
	strcpy(pThis->szName, pName);
}

void PrintStudent(Student* pThis){
	cout << "번호 : " << pThis->nNo << ", 이름 : " << pThis->szName << endl;
}

int main(){
	int no;
	char name[20];
	Student student;

	cout << "학생 번호 입력 : ";
	cin >> no;

	cout << "학생 이름 입력 : ";
	cin >> name;

	SetStudent(&student, no, name);
	PrintStudent(&student);

	return 0;
}