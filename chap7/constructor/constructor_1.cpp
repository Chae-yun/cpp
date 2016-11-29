//c++에서 가장 많이 사용하는 형태!

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h> //strcpy()
using namespace std;

class Student{
	//public: //이거 안쓰면 기본이 private
	//얘는 한번 해주면 다음 꺼 나올 때까지 다 public...........
	short nNo; //번호
	double a; //사이즈 테스트용
	char szName[10]; //이름
	//이거를 *szName로 하면 생성자에서 new로 메모리를 따로 잡아서 해야 하는데 그러면 delete를 소멸자에서 꼭 해줘야 해!!!

public:
	void SetStudent(int nNo, char* pName);
	void PrintStudent();

	//Student(int a){
	Student(){
		cout << "기본(아빠) 생성자" << endl;
		nNo = 0;
		szName[0] = 0; //널은 더이상 뭐가 없다는 거니까 처음에 널을 넣어줘라
	}

	Student(int nNo, char* pName){
		cout << "매개변수 2개 생성자" << endl;
		this->nNo = nNo;
		strcpy(szName, pName);
	} //생성자는 private 일 수가 없다

	~Student(){
		cout << nNo << "소멸자" << endl;
	}
};

struct StudentExtend : public Student{ //최대 접근 범위 자바는 안됨 (protected 도 안됨 자기 아들쪽에서만 쓰니까)
	int nKor;
	int nEng;
	int nMat;

	StudentExtend(){
		cout << "아들 생성자" << endl; //한번 아빠 갔다가 아들로 옴
	} //아빠 기본이 없으면 에러남
};

void Student::SetStudent(int nNo, char* pName){
	//nNo = nNo;
	//이름이 같으면 매개변수로(가까운 놈) 인식해서 매개변수에 매개변수 넣은 것
	//그러니까 쓰레기 값이 나오지
	this->nNo = nNo; //자바와 다르게 -> 인 이유는 컴파일러가 아까 *pThis 대신에 *this로 받아줌
	//내가 *this를 넣으면 오히려 에러가 나니까 쓰기만 해라
	strcpy(szName, pName);
}

void Student::PrintStudent(){
	cout << "번호 : " << nNo << ", 이름 : " << szName << endl;
}

int main(){
	int no;
	char name[20];
	Student student; //위에서 기본 생성자 지우면 에러
	//기본 생성자 호출법 : 자바와 달리 괄호를 치면 안됨, 객체를 만드는 형태로 안 본다

	StudentExtend se;
	//se.nNo = 10;
	//cout << se.nNo << endl; //student를 바꾼 게 아니라 studentextend를 바꾼 거
	//지금 접근제어자 바꿔서 에러

	Student *st3 = new Student(3, "강아지");
	
	Student st1(5, "송");

	student.PrintStudent();
	st1.PrintStudent();

	cout << "학생 번호 입력 : ";
	cin >> no;

	cout << "학생 이름 입력 : ";
	cin >> name;

	student.SetStudent(no, name);
	student.PrintStudent();

	se.SetStudent(20, "망아지");
	se.PrintStudent(); //함수까지 상속을 받았다
	cout << sizeof(se) << endl;

	Student *st2 = new Student; //정적은 괄호가 있으면 안되지만 동적은 있으나 없으나 상관없다
	delete(st2); //동적은 delete 해야 없어져
	delete(st3);

	cout << sizeof(student) << endl;

	return 0;
} //이건 정적으로 객체 만든 거
//그래서 프로그램이 끝날 때 해제가 일어난다 만든 순서 거꾸로