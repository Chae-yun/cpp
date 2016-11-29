#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Student{ //멤버변수 다른 것도 생각해봐라
	int nNo;
	char* szName;

public: //기억해라
	Student(){
		nNo = 0;
		szName = 0;
		cout << "기본 생성자" << endl;
	}

	Student(int no, char* name){
		nNo = no;
		szName = new char[strlen(name) + 1];
		strcpy(szName, name);
		cout << "매개변수 2개 생성자" << endl;
	}

	Student(Student& st){
		if (this != &st){
			this->nNo = st.nNo;
			this->szName = new char[strlen(st.szName) + 1];
			strcpy(this->szName, st.szName);
		}
		else
			Student();
		cout << "복사 생성자" << endl;
	}

	~Student(){
		if (szName){
			cout << szName << " 소멸자" << endl;
			delete[] szName;
		}
		else{
			cout << "이름없음 소멸자" << endl;
		}
	}

	void PrintStudent(){
		cout << "번호 : " << nNo << endl;
		if (szName != NULL)
			cout << "이름 : " << szName << endl;
		else
			cout << "이름 없음" << endl;
	}

	Student& operator=(Student& st){
		if (this != &st){
			this->nNo = st.nNo;
			if (this->szName){
				delete[] this->szName;
			}
			this->szName = new char[strlen(st.szName) + 1];
			strcpy(this->szName, st.szName);
		}
		
		cout << "할당 연산자" << endl;
		return *this;
	}
};

int main(){
	Student a(1, "최콩쥐");
	a.PrintStudent();

	Student b;
	b.PrintStudent();

	b = a;
	a.PrintStudent();
	b.PrintStudent();

	Student c;
	c = a = b;
	a.PrintStudent();
	b.PrintStudent();
	c.PrintStudent();

	a = a;
	a.PrintStudent();

	c = b;

	Student d = a;
	a.PrintStudent();
	d.PrintStudent();

	Student e = e;
	e.PrintStudent();

	return 0;
}