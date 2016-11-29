//c++���� ���� ���� ����ϴ� ����!

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h> //strcpy()
using namespace std;

class Student{
	//public: //�̰� �Ⱦ��� �⺻�� private
	//��� �ѹ� ���ָ� ���� �� ���� ������ �� public...........
	short nNo; //��ȣ
	double a; //������ �׽�Ʈ��
	char szName[10]; //�̸�
	//�̰Ÿ� *szName�� �ϸ� �����ڿ��� new�� �޸𸮸� ���� ��Ƽ� �ؾ� �ϴµ� �׷��� delete�� �Ҹ��ڿ��� �� ����� ��!!!

public:
	void SetStudent(int nNo, char* pName);
	void PrintStudent();

	//Student(int a){
	Student(){
		cout << "�⺻(�ƺ�) ������" << endl;
		nNo = 0;
		szName[0] = 0; //���� ���̻� ���� ���ٴ� �Ŵϱ� ó���� ���� �־����
	}

	Student(int nNo, char* pName){
		cout << "�Ű����� 2�� ������" << endl;
		this->nNo = nNo;
		strcpy(szName, pName);
	} //�����ڴ� private �� ���� ����

	~Student(){
		cout << nNo << "�Ҹ���" << endl;
	}
};

struct StudentExtend : public Student{ //�ִ� ���� ���� �ڹٴ� �ȵ� (protected �� �ȵ� �ڱ� �Ƶ��ʿ����� ���ϱ�)
	int nKor;
	int nEng;
	int nMat;

	StudentExtend(){
		cout << "�Ƶ� ������" << endl; //�ѹ� �ƺ� ���ٰ� �Ƶ�� ��
	} //�ƺ� �⺻�� ������ ������
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
	Student student; //������ �⺻ ������ ����� ����
	//�⺻ ������ ȣ��� : �ڹٿ� �޸� ��ȣ�� ġ�� �ȵ�, ��ü�� ����� ���·� �� ����

	StudentExtend se;
	//se.nNo = 10;
	//cout << se.nNo << endl; //student�� �ٲ� �� �ƴ϶� studentextend�� �ٲ� ��
	//���� ���������� �ٲ㼭 ����

	Student *st3 = new Student(3, "������");
	
	Student st1(5, "��");

	student.PrintStudent();
	st1.PrintStudent();

	cout << "�л� ��ȣ �Է� : ";
	cin >> no;

	cout << "�л� �̸� �Է� : ";
	cin >> name;

	student.SetStudent(no, name);
	student.PrintStudent();

	se.SetStudent(20, "������");
	se.PrintStudent(); //�Լ����� ����� �޾Ҵ�
	cout << sizeof(se) << endl;

	Student *st2 = new Student; //������ ��ȣ�� ������ �ȵ����� ������ ������ ������ �������
	delete(st2); //������ delete �ؾ� ������
	delete(st3);

	cout << sizeof(student) << endl;

	return 0;
} //�̰� �������� ��ü ���� ��
//�׷��� ���α׷��� ���� �� ������ �Ͼ�� ���� ���� �Ųٷ