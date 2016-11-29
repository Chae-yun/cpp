#include<iostream>
using namespace std;

class Number{

public:
	int n1, n2;

public:
	void setNumber(int n1, int n2){
		this->n1 = n1;
		this->n2 = n2;
	}

};

class Plus{

	int n;

public:
	Number num;

	void add(){
		n = num.n1 + num.n2;
	}

	void print(){
		cout << num.n1 << " + " << num.n2 << " = " << n << endl;
	}

};

int main(){
	Plus p;
	p.num.setNumber(4, 8);
	p.add();
	p.print();

	return 0;
}
//위임

//#include<iostream>
//using namespace std;
//
//class Number{
//
//protected:
//	int n1, n2;
//
//public:
//	void setNumber(int n1, int n2){
//		this->n1 = n1;
//		this->n2 = n2;
//	}
//
//};
//
//class Plus:public Number{
//
//	int n;
//
//public:
//	void add(){
//		n = n1 + n2;
//	}
//
//	void print(){
//		cout << n1 << " + " << n2 << " = " << n << endl;
//	}
//
//};
//
//int main(){
//	Plus p;
//	p.setNumber(4, 8);
//	p.add();
//	p.print();
//
//	return 0;
//}
//상속