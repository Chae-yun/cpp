#include<iostream>
#include<time.h>
using namespace std;

struct STUDENT{
	int no;
	char name[20];
	int kor;
	int eng;
	int math;

	void PrintStudent(){
		cout << "��ȣ : " << no << endl;
		cout << "�̸� : " << name << endl;
		cout << "���� : " << kor << endl;
		cout << "���� : " << eng << endl;
		cout << "���� : " << math << endl;
	}
};

int main(){
	STUDENT stus[10] =
	{ { 1, "������", 0, 0, 0 }, { 2, "������", 0, 0, 0 }, { 3, "�ٴٴ�", 0, 0, 0 },
	{ 4, "����", 0, 0, 0 }, { 5, "������", 0, 0, 0 }, { 6, "�ٹٹ�", 0, 0, 0 },
	{ 7, "����", 0, 0, 0 }, { 8, "�ƾƾ�", 0, 0, 0 }, { 9, "������", 0, 0, 0 },
	{ 10, "������", 0, 0, 0 } };

	char* title[3] = { "����", "����", "����" };

	srand((unsigned)time(0));

	for (int i = 0; i < 10; i++){
		stus[i].kor = rand() % 101;
		stus[i].eng = rand() % 101;
		stus[i].math = rand() % 101;
	}

	int num = 0;
	int max = stus[0].kor;

	for (int i = 1; i < 10; i++){
		if (max < stus[i].kor){
			max = stus[i].kor;
			num = i;
		}
	}

	cout << "���� ������ ���� ���� �л�" << endl;
	stus[num].PrintStudent();
	cout << endl;


	num = 0;
	max = stus[0].eng;

	for (int i = 1; i < 10; i++){
		if (max < stus[i].eng){
			max = stus[i].eng;
			num = i;
		}
	}

	cout << "���� ������ ���� ���� �л�" << endl;
	stus[num].PrintStudent();
	cout << endl;


	num = 0;
	max = stus[0].math;

	for (int i = 1; i < 10; i++){
		if (max < stus[i].math){
			max = stus[i].math;
			num = i;
		}
	}

	cout << "���� ������ ���� ���� �л�" << endl;
	stus[num].PrintStudent();

	return 0;
}