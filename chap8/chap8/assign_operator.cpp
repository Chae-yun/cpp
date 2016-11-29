#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Student{
public:
	int nNo;
	char* szName;

	Student(){
		nNo = 0;
		szName = 0;
		cout << nNo << " 기본 생성자" << endl;
	}
	Student(int no, char* name){
		nNo = no;
		szName = new char[strlen(name) + 1]; //효율적인 사용
		strcpy(szName, name);
		cout << nNo << " 매개변수가 2개인 생성자" << endl;
	}
	Student(Student& st){ //새로 공간을 잡으면 중간에 해제가 일어나서 ㄴㄴ
		if (this != &st){
			this->nNo = st.nNo;
			this->szName = new char[strlen(st.szName) + 1];
			//Student e=e 하면 할당하다가 죽음  szName의 길이가 없으니까 왜 넘버에서는 안죽어?
			strcpy(this->szName, st.szName);
		}
		else{
			/*this->nNo = 0;
			this->szName = 0;*/
			//this();
			Student();
			//C는 this나 super이런 거로 못하고 그냥 이름 부른다
			//소멸이 또 일어나는 거는 생성자 갔다와서 그런거?? 왜그러지 근데 그 문장을 소멸로 생각하면 안됑
		}
	} //뭐가 딸려있냐 if는 처리 안 해줘도 돼

	~Student(){
		if (szName){
			cout << szName << " 소멸자" << endl;
			delete[] szName;
		}
		else{
			cout << "이름 없음 소멸" << endl;
		}
	}

	void PrintStudent(){
		if (szName != NULL)
			cout << "번호 : " << nNo << ", 이름 : " << szName << endl;
		else
			cout << "번호 : " << nNo << ", 이름 없음" << endl;
	}

	Student& Copy(Student& ori){
		if (this != &ori){ //객체가 같다는 것은 주소(모양, 내용이 아니야)가 같아야 해
			//this는 자체가 주소, ori는 내용이기 때문에 주소로
			this->nNo = ori.nNo;
			if (this->szName){
				delete[] this->szName; //[]? 없어도 돼?
			} //b=c했을 때 원래 있던 메모리가 떠버리고 다른 걸 연결한다, 메모리 누수 발생
			this->szName = new char[strlen(ori.szName) + 1]; //새 방을 잡아줘야지!
			strcpy(this->szName, ori.szName); //a=a하면 이미 다른 방을 가르키기 때문에 쓰레기에 쓰레기를 넣는 거
			//cout << "#############################################";
			//콜바이밸류 ori를 새로 생성한 거...걔는 a의 네임을 가리키고 copy가 끝나면서 ori는 죽고 a의 네임까지 죽여... 콜바이레퍼런스 &를 해야지......
		}
		return *this; //얘는 void로 해도 상관은 없어 copy안쓸거면
	}

	Student& operator=(Student& ori){ //연산자 만드는 것도 결국 함수를 만드는 것 (연산자 오버로딩)
		//매개변수에 &안하면 새로 생겨, 중간에 소멸을 해버린다
		//리턴값을 객체로 안해주면 a=b=c 할 때 문제이다
		//그리고 리턴값에 &를 해준 이유도 a=b=c 에서 오른쪽 b=c 결과가 또 매개변수로 들어가기 때문에
		cout << "할당연산자 호출" << endl;
		Copy(ori);

		return *this;  //ori보다는 주체가 되는 this
		//Studenet를 리턴해야하기 때문에 *this
	}
};

void a(){
	Student a(1, "강아지"); //정적으로 매개변수 있는 생성자 호출법
	a.PrintStudent();

	Student b; //정적으로 기본 생성자 호출법
	b.PrintStudent();

	//b = a; //멤버들이 기본 데이터면 이게 돼, 0110101110 이런걸 그대로 복사함
	//szName을 공유하게 됨 그런데 소멸할 때 b를 먼저 죽여서 그 공간이 사라지고 a죽일 때 프로그램이 죽는다
	//b.Copy(a); //얘써도 됑
	//b = a; //얘써도 됑
	b.operator=(a); //함수 이름이 operator=라고 생각해
	b.PrintStudent();
	strcpy(b.szName, "고양이");
	b.PrintStudent();
	a = a;
	a.PrintStudent();

	Student c;
	c = b = a; //할당연산자의 우선순위는 오른쪽부터 c=(b=a)랑 같아, void면 좌변 우변 타입이 안 맞아
	c.PrintStudent();

	b = c;
	b.PrintStudent();
	c.PrintStudent();
	
	cout << "------------------------------------------------" << endl;

	Student d = b; //할당연산자 호출이 안된다 (d객체가 아직 만들어지기 전이기 때문에 생성자를 만들어야한다!, 우선순위가 어떻게 돼?)
	//할당연산자를 안불렀지만 컴파일러가 가지고 있는 할당 비슷한 거(아마 1:1)를 불렀다
	//그래서 죽였다?? a하면 마지막에 런타임에러, b하면 마지막 하나 전에 런타임에러
	//Studend d(b); 같이 생성자 부르듯이 불러도 된다
	b.PrintStudent();
	d.PrintStudent();



	Student e = e;
	e.PrintStudent();

	cout << "a종료^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
} //정적으로 만든 객체는 지역변수이기 때문에 프로그램이 아니라 그 함수가 끝나면 죽는다

int main(){
	a();
	cout << "메인종료^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	return 0;
}