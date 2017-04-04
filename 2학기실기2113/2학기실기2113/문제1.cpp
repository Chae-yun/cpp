#include <iostream>
#include <time.h>
#define PI 3.141592

using namespace std;

class Point{
	int x, y;

public:
	Point(int x, int y){
		this->x = x;
		this->y = y;
	}
	int GetX(){
		return x;
	}
	int GetY(){
		return y;
	}
};

class Circle{
	Point p;
	int r;

public:
	Circle(Point& p, int r) : p(p.GetX(), p.GetY()){
		this->r = r;
	}
	void Print(ostream &os){
		os << "���� ��ǥ<" << p.GetX() << ", " << p.GetY() << ">�� ������ " << r << "�� ���� ���� : " << (r*r*PI) << endl;
	}
	friend ostream& operator<<(ostream &os, Circle c){
		c.Print(os);

		return os;
	}
};

int main(){
	int x, y, r;

	srand((unsigned)time(NULL));
	x = rand() % 101;
	y = rand() % 101;
	r = (rand() % 10) + 1;

	Point p(x, y);
	Circle cir(p, r);
	//cir.Print();
	cout << cir;

	return 0;
}