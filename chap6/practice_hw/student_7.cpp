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
		cout << "번호 : " << no << endl;
		cout << "이름 : " << name << endl;
		cout << "국어 : " << kor << endl;
		cout << "영어 : " << eng << endl;
		cout << "수학 : " << math << endl;
	}
};

int main(){
	STUDENT stus[10] =
	{ { 1, "가가가", 0, 0, 0 }, { 2, "나나나", 0, 0, 0 }, { 3, "다다다", 0, 0, 0 },
	{ 4, "라라라", 0, 0, 0 }, { 5, "마마마", 0, 0, 0 }, { 6, "바바바", 0, 0, 0 },
	{ 7, "사사사", 0, 0, 0 }, { 8, "아아아", 0, 0, 0 }, { 9, "자자자", 0, 0, 0 },
	{ 10, "차차차", 0, 0, 0 } };

	char* title[3] = { "국어", "영어", "수학" };

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

	cout << "국어 점수가 가장 높은 학생" << endl;
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

	cout << "영어 점수가 가장 높은 학생" << endl;
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

	cout << "수학 점수가 가장 높은 학생" << endl;
	stus[num].PrintStudent();

	return 0;
}