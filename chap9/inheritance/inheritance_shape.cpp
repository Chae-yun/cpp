#include<iostream>
using namespace std;

class Shape{
protected:
	int x, y, width, height;

public:
	Shape() : x(0), y(0), width(0), height(0){ //이렇게 하는 것도 초기화
		//앞이 멤버변수, 괄호 안이 값
		cout << "도형 기본 생성자" << endl;
		//x = 0;
		//y = 0;
		//width = 0;
		//height = 0;
	}

	Shape(int x, int y, int width, int height) : x(x), y(y), width(width), height(height){
		//얘는 this 안붙인다 앞은 무조건 멤버, 괄호는 값인줄 아니까. 붙이면 에러
		cout << "도형 매개변수 있는 생성자" << endl;
		//this->x = x;
		//this->y = y;
		//this->width = width;
		//this->height = height;
	}

	virtual ~Shape(){
		cout << "도형 소멸자" << endl;
	}

	virtual void Draw(){
		cout << "도형을 그립니다" << endl;
		cout << "시작좌표 : ( " << x << ", " << y << " ), 너비 : " << width << ", 높이 : " << height << endl;
	}
};

class Rectangle : public Shape{
	//int x, y, width, height;
	int k;

public:
	Rectangle(){
		cout << "사각형 기본 생성자" << endl;
		//x = 0;
		//y = 0;
		//width = 0;
		//height = 0;
		k = 10;
	}

	Rectangle(int x, int y, int width, int height) : Shape(x, y, width, height){ //super(,,,)와 같다. 건방지다 직접부른다
		cout << "사각형 매개변수 있는 생성자" << endl;
		//this->x = x;
		//this->y = y;
		//this->width = width;
		//this->height = height;
		k = 100;
	}

	~Rectangle(){
		cout << "사각형 소멸자" << endl;
	}

	void Draw(){
		cout << "사각형을 그립니다" << endl;
		cout << "시작좌표 : ( " << x << ", " << y << " ), 너비 : " << width << ", 높이 : " << height << endl;
		cout << k << endl;
	}
};

class Ellipse : public Shape{
	//int x, y, width, height;

public:
	Ellipse(){
		cout << "타원 기본 생성자" << endl;
		//x = 0;
		//y = 0;
		//width = 0;
		//height = 0;
	}

	Ellipse(int x, int y, int width, int height) : Shape(x, y, width, height){ //super(,,,)와 같다. 건방지다 직접부른다
		cout << "타원 매개변수 있는 생성자" << endl;
		//this->x = x;
		//this->y = y;
		//this->width = width;
		//this->height = height;
	}

	~Ellipse(){
		cout << "타원 소멸자" << endl;
	}

	void Draw(){
		cout << "타원을 그립니다" << endl;
		cout << "시작좌표 : ( " << x << ", " << y << " ), 너비 : " << width << ", 높이 : " << height << endl;
	}
};

class Triangle : public Shape{
	//int x, y, width, height;

public:
	Triangle(){
		cout << "삼각형 기본 생성자" << endl;
		//x = 0;
		//y = 0;
		//width = 0;
		//height = 0;
	}

	Triangle(int x, int y, int width, int height) : Shape(x, y, width, height){ //super(,,,)와 같다. 건방지다 직접부른다
		cout << "삼각형 매개변수 있는 생성자" << endl;
		//this->x = x;
		//this->y = y;
		//this->width = width;
		//this->height = height;
	}

	~Triangle(){
		cout << "삼각형 소멸자" << endl;
	}

	void Draw(){
		cout << "삼각형을 그립니다" << endl;
		cout << "시작좌표 : ( " << x << ", " << y << " ), 너비 : " << width << ", 높이 : " << height << endl;
	}
}; //:은 클래스에서는 상속, 아들 생성자에서는 super, 부모(아들도 뭐) 생성자에서는 초기화

