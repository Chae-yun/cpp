#include <iostream>
using namespace std;

class complex{

//public: //�ٱ��Լ� ������� ���
	int real, imaginary;

public:
	complex(){
		real = 0;
		imaginary = 0;
	}

	complex(int real, int imaginary){
		this->real = real;
		this->imaginary = imaginary;
	}

	void PrintComplex(){
		if (imaginary == 1)
			cout << real << "+i" << endl;
		else if (imaginary == -1)
			cout << real << "-i" << endl;
		else if (imaginary == 0)
			cout << real << endl;
		else if (real == 0)
			cout << imaginary << "i" << endl;
		else if (imaginary >= 0)
			cout << real << "+" << imaginary << "i" << endl;
		else if (imaginary < 0)
			cout << real << imaginary << "i" << endl;
	} //���밪���� �ϸ� �� ª���� �Ŵ�

	//complex operator+(complex &c){ //&�� �������� ������ �ϱ� ������ �̹� �Ҹ�� ���Ӥ��� �׷��� �̰� ��¥��
	//	int real, imaginary; //��������� �˸°� �ϱ� ���� ����������! �̰� �Ҵ��� �ƴ϶� ���ϱ��ݾ�
	//	real = this->real + c.real;
	//	imaginary = this->imaginary + c.imaginary;
	//	return complex(real, imaginary); //����� �� ��ü
	//}

	complex operator-(complex &c){
		int real, imaginary;
		real = this->real - c.real;
		imaginary = this->imaginary - c.imaginary;
		return complex(real, imaginary);
	}

	complex operator*(complex &c){
		int real, imaginary;
		real = (this->real * c.real) + (-1 * this->imaginary * c.imaginary);
		imaginary = (this->real * c.imaginary) + (this->imaginary * c.real);
		return complex(real, imaginary);
	}

	complex& operator++(){
		this->real++;
		cout << "a";
		return *this;
	} //++a ����

	complex operator++(int){
		int real; //���� �־���ϴϱ�
		real=this->real++;
		cout << "b";
		return complex(real, this->imaginary);
	} //a++ ����
	//��� ã�ư��� ����
	//�ϳ��� �����ϸ� ������ �װŰ� ������ ���ָ� ã�ư���

	complex& operator--(){
		this->real--;
		cout << "a";
		return *this;
	} //++a ����

	complex operator--(int){
		int real; //���� �־���ϴϱ�
		real = this->real--;
		cout << "b";
		return complex(real, this->imaginary);
	} //a++ ����

	//��¿�����(<<)�� ���߿� ���� ostream, istream ����ϴϱ� ���߿� �� �Ѵ�

	//�Ҵ翬���ڴ� �ΰ��� int�� �� ���� �Ǵϱ� ������ ���� int*�̸� �� ó��������

	friend complex operator+(complex &c, complex &c1);
	//�Ϲ��Լ����� private�� ���� ���
	//1. private�� public���� ��ģ��
	//2. getter setter�� �����
	//3. �Լ� �տ� friend�� ����� (friend �Լ�)

	//���� ���� ���� ������ friend�� ���� ���� �ʴ´�
	//friend�� �� �Լ��� ����� ���뿡���� private�� �� �� �ִ�
};

complex operator+(complex &c, complex &c1){ //&�� �������� ������ �ϱ� ������ �̹� �Ҹ�� ���Ӥ��� �׷��� �̰� ��¥��
	int real, imaginary; //��������� �˸°� �ϱ� ���� ����������! �̰� �Ҵ��� �ƴ϶� ���ϱ��ݾ�
	real = c.real + c1.real; //��������� ���������ڸ� public����
	imaginary = c.imaginary + c1.imaginary;
	return complex(real, imaginary); //����� �� ��ü
}
//++�� �غ���!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

int main(){
	complex a(3, 5);
	a.PrintComplex();

	complex b(4, -7);
	b.PrintComplex();

	complex c(-2, 6);
	c.PrintComplex();

	complex d(-3, -4);
	d.PrintComplex();

	complex e(4, 1);
	e.PrintComplex();

	complex f(-3, 0);
	f.PrintComplex();

	complex g(0, -3);
	g.PrintComplex();

	complex h(0, 0);
	h.PrintComplex();

	complex i;
	i.PrintComplex();

	complex j;
	j.PrintComplex();

	complex k;
	k.PrintComplex();

	complex l;
	l.PrintComplex();

	complex m;
	m.PrintComplex();

	cout << "===========" << endl;

	//a + b;
	i = a + b;
	cout << "( a + b )" << endl;
	a.PrintComplex();
	b.PrintComplex();
	i.PrintComplex();

	cout << endl << "( c - d )" << endl;
	i = c - d;
	c.PrintComplex();
	d.PrintComplex();
	i.PrintComplex();

	cout << endl << "( a * b )" << endl;
	j = a * b;
	a.PrintComplex();
	b.PrintComplex();
	j.PrintComplex();
	cout << "( c * d )" << endl;
	j = c * d;
	c.PrintComplex();
	d.PrintComplex();
	j.PrintComplex();

	cout << endl << "( a++ )" << endl;
	k = a++;
	a.PrintComplex();
	k.PrintComplex();

	cout << "( ++a )" << endl;
	l = ++a;
	a.PrintComplex();
	l.PrintComplex();

	cout << "===========" << endl;
	
	cout << "( c + d )" << endl;
	m = c + d;
	//����Լ��� ó�������� �Ϲ��Լ��� �Ű������� ������ ������ ó�� �����ϴ�
	//������ �Ѵ� ���� �ɷ� ���� ������ ����Լ��� �Ϲ��Լ�, 2�� ������ ���� �������� �𸥴� (�Ű����� Ÿ���� �ٸ��� ��������)
	//m = c.operator+(d);
	//m = operator+(c, d);
	c.PrintComplex();
	d.PrintComplex();
	m.PrintComplex();
	//�Ϲ��Լ��� ���� ������ ȿ�������� �ʴ´�

	return 0;
}