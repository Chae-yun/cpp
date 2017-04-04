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
	void Print(){
		cout << "점의 좌표<" << p.GetX() << ", " << p.GetY() << ">와 반지름 " << r << "인 원의 넓이 : " << (r*r*PI) << endl;
	}
};

int main(){
	int x, y, r, i;
	Point* points[5];
	Circle* circles[5];

	srand((unsigned)time(NULL));

	for (i = 0; i < 5; i++){
		x = rand() % 101;
		y = rand() % 101;
		r = (rand() % 10) + 1;

		points[i] = new Point(x, y);
		circles[i] = new Circle(*points[i], r);
	}

	for (i = 0; i < 5; i++){
		circles[i]->Print();
	}

	return 0;
}