int main(){
	/*Rectangle r1;
	r1.Draw();

	Rectangle r2(1, 2, 3, 4);
	r2.Draw();
	//사각형 생성과 소멸 시에 아버지한테 갔다가 온다
	//shape가 먼저 생성, 나중에 소멸
	//super()가 불린거다

	Ellipse e1;
	e1.Draw();

	Ellipse e2(5, 6, 7, 8);
	e2.Draw();

	Triangle t1;
	t1.Draw();

	Triangle t2(9, 10, 11, 12);
	t2.Draw();

	cout << sizeof(Shape) << endl << sizeof(Rectangle) << endl;
	//다 주석달고 private를 상속받는 것을 테스트 해보면 멤버 4개가 상속은 되어서 메모리가 잡히는 것을 볼 수 있음*/

	/*Rectangle* pRect = 0;
	pRect = new Rectangle(10, 10, 100, 100); //따라가면 객체
	pRect->Draw();
	((Shape*)pRect)->Draw(); //괄호 중요!! 이게 업캐스팅 부모걸로 올라갔으니까
	//이건 잠시 바꿔주는 것
	delete pRect;

	Shape *a = new Rectangle(); //만드는 건 Rectangle 이게 업캐스팅
	((Rectangle *)a)->Draw(); //사용하는 타입은 Shape
	//이게 다운캐스팅인데 안하면 쉐이프거밖에 못써
	delete ((Rectangle *)a); //사용하는 타입은 Shape
	//이게 다운캐스팅인데 안하면 쉐이프거만 지우고 사각형거는 안지움 -> 문제!
	//중요한 건 앞에 것!
	//얘는 많이 만들고 조금 쓰겠다
	//다운캐스팅은 업캐스팅 후에 가능

	//저거 쓰는 거 귀찮으면 Rectangle *r=(Rectangle *) a해도 된대

	//Rectangle *b = new Shape();
	//얘는 조금 만들고 많이 쓰겠다는 거니까 에러
	//업캐스팅도 안하고 다운캐스팅하겠다는 거니까 에러*/

	/*Shape *c = new Shape(); //Rectangle 생성자에 안가니까 int k 초기화를 안해줘
	((Rectangle *)c)->Draw();
	delete ((Rectangle *)c);
	//얘는 조금 만들고 더 큰거 쓰겠다는데 에러 안뜸
	//멤버들이 같으니까 이상은 없는데 논리적으로는 합당하지 않아
	//작은거 해놓고 큰거 쓰는건 컴파일 때이든 논리적으로든 이상해... 결국 업캐스팅 후에 다운캐스팅 하자!*/

	Shape* shapes[6];

	cout << "\n생성자를 호출합니다" << endl;

	shapes[0] = new Rectangle();
	shapes[1] = new Rectangle(10, 10, 100, 100);

	shapes[2] = new Ellipse();
	shapes[3] = new Ellipse(10, 10, 100, 100);

	shapes[4] = new Triangle();
	shapes[5] = new Triangle(10, 10, 100, 100);

	cout << "\n도형을 그립니다" << endl;

	for (int i = 0; i < 6; i++){
		//shape의 draw()호출
		shapes[i]->Draw(); //shape에 draw 없애면 멤버 없어서 에러 얘도 shape니까. 아들거 부르고 싶으면 virtual을 붙여라! 부모꺼 부르려면 안 붙이고 ㅇㅇ
	} //함수에 virtual 붙이니까 아들거로 해줌

	cout << "\n소멸자를 호출합니다" << endl;

	for (int i = 0; i < 6; i++){
		//shape의 소멸자호출
		delete shapes[i];
	} //소멸자에 virtual 붙이니까 자동으로 다 해줌

	//virtual을 함수에 붙이면 아들 거를 부르고 소멸자에 붙이면 아들거 해제하고 오라는 거
	//소멸자에는 모든 거에 다 붙여주자 상속할 일이 없다면 안붙여도 되지만 그래도!!!
	//함수는 아버지에 붙이면 그게 상속된다

	return 0;
}