//c++에서 가장 많이 사용하는 형태!

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h> //strcpy()
using namespace std;

class Student{
	//public: //이거 안쓰면 기본이 private 나중엔 private하고 게터세터 써야해!
	//얘는 한번 해주면 다음 꺼 나올 때까지 다 public...........
	int nNo; //번호
	char *szName; //이름
	//이런 경우 반드시 딜리트!!

	static short nCnt; //여기서 선언만

	//객체의 사이즈는 가장 큰 거의 배수로 나온다
	//캐릭터 배열이 있다면 그건 각각 캐릭터로 본다
	//선언 위치에 따라 좀 다르다. 제일 큰 게 및에 있어야 위의 내용으로 최적화?
	//프로그래밍 할 때 아는 걸로 계산하지 말고 사이즈오브 해보기!

public:
	void SetStudent(int nNo, char* pName);
	void PrintStudent();
	static int GetNCount();

	//Student(int a){
	Student(){
		cout << "기본(아빠) 생성자" << endl;
		cout << ++nCnt << endl;
		nNo = 0;
		szName = 0; //포인터 자체에 0을 넣어야지
	}

	Student(int nNo, char* pName){
		cout << "매개변수 2개 생성자" << endl;
		cout << ++nCnt << endl;
		this->nNo = nNo; //this 안붙이면 가까운 거, 즉 매개변수로 인식
		szName = new char[strlen(pName)+1]; //낭비 안하고 들어오는 만큼 잡고 20바이트 넘는 것도 처리 가능
		strcpy(szName, pName);
	} //생성자는 private 일 수가 없다

	~Student(){
		cout << --nCnt << "소멸자" << endl;
		//delete szName; //별로 안 적절해
		delete[] szName; //연결을 끊었당 배열도 없앤건가?
		szName = 0; //이렇게 해야 완전히 클리어! 괜찮은 방법이다
	}
};

short Student::nCnt = 0; //여기서 선언 & 메모리가 잡힌 것
//객체에 메모리가 붙는 것이 아니라 따로 공간이 잡힘

//struct StudentExtend : public Student{ //최대 접근 범위 자바는 안됨 (protected 도 안됨 자기 아들쪽에서만 쓰니까)
//	int nKor;
//	int nEng;
//	int nMat;
//
//	StudentExtend(){
//		cout << "아들 생성자" << endl; //한번 아빠 갔다가 아들로 옴
//	} //아빠 기본이 없으면 에러남
//};

void Student::SetStudent(int nNo, char* pName){
	//nNo = nNo;
	//이름이 같으면 매개변수로(가까운 놈) 인식해서 매개변수에 매개변수 넣은 것
	//그러니까 쓰레기 값이 나오지
	this->nNo = nNo; //자바와 다르게 -> 인 이유는 컴파일러가 아까 *pThis 대신에 *this로 받아줌
	//내가 *this를 넣으면 오히려 에러가 나니까 쓰기만 해라
	szName = new char[strlen(pName)+1];
	strcpy(szName, pName);
}

void Student::PrintStudent(){
	cout << "번호 : " << nNo;
	if (szName != NULL)
		cout << ", 이름 : " << szName << endl;
	else
		cout << ", 이름 없음" << endl;
}

int Student::GetNCount(){ //스태틱은 스태틱
	return nCnt;
} //프로토에만 스태틱 여기는 안쓰고
//스태틱은 매개변수에 this 안 들어가! 객체 관련이 아니기 때문에 this 쓰면 에러

int main(){
	//cout << Student.nCnt << endl; //지금은 private라서 못함
	cout << Student::GetNCount() << endl;
	//객체 하나도 없어도 부를 수 있어 자바와 다른 건 ::, ., ->
	int no;
	char name[20];
	Student student; //위에서 기본 생성자 지우면 에러
	//기본 생성자 호출법 : 자바와 달리 괄호를 치면 안됨, 객체를 만드는 형태로 안 본다

	//StudentExtend se;
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



	//se.SetStudent(20, "망아지");
	//se.PrintStudent(); //함수까지 상속을 받았다

	Student *st2 = new Student; //정적은 괄호가 있으면 안되지만 동적은 있으나 없으나 상관없다

	cout << Student::GetNCount() << endl;
	cout << st1.GetNCount() << endl; //위랑 아래 같아! (정적은 . 동적은 ->)
	cout << st3->GetNCount() << endl; //위랑 아래 같아! (정적은 . 동적은 ->)
	//총 5개 가능!!

	delete(st2); //동적은 delete 해야 없어져
	delete(st3);

	cout << sizeof(st1) << endl; //스태틱은 객체마다 메모리 잡히지 않아 테스트

	return 0;
} //이건 정적으로 객체 만든 거
//그래서 프로그램이 끝날 때 해제가 일어난다 만든 순서 거꾸로