#include <iostream>
using namespace std;
class Horse{
	int a;
public:
	Horse(){ cout << "��������" << endl; }
	virtual ~Horse(){ cout << "���Ҹ���" << endl; }
	virtual void Speak() = 0;
	//virtual void Speak(){ cout << "���� ��ϴ�." << endl; } //virtual�� ������ ���� ��ϴ� ����. �ƺ� Ÿ���̴ϱ� �ƺ��� ������ �翬�ѵ� virtual�� �Ƶ��� �θ�
	//���� �� ���� ������ {}�̷��� �ϴµ� �̰͵� �ǹ� ���� �ƹ��͵� �� ���� ���� �����ϱ� =0;���� ���� �̷��� �� �߸� ���ϵ��� ������ ����
};
class Bird{
public:
	Bird(){ cout << "��������" << endl; }
	~Bird(){ cout << "���Ҹ���" << endl; }
	virtual void Speak(){ cout << "���� ��ϴ�." << endl; }
	virtual void Fly(){ cout << "�ϴ��� �� �� �ֽ��ϴ�." << endl; }
};
class Pegasus : public Horse, public Bird{ //������ ���� �޶��� (�׽�Ʈ!) public Bird, 
public:
	//Bird bi; //����, ����� 2�� �޾Ҵ��� ���� �䰡������ ����ũ�� ���� �� �ƺ� �� �����ؾߵǴµ� �Ѵ� �����ϱ� ���� �߻�
	//���� ����� ����� ������ ���� �߻� ���ɼ��� �־ �ϳ��� ���, �������� �������� ���� �̷��� ����ũ�� �θ� �� Ȧ���� ����
	//����� is(���̴�) ������ has(������ �ִ�)
	Pegasus(){ cout << "�䰡 ���� ������" << endl; }
	~Pegasus(){ cout << "�䰡 ���� �Ҹ���" << endl; }
	//void Speak(){
	//	//Horse::Speak();   ���������ڷ� Horse�� speak�� �����ϵ��� �� �̷��� �ϸ� �Ѵ� ��
		//cout << "�䰡������ ��ϴ�." << endl;
	//} //�̰� �ּ� �޸� virtual�� �־ �ƺ��� ��. �̰� ���� �ȵ��(�ֳĸ� ���� �ǵ��� ���� �ƴ��ݾ�) ���� �������� �ؼ� ������ ���ָ� �ȴ� 
	void Fly(){
		Bird::Fly();
	}

};
class CC : public Pegasus{
public:
	CC(){ cout << "CC ������" << endl; }
	~CC(){ cout << "CC �Ҹ���" << endl; }
	void Speak(){
		cout << "Dd" << endl;
	}
};
int main(){
	cout << sizeof(Horse) << endl; //virtual�� �����Ͷ� �⺻������ 4byte����, 8byte, 4+4
	cout << sizeof(Pegasus) << endl; //virtual�� 2���� �ϳ��� ���=>4byte, 

	//Horse *a = new Pegasus();
	Pegasus *p = new CC();
	((CC *)p)->Speak(); //������ ���� ��ϴ� �ε� virtual�̶� �Ƶ�� ������
	delete p;
}
