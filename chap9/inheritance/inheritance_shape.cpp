#include<iostream>
using namespace std;

class Shape{
protected:
	int x, y, width, height;

public:
	Shape() : x(0), y(0), width(0), height(0){ //�̷��� �ϴ� �͵� �ʱ�ȭ
		//���� �������, ��ȣ ���� ��
		cout << "���� �⺻ ������" << endl;
		//x = 0;
		//y = 0;
		//width = 0;
		//height = 0;
	}

	Shape(int x, int y, int width, int height) : x(x), y(y), width(width), height(height){
		//��� this �Ⱥ��δ� ���� ������ ���, ��ȣ�� ������ �ƴϱ�. ���̸� ����
		cout << "���� �Ű����� �ִ� ������" << endl;
		//this->x = x;
		//this->y = y;
		//this->width = width;
		//this->height = height;
	}

	virtual ~Shape(){
		cout << "���� �Ҹ���" << endl;
	}

	virtual void Draw(){
		cout << "������ �׸��ϴ�" << endl;
		cout << "������ǥ : ( " << x << ", " << y << " ), �ʺ� : " << width << ", ���� : " << height << endl;
	}
};

class Rectangle : public Shape{
	//int x, y, width, height;
	int k;

public:
	Rectangle(){
		cout << "�簢�� �⺻ ������" << endl;
		//x = 0;
		//y = 0;
		//width = 0;
		//height = 0;
		k = 10;
	}

	Rectangle(int x, int y, int width, int height) : Shape(x, y, width, height){ //super(,,,)�� ����. �ǹ����� �����θ���
		cout << "�簢�� �Ű����� �ִ� ������" << endl;
		//this->x = x;
		//this->y = y;
		//this->width = width;
		//this->height = height;
		k = 100;
	}

	~Rectangle(){
		cout << "�簢�� �Ҹ���" << endl;
	}

	void Draw(){
		cout << "�簢���� �׸��ϴ�" << endl;
		cout << "������ǥ : ( " << x << ", " << y << " ), �ʺ� : " << width << ", ���� : " << height << endl;
		cout << k << endl;
	}
};

class Ellipse : public Shape{
	//int x, y, width, height;

public:
	Ellipse(){
		cout << "Ÿ�� �⺻ ������" << endl;
		//x = 0;
		//y = 0;
		//width = 0;
		//height = 0;
	}

	Ellipse(int x, int y, int width, int height) : Shape(x, y, width, height){ //super(,,,)�� ����. �ǹ����� �����θ���
		cout << "Ÿ�� �Ű����� �ִ� ������" << endl;
		//this->x = x;
		//this->y = y;
		//this->width = width;
		//this->height = height;
	}

	~Ellipse(){
		cout << "Ÿ�� �Ҹ���" << endl;
	}

	void Draw(){
		cout << "Ÿ���� �׸��ϴ�" << endl;
		cout << "������ǥ : ( " << x << ", " << y << " ), �ʺ� : " << width << ", ���� : " << height << endl;
	}
};

class Triangle : public Shape{
	//int x, y, width, height;

public:
	Triangle(){
		cout << "�ﰢ�� �⺻ ������" << endl;
		//x = 0;
		//y = 0;
		//width = 0;
		//height = 0;
	}

	Triangle(int x, int y, int width, int height) : Shape(x, y, width, height){ //super(,,,)�� ����. �ǹ����� �����θ���
		cout << "�ﰢ�� �Ű����� �ִ� ������" << endl;
		//this->x = x;
		//this->y = y;
		//this->width = width;
		//this->height = height;
	}

	~Triangle(){
		cout << "�ﰢ�� �Ҹ���" << endl;
	}

	void Draw(){
		cout << "�ﰢ���� �׸��ϴ�" << endl;
		cout << "������ǥ : ( " << x << ", " << y << " ), �ʺ� : " << width << ", ���� : " << height << endl;
	}
}; //:�� Ŭ���������� ���, �Ƶ� �����ڿ����� super, �θ�(�Ƶ鵵 ��) �����ڿ����� �ʱ�ȭ

