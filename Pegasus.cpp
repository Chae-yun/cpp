#include <iostream>
using namespace std;

class Horse{
private: 
	int a;
public:
	Horse(){cout<<"말(Horse)생성자"<<endl;}
	//virtual
	virtual~Horse(){cout<<"말소멸자"<<endl;}
	//virtual 
	virtual void Speak()=0;//추상으로 만들어줌//{cout<<"말이 웁니다.히히힝~"<<endl;}//밑에서 꼭 재정의를 해줘야해! 추상메서드!
};
class Bird{
public:
	Bird(){cout<<"새생성자"<<endl;}
	virtual~Bird(){cout<<"새소멸자"<<endl;}
	virtual void Speak(){cout<<"새가 웁니다짹짹~"<<endl;}
	virtual void Fly(){cout<<"하늘을 날 수 있습니다."<<endl;}
};
class Pegasus:public Horse{//순서 바뀌면 생성자와 소멸자를 출력할 때 순서가 바뀜
	int b;
	Bird bi;//위임은 멤버변수로 넣음
	Pegasus(){cout<<"페가수스생성자"<<endl;}
	virtual~Pegasus(){cout<<"페가수스소멸자"<<endl;}
	virtual void Speak(){Horse::Speak();cout<<"페가수스가 웁니다히히힝~"<<endl;}
	virtual void Fly(){bi.Fly();}//할일은 Bird bi에게 넘김
	//클래스를 부르는 방법은 영역연산자
};
int main()
{
	cout<<sizeof(Horse)<<endl;//8나옴 virtual을 지우면 4바이트 사라짐(4바이트 나옴) virtual이 포인터
	cout<<sizeof(Pegasus)<<endl;//Bird virtual 4+Pegasus virtual 4+ Pegasus b 4+Horse 8 하면 20인데 16이 나옴 왜?
	//Horse의 virtual과 Pegasus의 4가 따로따로가 아닌 하나라 생각하면 됨 그래서 둘이 더한 8이 아닌 4임.
	//Horse a가 4, Bird가 4, Pegasus b가 4, Horse와 Pegasus의 virtual이 4 -> 16
	//Horse *a = new Pegasus();//업캐스팅! 생성자3개나옴 말->새->페가수스 다형성을 만들기 위해서는 a형태
	//a->Speak();//페가수스가 웁니다히히힝 말한테 갔더니 virtual이 되어있어서 아들쪽으로 내려옴
	//virtual을 제거하면 말이 웁니다가 나옴
	delete a;//페가수스->새->말 생성자와 완전하게 거꾸로 나옴
	Pegasus *b = new Pegasus();
	b->Speak;
	b->Speak();//페가수스가 웁니다
	//페가수스의 Speak을 주석달았을때 액세스가 모호합니다.에러 뜸 왜냐하면 Speak이 있었으면 자기걸 실행했을텐데 없으니까 부모한테 감 근데 부모 둘 다한테 다 Speak이 있음 Bird거를 수행할지 Horse거를 수행할지 몰라서
	b->Fly();
	delete b;
}

