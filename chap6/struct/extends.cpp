//c++���� ���� ���� ����ϴ� ����!

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h> //strcpy()
using namespace std;

class Student{
//public: //�̰� �Ⱦ��� �⺻�� private
	//��� �ѹ� ���ָ� ���� �� ���� ������ �� public...........
	int nNo; //��ȣ
	char szName[20]; //�̸�

public:
	void SetStudent(int nNo, char* pName);
	void PrintStudent();
};

struct StudentExtend : public Student{ //�ִ� ���� ���� �ڹٴ� �ȵ� (protected �� �ȵ� �ڱ� �Ƶ��ʿ����� ���ϱ�)
	int nKor;
	int nEng;
	int nMat;
};

void Student::SetStudent(int nNo, char* pName){
	//nNo = nNo;
	//�̸��� ������ �Ű�������(����� ��) �ν��ؼ� �Ű������� �Ű����� ���� ��
	//�׷��ϱ� ������ ���� ������
	this->nNo = nNo; //�ڹٿ� �ٸ��� -> �� ������ �����Ϸ��� �Ʊ� *pThis ��ſ� *this�� �޾���
	//���� *this�� ������ ������ ������ ���ϱ� ���⸸ �ض�
	strcpy(szName, pName);
}

void Student::PrintStudent(){
	cout << "��ȣ : " << nNo << ", �̸� : " << szName << endl;
}

int main(){
	int no;
	char name[20];
	Student student;

	cout << "�л� ��ȣ �Է� : ";
	cin >> no;

	cout << "�л� �̸� �Է� : ";
	cin >> name;

	student.SetStudent(no, name);
	student.PrintStudent();

	StudentExtend se;
	//se.nNo = 10;
	//cout << se.nNo << endl; //student�� �ٲ� �� �ƴ϶� studentextend�� �ٲ� ��
	//���� ���������� �ٲ㼭 ����

	se.SetStudent(20, "������");
	se.PrintStudent(); //�Լ����� ����� �޾Ҵ�

	return 0;
}