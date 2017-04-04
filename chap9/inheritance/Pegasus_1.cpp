#include<iostream>

using namespace std;

class Horse{
private:
	int a;
public:
	Horse(){
		cout << "말(Horse)생성자" << endl;
	}
	virtual ~Horse(){
		cout << "말(Horse)소멸자" << endl;
	}
	virtual void Speak() = 0;
};

class Bird{
public:
	Bird(){
		cout << "새(Bird)생성자" << endl;
	}
	virtual ~Bird(){
		cout << "새(Bird)소멸자" << endl;
	}
	virtual void Fly(){
		cout << "새(Bird)이 웁니다. 짹짹짹~" << endl;
	}
};

class Pegasus : public Horse{
	int b;
	Bird bi; //위임
public:
	Pegasus(){
		cout << "페가수스(Pegasus)생성자" << endl;
	}
	virtual ~Pegasus(){
		cout << "페가수스(Pegasus)소멸자" << endl;
	}

	void Speak(){
		Horse::Speak(); //아빠의 Speak을 불러옴
		cout << "페가수스(Pegasus)가 웁니다. 히히힝~" << endl;
	}

	void Fly(){
		bi.Fly();
	}
};

int main()
{
	/*
	//업캐스팅
	Horse *a = new Pegasus();
	a->Speak();
	delete a;
	*/
	cout << "------------------" << endl;

	Pegasus *b = new Pegasus();
	b->Speak();
	b->Fly();
	delete b;

	cout << "------------------" << endl;

	cout << sizeof(Horse) << endl;
	cout << sizeof(Pegasus) << endl;
}