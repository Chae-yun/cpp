//c++���� ���� ���� ����ϴ� ����!

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h> //strcpy()
using namespace std;

class Student{
	//public: //�̰� �Ⱦ��� �⺻�� private ���߿� private�ϰ� ���ͼ��� �����!
	//��� �ѹ� ���ָ� ���� �� ���� ������ �� public...........
	int nNo; //��ȣ
	char *szName; //�̸�
	//�̷� ��� �ݵ�� ����Ʈ!!

	static short nCnt; //���⼭ ����

	//��ü�� ������� ���� ū ���� ����� ���´�
	//ĳ���� �迭�� �ִٸ� �װ� ���� ĳ���ͷ� ����
	//���� ��ġ�� ���� �� �ٸ���. ���� ū �� �׿� �־�� ���� �������� ����ȭ?
	//���α׷��� �� �� �ƴ� �ɷ� ������� ���� ��������� �غ���!

public:
	void SetStudent(int nNo, char* pName);
	void PrintStudent();
	static int GetNCount();

	//Student(int a){
	Student(){
		cout << "�⺻(�ƺ�) ������" << endl;
		cout << ++nCnt << endl;
		nNo = 0;
		szName = 0; //������ ��ü�� 0�� �־����
	}

	Student(int nNo, char* pName){
		cout << "�Ű����� 2�� ������" << endl;
		cout << ++nCnt << endl;
		this->nNo = nNo; //this �Ⱥ��̸� ����� ��, �� �Ű������� �ν�
		szName = new char[strlen(pName)+1]; //���� ���ϰ� ������ ��ŭ ��� 20����Ʈ �Ѵ� �͵� ó�� ����
		strcpy(szName, pName);
	} //�����ڴ� private �� ���� ����

	~Student(){
		cout << --nCnt << "�Ҹ���" << endl;
		//delete szName; //���� �� ������
		delete[] szName; //������ ������ �迭�� ���ذǰ�?
		szName = 0; //�̷��� �ؾ� ������ Ŭ����! ������ ����̴�
	}
};

short Student::nCnt = 0; //���⼭ ���� & �޸𸮰� ���� ��
//��ü�� �޸𸮰� �ٴ� ���� �ƴ϶� ���� ������ ����

//struct StudentExtend : public Student{ //�ִ� ���� ���� �ڹٴ� �ȵ� (protected �� �ȵ� �ڱ� �Ƶ��ʿ����� ���ϱ�)
//	int nKor;
//	int nEng;
//	int nMat;
//
//	StudentExtend(){
//		cout << "�Ƶ� ������" << endl; //�ѹ� �ƺ� ���ٰ� �Ƶ�� ��
//	} //�ƺ� �⺻�� ������ ������
//};

void Student::SetStudent(int nNo, char* pName){
	//nNo = nNo;
	//�̸��� ������ �Ű�������(����� ��) �ν��ؼ� �Ű������� �Ű����� ���� ��
	//�׷��ϱ� ������ ���� ������
	this->nNo = nNo; //�ڹٿ� �ٸ��� -> �� ������ �����Ϸ��� �Ʊ� *pThis ��ſ� *this�� �޾���
	//���� *this�� ������ ������ ������ ���ϱ� ���⸸ �ض�
	szName = new char[strlen(pName)+1];
	strcpy(szName, pName);
}

void Student::PrintStudent(){
	cout << "��ȣ : " << nNo;
	if (szName != NULL)
		cout << ", �̸� : " << szName << endl;
	else
		cout << ", �̸� ����" << endl;
}

int Student::GetNCount(){ //����ƽ�� ����ƽ
	return nCnt;
} //�����信�� ����ƽ ����� �Ⱦ���
//����ƽ�� �Ű������� this �� ��! ��ü ������ �ƴϱ� ������ this ���� ����

int main(){
	//cout << Student.nCnt << endl; //������ private�� ����
	cout << Student::GetNCount() << endl;
	//��ü �ϳ��� ��� �θ� �� �־� �ڹٿ� �ٸ� �� ::, ., ->
	int no;
	char name[20];
	Student student; //������ �⺻ ������ ����� ����
	//�⺻ ������ ȣ��� : �ڹٿ� �޸� ��ȣ�� ġ�� �ȵ�, ��ü�� ����� ���·� �� ����

	//StudentExtend se;
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



	//se.SetStudent(20, "������");
	//se.PrintStudent(); //�Լ����� ����� �޾Ҵ�

	Student *st2 = new Student; //������ ��ȣ�� ������ �ȵ����� ������ ������ ������ �������

	cout << Student::GetNCount() << endl;
	cout << st1.GetNCount() << endl; //���� �Ʒ� ����! (������ . ������ ->)
	cout << st3->GetNCount() << endl; //���� �Ʒ� ����! (������ . ������ ->)
	//�� 5�� ����!!

	delete(st2); //������ delete �ؾ� ������
	delete(st3);

	cout << sizeof(st1) << endl; //����ƽ�� ��ü���� �޸� ������ �ʾ� �׽�Ʈ

	return 0;
} //�̰� �������� ��ü ���� ��
//�׷��� ���α׷��� ���� �� ������ �Ͼ�� ���� ���� �Ųٷ