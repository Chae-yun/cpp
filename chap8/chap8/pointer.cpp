#include <iostream>
using namespace std;

class Student{
public:
	int nNo;
	char szName[20]; 

	Student(){
		nNo = 0;
		szName[0] = 0;
		cout << nNo << " �⺻ ������" << endl;
	}
	Student(int no, char* name){
		nNo = no;
		strcpy_s(szName, name);
		cout << nNo << " �Ű������� 2���� ������" << endl;
	}

	~Student(){
		cout << nNo << " �Ҹ���" << endl;
	}

	void PrintStudent(){
		cout << "��ȣ : " << nNo << ", �̸� : " << szName << endl;
	}
};

int main(){
	Student st[10];
	st[0].nNo = 1;
	strcpy_s(st[0].szName, "������");
	st[0].PrintStudent();
	st[1].nNo = 2;
	strcpy_s(st[1].szName, "������");
	st[1].PrintStudent();
	st->PrintStudent();
	(st + 1)->PrintStudent(); //���ɰ���
	cout << &st[0] << endl;
	cout << &st[1] << endl; //�� ���� 24����Ʈ

	Student* ast = new Student[10];
	ast[0].nNo = 3;
	strcpy_s(ast[0].szName, "�۾���");
	ast[0].PrintStudent();
	//ast[1].nNo = 4;
	(ast + 1)->nNo = 4; //�켱���� ������ ��ȣ �ʿ�!
	strcpy_s(ast[1].szName, "���Ƹ�");
	ast[1].PrintStudent();
	ast->PrintStudent(); //0���� ����Ŵ, �迭�� ������ó���� ����
	(ast + 2)->nNo = 5;
	strcpy_s((ast + 2)->szName,"�����");
	(ast + 2)->PrintStudent();
	cout << ast << endl;
	cout << (ast + 1) << endl; //�굵 24����Ʈ

	//st++; //�̰ɷ� ���ؼ� ȭ��ǥ�� ��밡�������� ������ �����ͷ� ����� �Ұ�
	(st + 1)->PrintStudent();
	//ast++; //�̷� �� �ϸ� ����� �� �̻�
	ast->PrintStudent();

	//delete ast; //�ϸ� �۾����� �װ� �ߴ�, �޸� ����
	delete[] ast; //�迭��ü�� ����, �ڿ������� �״´ٴ� �� ���ÿ� �� �� (������ ����)

	return 0;
}