int main(){
	/*Rectangle r1;
	r1.Draw();

	Rectangle r2(1, 2, 3, 4);
	r2.Draw();
	//�簢�� ������ �Ҹ� �ÿ� �ƹ������� ���ٰ� �´�
	//shape�� ���� ����, ���߿� �Ҹ�
	//super()�� �Ҹ��Ŵ�

	Ellipse e1;
	e1.Draw();

	Ellipse e2(5, 6, 7, 8);
	e2.Draw();

	Triangle t1;
	t1.Draw();

	Triangle t2(9, 10, 11, 12);
	t2.Draw();

	cout << sizeof(Shape) << endl << sizeof(Rectangle) << endl;
	//�� �ּ��ް� private�� ��ӹ޴� ���� �׽�Ʈ �غ��� ��� 4���� ����� �Ǿ �޸𸮰� ������ ���� �� �� ����*/

	/*Rectangle* pRect = 0;
	pRect = new Rectangle(10, 10, 100, 100); //���󰡸� ��ü
	pRect->Draw();
	((Shape*)pRect)->Draw(); //��ȣ �߿�!! �̰� ��ĳ���� �θ�ɷ� �ö����ϱ�
	//�̰� ��� �ٲ��ִ� ��
	delete pRect;

	Shape *a = new Rectangle(); //����� �� Rectangle �̰� ��ĳ����
	((Rectangle *)a)->Draw(); //����ϴ� Ÿ���� Shape
	//�̰� �ٿ�ĳ�����ε� ���ϸ� �������Źۿ� ����
	delete ((Rectangle *)a); //����ϴ� Ÿ���� Shape
	//�̰� �ٿ�ĳ�����ε� ���ϸ� �������Ÿ� ����� �簢���Ŵ� ������ -> ����!
	//�߿��� �� �տ� ��!
	//��� ���� ����� ���� ���ڴ�
	//�ٿ�ĳ������ ��ĳ���� �Ŀ� ����

	//���� ���� �� �������� Rectangle *r=(Rectangle *) a�ص� �ȴ�

	//Rectangle *b = new Shape();
	//��� ���� ����� ���� ���ڴٴ� �Ŵϱ� ����
	//��ĳ���õ� ���ϰ� �ٿ�ĳ�����ϰڴٴ� �Ŵϱ� ����*/

	/*Shape *c = new Shape(); //Rectangle �����ڿ� �Ȱ��ϱ� int k �ʱ�ȭ�� ������
	((Rectangle *)c)->Draw();
	delete ((Rectangle *)c);
	//��� ���� ����� �� ū�� ���ڴٴµ� ���� �ȶ�
	//������� �����ϱ� �̻��� ���µ� �������δ� �մ����� �ʾ�
	//������ �س��� ū�� ���°� ������ ���̵� �������ε� �̻���... �ᱹ ��ĳ���� �Ŀ� �ٿ�ĳ���� ����!*/

	Shape* shapes[6];

	cout << "\n�����ڸ� ȣ���մϴ�" << endl;

	shapes[0] = new Rectangle();
	shapes[1] = new Rectangle(10, 10, 100, 100);

	shapes[2] = new Ellipse();
	shapes[3] = new Ellipse(10, 10, 100, 100);

	shapes[4] = new Triangle();
	shapes[5] = new Triangle(10, 10, 100, 100);

	cout << "\n������ �׸��ϴ�" << endl;

	for (int i = 0; i < 6; i++){
		//shape�� draw()ȣ��
		shapes[i]->Draw(); //shape�� draw ���ָ� ��� ��� ���� �굵 shape�ϱ�. �Ƶ�� �θ��� ������ virtual�� �ٿ���! �θ� �θ����� �� ���̰� ����
	} //�Լ��� virtual ���̴ϱ� �Ƶ�ŷ� ����

	cout << "\n�Ҹ��ڸ� ȣ���մϴ�" << endl;

	for (int i = 0; i < 6; i++){
		//shape�� �Ҹ���ȣ��
		delete shapes[i];
	} //�Ҹ��ڿ� virtual ���̴ϱ� �ڵ����� �� ����

	//virtual�� �Լ��� ���̸� �Ƶ� �Ÿ� �θ��� �Ҹ��ڿ� ���̸� �Ƶ�� �����ϰ� ����� ��
	//�Ҹ��ڿ��� ��� �ſ� �� �ٿ����� ����� ���� ���ٸ� �Ⱥٿ��� ������ �׷���!!!
	//�Լ��� �ƹ����� ���̸� �װ� ��ӵȴ�

	return 0;
}