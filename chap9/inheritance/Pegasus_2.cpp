#include <iostream>
using namespace std;
class Horse{
	int a;
public:
	Horse(){ cout << "말생성자" << endl; }
	virtual ~Horse(){ cout << "말소멸자" << endl; }
	virtual void Speak() = 0;
	//virtual void Speak(){ cout << "말이 웁니다." << endl; } //virtual이 없으면 말이 웁니다 나옴. 아빠 타입이니까 아빠거 실행이 당연한데 virtual이 아들을 부름
	//딱히 할 일이 없으면 {}이렇게 하는데 이것도 의미 없고 아무것도 안 나올 수도 있으니까 =0;으로 하자 이러면 나 잘못 안하도록 에러도 내줌
};
class Bird{
public:
	Bird(){ cout << "새생성자" << endl; }
	~Bird(){ cout << "새소멸자" << endl; }
	virtual void Speak(){ cout << "새가 웁니다." << endl; }
	virtual void Fly(){ cout << "하늘을 날 수 있습니다." << endl; }
};
class Pegasus : public Horse, public Bird{ //순서에 따라 달라짐 (테스트!) public Bird, 
public:
	//Bird bi; //위임, 상속을 2개 받았더니 만약 페가수스의 스피크가 없을 때 아빠 걸 실행해야되는데 둘다 있으니까 에러 발생
	//다중 상속은 허용은 하지만 문제 발생 가능성이 있어서 하나만 상속, 나머지는 위임으로 받자 이러면 스피크를 부를 때 홀스로 가지
	//상속은 is(말이다) 위임은 has(날개가 있다)
	Pegasus(){ cout << "페가 수스 생성자" << endl; }
	~Pegasus(){ cout << "페가 수스 소멸자" << endl; }
	//void Speak(){
	//	//Horse::Speak();   영역연산자로 Horse의 speak을 수행하도록 함 이렇게 하면 둘다 떠
		//cout << "페가수스가 웁니다." << endl;
	//} //이거 주석 달면 virtual이 있어도 아빠거 함. 이게 맘에 안들면(왜냐면 내가 의도한 것이 아니잖아) 순수 가상으로 해서 에러를 내주면 된다 
	void Fly(){
		Bird::Fly();
	}

};
class CC : public Pegasus{
public:
	CC(){ cout << "CC 생성자" << endl; }
	~CC(){ cout << "CC 소멸자" << endl; }
	void Speak(){
		cout << "Dd" << endl;
	}
};
int main(){
	cout << sizeof(Horse) << endl; //virtual이 포인터라서 기본적으로 4byte가짐, 8byte, 4+4
	cout << sizeof(Pegasus) << endl; //virtual은 2개라도 하나만 담김=>4byte, 

	//Horse *a = new Pegasus();
	Pegasus *p = new CC();
	((CC *)p)->Speak(); //원래는 말이 웁니다 인데 virtual이라서 아들로 내려옴
	delete p;
}
