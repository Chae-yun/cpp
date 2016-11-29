#include <iostream>
using namespace std;

class complex{

//public: //바깥함수 만들려고 편법
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
	} //절대값으로 하면 더 짧아질 거다

	//complex operator+(complex &c){ //&면 별명으로 리턴을 하기 때문에 이미 소멸된 거임ㅇㅇ 그래서 이건 진짜로
	//	int real, imaginary; //산수적으로 알맞게 하기 위해 지역변수로! 이건 할당이 아니라 더하기잖아
	//	real = this->real + c.real;
	//	imaginary = this->imaginary + c.imaginary;
	//	return complex(real, imaginary); //결과로 새 객체
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
	} //++a 전위

	complex operator++(int){
		int real; //먼저 넣어야하니까
		real=this->real++;
		cout << "b";
		return complex(real, this->imaginary);
	} //a++ 후위
	//어떻게 찾아가는 거지
	//하나만 선언하면 무조건 그거고 구분을 해주면 찾아간다

	complex& operator--(){
		this->real--;
		cout << "a";
		return *this;
	} //++a 전위

	complex operator--(int){
		int real; //먼저 넣어야하니까
		real = this->real--;
		cout << "b";
		return complex(real, this->imaginary);
	} //a++ 후위

	//출력연산자(<<)는 나중에 배우는 ostream, istream 써야하니까 나중에 또 한다

	//할당연산자는 두개의 int가 잘 복사 되니까 괜찮다 만약 int*이면 다 처리해줬어야

	friend complex operator+(complex &c, complex &c1);
	//일반함수에서 private를 쓰는 방법
	//1. private를 public으로 고친다
	//2. getter setter를 만든다
	//3. 함수 앞에 friend를 만든다 (friend 함수)

	//물론 보안 상의 이유로 friend를 많이 쓰지 않는다
	//friend를 쓴 함수의 헤더의 몸통에서는 private도 쓸 수 있다
};

complex operator+(complex &c, complex &c1){ //&면 별명으로 리턴을 하기 때문에 이미 소멸된 거임ㅇㅇ 그래서 이건 진짜로
	int real, imaginary; //산수적으로 알맞게 하기 위해 지역변수로! 이건 할당이 아니라 더하기잖아
	real = c.real + c1.real; //멤버변수의 접근제어자를 public으로
	imaginary = c.imaginary + c1.imaginary;
	return complex(real, imaginary); //결과로 새 객체
}
//++도 해보자!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

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
	//멤버함수도 처리하지만 일반함수도 매개변수의 개수만 맞으면 처리 가능하다
	//하지만 둘다 같은 걸로 보기 때문에 멤버함수와 일반함수, 2개 있으면 어디로 가야할지 모른다 (매개변수 타입이 다르면 괜찮지만)
	//m = c.operator+(d);
	//m = operator+(c, d);
	c.PrintComplex();
	d.PrintComplex();
	m.PrintComplex();
	//일반함수도 문제 없으나 효율적이지 않는다

	return 0;
}