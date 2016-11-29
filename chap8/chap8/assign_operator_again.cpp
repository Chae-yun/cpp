#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Student{ //������� �ٸ� �͵� �����غ���
	int nNo;
	char* szName;

public: //����ض�
	Student(){
		nNo = 0;
		szName = 0;
		cout << "�⺻ ������" << endl;
	}

	Student(int no, char* name){
		nNo = no;
		szName = new char[strlen(name) + 1];
		strcpy(szName, name);
		cout << "�Ű����� 2�� ������" << endl;
	}

	Student(Student& st){
		if (this != &st){
			this->nNo = st.nNo;
			this->szName = new char[strlen(st.szName) + 1];
			strcpy(this->szName, st.szName);
		}
		else
			Student();
		cout << "���� ������" << endl;
	}

	~Student(){
		if (szName){
			cout << szName << " �Ҹ���" << endl;
			delete[] szName;
		}
		else{
			cout << "�̸����� �Ҹ���" << endl;
		}
	}

	void PrintStudent(){
		cout << "��ȣ : " << nNo << endl;
		if (szName != NULL)
			cout << "�̸� : " << szName << endl;
		else
			cout << "�̸� ����" << endl;
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
		
		cout << "�Ҵ� ������" << endl;
		return *this;
	}
};

int main(){
	Student a(1, "������");
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