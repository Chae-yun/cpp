#include<iostream>

using namespace std;

class Horse{
private:
	int a;
public:
	Horse(){
		cout << "��(Horse)������" << endl;
	}
	virtual ~Horse(){
		cout << "��(Horse)�Ҹ���" << endl;
	}
	virtual void Speak() = 0;
};

class Bird{
public:
	Bird(){
		cout << "��(Bird)������" << endl;
	}
	virtual ~Bird(){
		cout << "��(Bird)�Ҹ���" << endl;
	}
	virtual void Fly(){
		cout << "��(Bird)�� ��ϴ�. ±±±~" << endl;
	}
};

class Pegasus : public Horse{
	int b;
	Bird bi; //����
public:
	Pegasus(){
		cout << "�䰡����(Pegasus)������" << endl;
	}
	virtual ~Pegasus(){
		cout << "�䰡����(Pegasus)�Ҹ���" << endl;
	}

	void Speak(){
		Horse::Speak(); //�ƺ��� Speak�� �ҷ���
		cout << "�䰡����(Pegasus)�� ��ϴ�. ������~" << endl;
	}

	void Fly(){
		bi.Fly();
	}
};

int main()
{
	/*
	//��ĳ����
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