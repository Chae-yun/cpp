#include <iostream>
using namespace std;

class Student{
public:
	int nNo;
	char szName[20]; 

	Student(){
		nNo = 0;
		szName[0] = 0;
		cout << nNo << " 기본 생성자" << endl;
	}
	Student(int no, char* name){
		nNo = no;
		strcpy_s(szName, name);
		cout << nNo << " 매개변수가 2개인 생성자" << endl;
	}

	~Student(){
		cout << nNo << " 소멸자" << endl;
	}

	void PrintStudent(){
		cout << "번호 : " << nNo << ", 이름 : " << szName << endl;
	}
};

int main(){
	Student st[10];
	st[0].nNo = 1;
	strcpy_s(st[0].szName, "강아지");
	st[0].PrintStudent();
	st[1].nNo = 2;
	strcpy_s(st[1].szName, "망아지");
	st[1].PrintStudent();
	st->PrintStudent();
	(st + 1)->PrintStudent(); //가능가능
	cout << &st[0] << endl;
	cout << &st[1] << endl; //방 차이 24바이트

	Student* ast = new Student[10];
	ast[0].nNo = 3;
	strcpy_s(ast[0].szName, "송아지");
	ast[0].PrintStudent();
	//ast[1].nNo = 4;
	(ast + 1)->nNo = 4; //우선순위 때문에 괄호 필요!
	strcpy_s(ast[1].szName, "병아리");
	ast[1].PrintStudent();
	ast->PrintStudent(); //0번방 가르킴, 배열이 포인터처럼도 쓰임
	(ast + 2)->nNo = 5;
	strcpy_s((ast + 2)->szName,"고양이");
	(ast + 2)->PrintStudent();
	cout << ast << endl;
	cout << (ast + 1) << endl; //얘도 24바이트

	//st++; //이걸로 인해서 화살표는 사용가능하지만 완전히 포인터로 사용은 불가
	(st + 1)->PrintStudent();
	//ast++; //이런 거 하면 지우는 게 이상
	ast->PrintStudent();

	//delete ast; //하면 송아지만 죽고 중단, 메모리 누수
	delete[] ast; //배열자체는 정적, 뒤에서부터 죽는다는 건 스택에 들어간 것 (스택은 정적)

	return 0;
}