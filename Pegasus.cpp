#include <iostream>
using namespace std;

class Horse{
private: 
	int a;
public:
	Horse(){cout<<"��(Horse)������"<<endl;}
	//virtual
	virtual~Horse(){cout<<"���Ҹ���"<<endl;}
	//virtual 
	virtual void Speak()=0;//�߻����� �������//{cout<<"���� ��ϴ�.������~"<<endl;}//�ؿ��� �� �����Ǹ� �������! �߻�޼���!
};
class Bird{
public:
	Bird(){cout<<"��������"<<endl;}
	virtual~Bird(){cout<<"���Ҹ���"<<endl;}
	virtual void Speak(){cout<<"���� ��ϴ�±±~"<<endl;}
	virtual void Fly(){cout<<"�ϴ��� �� �� �ֽ��ϴ�."<<endl;}
};
class Pegasus:public Horse{//���� �ٲ�� �����ڿ� �Ҹ��ڸ� ����� �� ������ �ٲ�
	int b;
	Bird bi;//������ ��������� ����
	Pegasus(){cout<<"�䰡����������"<<endl;}
	virtual~Pegasus(){cout<<"�䰡�����Ҹ���"<<endl;}
	virtual void Speak(){Horse::Speak();cout<<"�䰡������ ��ϴ�������~"<<endl;}
	virtual void Fly(){bi.Fly();}//������ Bird bi���� �ѱ�
	//Ŭ������ �θ��� ����� ����������
};
int main()
{
	cout<<sizeof(Horse)<<endl;//8���� virtual�� ����� 4����Ʈ �����(4����Ʈ ����) virtual�� ������
	cout<<sizeof(Pegasus)<<endl;//Bird virtual 4+Pegasus virtual 4+ Pegasus b 4+Horse 8 �ϸ� 20�ε� 16�� ���� ��?
	//Horse�� virtual�� Pegasus�� 4�� ���ε��ΰ� �ƴ� �ϳ��� �����ϸ� �� �׷��� ���� ���� 8�� �ƴ� 4��.
	//Horse a�� 4, Bird�� 4, Pegasus b�� 4, Horse�� Pegasus�� virtual�� 4 -> 16
	//Horse *a = new Pegasus();//��ĳ����! ������3������ ��->��->�䰡���� �������� ����� ���ؼ��� a����
	//a->Speak();//�䰡������ ��ϴ������� ������ ������ virtual�� �Ǿ��־ �Ƶ������� ������
	//virtual�� �����ϸ� ���� ��ϴٰ� ����
	delete a;//�䰡����->��->�� �����ڿ� �����ϰ� �Ųٷ� ����
	Pegasus *b = new Pegasus();
	b->Speak;
	b->Speak();//�䰡������ ��ϴ�
	//�䰡������ Speak�� �ּ��޾����� �׼����� ��ȣ�մϴ�.���� �� �ֳ��ϸ� Speak�� �־����� �ڱ�� ���������ٵ� �����ϱ� �θ����� �� �ٵ� �θ� �� ������ �� Speak�� ���� Bird�Ÿ� �������� Horse�Ÿ� �������� ����
	b->Fly();
	delete b;
}

